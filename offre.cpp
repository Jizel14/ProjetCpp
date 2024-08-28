#include "offre.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include<QSqlQueryModel>
#include<QObject>
#include <QDate>


Offre::Offre() {
    offre_id = 0;
    titre = "";
    description = "";
    date_publication = QDate::currentDate();  // Set to the current date
    date_limite = QDate::currentDate();
    entreprise_id = 0;
}

Offre::Offre(int offre_id, QString titre, QString description, QDate date_publication, QDate date_limit, int entreprise_id) {
    this->offre_id = offre_id;
    this->titre = titre;
    this->description = description;
    this->date_publication = date_publication;
    this->date_limite = date_limit;
    this->entreprise_id = entreprise_id;
}

// Getter
int Offre::getOffreId() const {return offre_id;}
int Offre::getEntrepriseId() const {return entreprise_id;}
QString Offre::getTitre() const {return titre;}
QString Offre::getDescription() const {return description;}
QDate Offre::getDatePublication() const {return date_publication;}
QDate Offre::getDateLimit() const {return date_limite;}
// Setter
void Offre::setOffreId(int value) {offre_id = value;}
void Offre::setTitre(const QString &value) {titre = value;}
void Offre::setDescription(const QString &value) {description = value;}
void Offre::setDatePublication(const QDate &value) { date_publication = value;}
void Offre::setDateLimit(const QDate &value) {date_limite = value;}
void Offre::setEntrepriseId(int value) {entreprise_id = value;}

// ----------------------------------------------------------------


// ----------------- AJOUTER ---------------------------------
bool Offre::ajouter() {
    QSqlQuery query;

    // Vérifier si l'entreprise existe
    query.prepare("SELECT COUNT(*) FROM entreprise WHERE entreprise_id = :entreprise_id");
    query.bindValue(":entreprise_id", entreprise_id); // Lier directement l'entier

    if (query.exec()) {
        query.next();
        if (query.value(0).toInt() == 0) {
            // L'entreprise n'existe pas
            qDebug() << "L'entreprise avec l'ID" << entreprise_id << "n'existe pas.";
            return false;
        }
    } else {
        qDebug() << "Erreur lors de la vérification de l'entreprise:" << query.lastError().text();
        return false; // Échec de l'exécution de la requête
    }

    // Si date_publication est null, utiliser la date actuelle
    if (date_publication.isNull()) {
        date_publication = QDate::currentDate();
    }

    // Préparer l'insertion de l'offre d'emploi
    query.prepare("INSERT INTO offre_emploi (offre_id, titre, description, date_publication, date_limite, entreprise_id) "
                  "VALUES (:offre_id, :titre, :description, :date_publication, :date_limite, :entreprise_id)");

    query.bindValue(":offre_id", offre_id); // Lier directement l'entier
    query.bindValue(":titre", titre);
    query.bindValue(":description", description);
    query.bindValue(":date_publication", date_publication);
    query.bindValue(":date_limite", date_limite); // Assurez-vous que ce nom correspond à la colonne dans la DB
    query.bindValue(":entreprise_id", entreprise_id); // Lier directement l'entier

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de l'insertion de l'offre:" << query.lastError().text();
        return false;
    }
}

//---------------- AFFICHER  -------------

QSqlQueryModel* Offre::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM offre_emploi");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("offre_id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_publication"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_limite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_entreprise"));

    return model;

}

//---------------- SUPPRIMER ---------


bool Offre::supprimer(int offre_id)
{
    QSqlQuery query;

    query.prepare("Delete from offre_emploi where offre_id=:offre_id");
    query.bindValue(":offre_id", offre_id);
    return query.exec();
}

// ------------- MODIFIER -----------------------
bool Offre::modifier(int offre_id) {
    QSqlQuery query;

    // Vérifier si l'offre existe
    query.prepare("SELECT COUNT(*) FROM offre_emploi WHERE offre_id = :offre_id");
    query.bindValue(":offre_id", offre_id);

    if (query.exec()) {
        query.next();
        if (query.value(0).toInt() == 0) {
            // L'offre n'existe pas
            qDebug() << "L'offre avec l'ID" << offre_id << "n'existe pas.";
            return false;
        }
    } else {
        qDebug() << "Erreur lors de la vérification de l'offre:" << query.lastError().text();
        return false; // Échec de l'exécution de la requête
    }

    // Préparer la mise à jour de l'offre d'emploi
    query.prepare("UPDATE offre_emploi SET offre_id = :nouveau_offre_id, titre = :titre, description = :description, date_publication = :date_publication, date_limite = :date_limite, entreprise_id = :entreprise_id WHERE offre_id = :offre_id");


    // Lier les valeurs
    query.bindValue(":nouveau_offre_id", offre_id); // Valeur de l'ID à mettre à jour
    query.bindValue(":titre", titre);
    query.bindValue(":description", description);
    query.bindValue(":date_publication", date_publication);
    query.bindValue(":date_limite", date_limite);
    query.bindValue(":entreprise_id", entreprise_id);
    query.bindValue(":offre_id", offre_id); // ID de l'offre à mettre à jour

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la mise à jour de l'offre:" << query.lastError().text();
        return false;
    }
}
// -----------------------------------------------------------------------------------
// ----------------- Tri -----------
QSqlQueryModel* Offre::trier(const QString& critere, bool ascendant) {
    QSqlQuery query;
    QString queryString = "SELECT * FROM offre_emploi";  // Corrected to select from the 'offre' table

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
QSqlQueryModel* Offre::rechercher(const QString& valeur) {
    QSqlQuery query;
    QString queryString;

    if (valeur.toInt() > 0) {
        // Recherche par ID (si la valeur est un entier positif)
        queryString = "SELECT * FROM offre_emploi WHERE offre_id = :valeur";
    } else {
        // Vérifier si la valeur semble être une date
        QDate date = QDate::fromString(valeur, "dd/MM/yy"); // Format selon votre exemple
        if (date.isValid()) {
            // Recherche par date
            queryString = "SELECT * FROM offre_emploi WHERE TO_CHAR(date_publication, 'DD/MM/YY') = :valeurDate";
        } else {
            // Recherche par titre
            queryString = "SELECT * FROM offre_emploi WHERE titre LIKE :valeurLike";
        }
    }

    query.prepare(queryString);

    if (valeur.toInt() > 0) {
        query.bindValue(":valeur", valeur.toInt());
    } else {
        QDate date = QDate::fromString(valeur, "dd/MM/yy");
        if (date.isValid()) {
            query.bindValue(":valeurDate", valeur); // Utilisez le format DD/MM/YY
        } else {
            query.bindValue(":valeurLike", "%" + valeur + "%");
        }
    }

    qDebug() << "Executing query:" << queryString;
    qDebug() << "Binding values - " << (valeur.toInt() > 0 ? "exact:" : "LIKE pattern:") << valeur;

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query); // Utilisation correcte de setQuery avec un objet QSqlQuery

    return model;
}

// -----------stat Ofrre

QPieSeries* Offre::stat_offre() {
    QPieSeries *series = new QPieSeries();

    // Query to count the number of job offers per sector
    QSqlQuery query;
    query.prepare("SELECT e.secteur, COUNT(o.offre_id) "
                  "FROM offre_emploi o "
                  "JOIN entreprise e ON o.entreprise_id = e.entreprise_id "
                  "GROUP BY e.secteur");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
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


