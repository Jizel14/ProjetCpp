#include "etudiant.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include<QSqlQueryModel>
#include<QObject>
Etudiant::Etudiant() {
    id =0; nom=""; prenom="";
}



Etudiant::Etudiant(int id,QString nom,QString prenom)
{
    this -> id=id; this -> nom=nom; this -> prenom=prenom;
}
int Etudiant::getid(){return id;}
QString Etudiant:: getnom(){return nom;}
QString Etudiant::getprenom(){return prenom;}
void Etudiant::setid(int id){this->id=id;}
void Etudiant::setnom(QString nom){this->nom=nom;}
void Etudiant::setprenom(QString prenom){this->prenom=prenom;}
// ajouter l'etudiant
bool Etudiant::ajouter(){
    //bool test=false;
    QString id_string=QString::number(id);
    QSqlQuery query;

    query.prepare("INSERT INTO ETUDIANT (id, nom, prenom) "
                  "VALUES (:id, :nom, :prenom)");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    return query.exec();

   // return test;
}
QSqlQueryModel* Etudiant::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM etudiant");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

    return model;

}

bool Etudiant::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("Delete from etudiant where id=:id");
    query.bindValue(":id", id);
    return query.exec();
}




