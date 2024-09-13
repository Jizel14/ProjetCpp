#ifndef OFFRE_H
#define OFFRE_H
#include <QString>
#include <QDate>
#include<QSqlQueryModel>
#include <QPieSeries>

#include <QList>
#include <QVariantMap>
#include <QStandardItemModel>

#include <QMessageBox>

class Offre
{
public:
    Offre();
    Offre(int offre_id, QString titre, QString description, QDate date_publication, QDate date_limite, int entreprise_id);

    // Getters and Setters
    int getOffreId() const;
    void setOffreId(int value);

    QString getTitre() const;
    void setTitre(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QDate getDatePublication() const;
    void setDatePublication(const QDate &value);

    QDate getDateLimit() const;
    void setDateLimit(const QDate &value);

    int getEntrepriseId() const;
    void setEntrepriseId(int value);


    // crud + métier

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
 bool modifier(int offre_id);
    // ---------------------------------------------

     // ------- métier ------
 QSqlQueryModel* trier(const QString& critere, bool ascendant = true);
 QSqlQueryModel* rechercher(const QString& )    ;

 QPieSeries* stat_offre();
 bool genererPDFOffres(const QString &cheminFichier);

 bool archiverOffresExpirees();
 QSqlQueryModel* afficherArchivesOffre() const;
 bool archiverOffres(const QDate& dateActuelle);

 QPieSeries* getNombreOffresParEntreprise() const;







private :
    int offre_id;
    QString titre;
    QString description;
    QDate date_publication;
    QDate date_limite;
    int entreprise_id;

};

#endif // OFFRE_H
