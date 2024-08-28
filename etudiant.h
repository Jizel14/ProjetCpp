#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include<QSqlQueryModel>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>

class Etudiant
{
public:
    //constructeur
    Etudiant();
    Etudiant(int,QString,QString);
        // get
        int getid();
    QString getnom();
    QString getprenom();
    // set
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    // ensemble d'infmartion , résultat d'une réquete sql
    QSqlQueryModel* afficher();
    bool supprimer(int);

private:
    int id;
    QString nom, prenom;
};

#endif // ETUDIANT_H
