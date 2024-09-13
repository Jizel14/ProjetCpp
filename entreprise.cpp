#include "entreprise.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include<QSqlQueryModel>
#include<QObject>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QFile>
#include <QTextDocument>

#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QPieSeries>
#include <utility> // pour std::move




Entreprise::Entreprise() {
    entreprise_id=0; nom_entreprise="";adresse="";telephone="";email="";secteur="";
}

Entreprise::Entreprise(int entreprise_id,QString nom_entreprise,QString adresse,QString telephone, QString email, QString secteur)
{
    this -> entreprise_id=entreprise_id; this -> nom_entreprise=nom_entreprise; this -> telephone=telephone;
    this ->email=email; this ->adresse=adresse; this ->secteur=secteur;
}

int Entreprise::getentreprise_id(){return entreprise_id;}
QString Entreprise::getnom_entreprise(){return nom_entreprise;}
QString Entreprise::getadresse(){return adresse;}
QString Entreprise::gettelephone(){return telephone;}
QString Entreprise::getemail(){return email;}
QString Entreprise::getsecteur(){return secteur;}

void Entreprise::setentreprise_id(int entreprise_id){this ->entreprise_id=entreprise_id;}
void Entreprise::setnom_entreprise(QString nom_entreprise){this ->nom_entreprise=nom_entreprise;}
void Entreprise::setadresse(QString adresse){this ->adresse=adresse;}
void Entreprise::settelephone(QString telephone){this ->telephone=telephone;}
void Entreprise::setemail(QString email){this ->email=email;}
void Entreprise::setsecteur(QString secteur){this ->secteur=secteur;}


bool Entreprise::ajouter(){
    //bool test=false;
    QString id_string=QString::number(entreprise_id);
    QSqlQuery query;

    query.prepare("INSERT INTO entreprise (entreprise_id, nom_entreprise, adresse,telephone,email,secteur) "
                  "VALUES (:entreprise_id, :nom_entreprise, :adresse, :telephone, :email, :secteur)");
    query.bindValue(":entreprise_id", id_string);
    query.bindValue(":nom_entreprise", nom_entreprise);
    query.bindValue(":adresse", adresse);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":secteur", secteur);

    return query.exec();

    // return test;
}



QSqlQueryModel* Entreprise::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM entreprise");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("entreprise_id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_entreprise"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("secteur"));

    return model;

}

bool Entreprise::archiver(int entreprise_id) {
    QSqlQuery query;

    // Archiver les données
    query.prepare("INSERT INTO entreprise_archive (entreprise_id, nom_entreprise, adresse, telephone, email, secteur, date_archivage) "
                  "SELECT entreprise_id, nom_entreprise, adresse, telephone, email, secteur, CURRENT_DATE "
                  "FROM entreprise WHERE entreprise_id = :entreprise_id");
    query.bindValue(":entreprise_id", entreprise_id);

    if (!query.exec()) {
        qDebug() << "Error archiving enterprise:" << query.lastError().text();
        return false;
    }

    // Supprimer les données de la table entreprise
    query.prepare("DELETE FROM entreprise WHERE entreprise_id = :entreprise_id");
    query.bindValue(":entreprise_id", entreprise_id);

    if (!query.exec()) {
        qDebug() << "Error deleting enterprise:" << query.lastError().text();
        return false;
    }

    return true;
}
QSqlQueryModel* Entreprise::afficherArchives() const {
    QSqlQuery query;
    query.prepare("SELECT * FROM entreprise_archive");

    if (!query.exec()) {
        qDebug() << "Error fetching archives:" << query.lastError().text();
        return nullptr; // Renvoie nullptr en cas d'erreur
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(std::move(query)); // Utilisation directe de query
    return model;
}
// MODIFICATION

bool Entreprise::modifierEntreprise(int id, int newId, const QString &nom, const QString &adresse, const QString &telephone, const QString &email,const QString &secteur) {
    QSqlQuery query;

    // Vérifier si l'entreprise avec l'ID donné existe
    query.prepare("SELECT COUNT(*) FROM Entreprise WHERE entreprise_id = :id");
    query.bindValue(":id", id);
    query.exec();
    query.next();

    if (query.value(0).toInt() == 0) {
        return false; // L'entreprise n'existe pas
    }

    // Préparer la requête de mise à jour
    query.prepare("UPDATE Entreprise SET entreprise_id = :newId, nom_entreprise = :nom, adresse = :adresse, telephone = :telephone, email = :email, secteur= :secteur WHERE entreprise_id = :id");
    query.bindValue(":newId", newId);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":id", id);
    query.bindValue(":secteur", secteur);

    return query.exec();
}

// ------------ stat
QPieSeries* Entreprise::obtenirStatistiquesParSecteur() {
    QPieSeries *series = new QPieSeries();

    QSqlQuery query;
    query.prepare("SELECT secteur, COUNT(*) FROM Entreprise GROUP BY secteur");
    if (!query.exec()) {
        // Vous pouvez gérer les erreurs ici ou les remonter à l'appelant
        return nullptr;
    }

    while (query.next()) {
        QString secteur = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(secteur, count);
    }

    for (auto slice : series->slices()) {
        slice->setLabel(QString("%1: %2").arg(slice->label()).arg(slice->value()));
    }

    return series;
}
// ----------- sort
QSqlQueryModel* Entreprise::trier(const QString& critere, bool ascendant) {
    QSqlQuery query;
    QString queryString = "SELECT * FROM entreprise";

    if (!critere.isEmpty()) {
        queryString += " ORDER BY " + critere;
        if (!ascendant) {
            queryString += " DESC";
        }
    }

    query.prepare(queryString);
    query.exec();

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(std::move(query));

    return model;
}
// ----------- rechercher
QSqlQueryModel* Entreprise::rechercher(const QString& valeur) {
    QSqlQuery query;
    QString queryString;

    if (valeur.toInt() > 0) {
        // Recherche par ID (si la valeur est un entier positif)
        queryString = "SELECT * FROM entreprise WHERE entreprise_id = :valeur";
    } else {
        // Recherche par nom ou secteur
        queryString = "SELECT * FROM entreprise "
                      "WHERE nom_entreprise LIKE :valeurLike "
                      "OR secteur LIKE :valeurLike";
    }

    query.prepare(queryString);

    if (valeur.toInt() > 0) {
        query.bindValue(":valeur", valeur);
    } else {
        query.bindValue(":valeurLike", "%" + valeur + "%");
    }

    qDebug() << "Executing query:" << queryString;
    qDebug() << "Binding values - " << (valeur.toInt() > 0 ? "exact:" : "LIKE pattern:") << valeur;

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(std::move(query));

    return model;
}
// --------------- PDF
bool Entreprise::genererPDFArchives(const QString &filePath) {
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);

    QPainter painter(&writer);
    if (!painter.isActive()) {
        qDebug() << "Failed to initialize painter.";
        return false;
    }

    // Define table parameters
    const int headerHeight = 60;
    const int rowHeight = 60;
    const int columnWidth = writer.width() / 6;
    const int tableTop = 100;
    const int tableLeft = 40;
    const QStringList headers = {"ID", "Nom", "Adresse", "Téléphone", "Email", "Secteur"};

    // Draw table headers with a thicker border
    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawRect(tableLeft + i * columnWidth, tableTop, columnWidth, headerHeight);
        painter.drawText(tableLeft + i * columnWidth + 10, tableTop + 35, headers[i]);
    }

    // Draw table rows with standard border
    pen.setWidth(1);
    painter.setPen(pen);
    painter.setFont(QFont("Arial", 10));
    int y = tableTop + headerHeight;
    QSqlQuery query;
    query.prepare("SELECT * FROM entreprise_archive");

    if (!query.exec()) {
        qDebug() << "Error fetching archives for PDF:" << query.lastError().text();
        return false;
    }

    while (query.next()) {
        for (int i = 0; i < headers.size(); ++i) {
            painter.drawRect(tableLeft + i * columnWidth, y, columnWidth, rowHeight);
            painter.drawText(tableLeft + i * columnWidth + 10, y + 25, query.value(i).toString());
        }
        y += rowHeight;
    }

    painter.end();
    return true;
}
 // ------------ email

bool Entreprise::envoyerEmail(QString entreprise_id, QString sujet, QString message) {
    QSqlQuery query;
    query.prepare("SELECT email FROM entreprise WHERE entreprise_id = :entreprise_id");
    query.bindValue(":entreprise_id", entreprise_id);

    if (query.exec()) {
        if (query.next()) {
            QString email = query.value(0).toString();
            QString mailtoLink = QString("mailto:%1?subject=%2&body=%3")
                                     .arg(email)
                                     .arg(QUrl::toPercentEncoding(sujet))
                                     .arg(QUrl::toPercentEncoding(message));

            if (QDesktopServices::openUrl(QUrl(mailtoLink))) {
                return true;
            } else {
                QMessageBox::warning(nullptr, "Erreur", "Impossible d'ouvrir le client de messagerie.");
                return false;
            }
        } else {
            QMessageBox::warning(nullptr, "Erreur", "Entreprise introuvable.");
            return false;
        }
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Erreur lors de l'exécution de la requête.");
        return false;
    }
}
