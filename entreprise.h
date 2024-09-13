#ifndef ENTREPRISE_H
#define ENTREPRISE_H
#include <QString>
#include<QSqlQueryModel>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QPieSeries>



class Entreprise
{
public:
    Entreprise();
    Entreprise(int,QString,QString,QString,QString,QString);

    int getentreprise_id();
    QString getnom_entreprise();
    QString getadresse();
    QString gettelephone();
    QString getemail();
    QString getsecteur();

    void setentreprise_id(int);
    void setnom_entreprise(QString);
    void setadresse(QString);
    void settelephone(QString);
    void setemail(QString);
    void setsecteur(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool archiver(int);
    QSqlQueryModel* afficherArchives() const;

    bool modifierEntreprise(int, int, const QString &, const QString &, const QString &, const QString &, const QString &);




    //---------------------------
    QPieSeries* obtenirStatistiquesParSecteur();
    QSqlQueryModel* trier(const QString& critere, bool ascendant = true);
    QSqlQueryModel* rechercher(const QString& )    ;

    bool genererPDFArchives(const QString &);

    bool envoyerEmail(QString entreprise_id, QString sujet, QString message);



private:
    int entreprise_id;
    QString nom_entreprise, adresse, telephone, email, secteur;
};

#endif // ENTREPRISE_H
