#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"etudiant.h"
#include"entreprise.h"
#include"offre.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QGraphicsScene>
#include <QSqlQuery>
#include <QFileDialog>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // controle de saisir de l'id
    ui->le_id->setValidator( new QIntValidator(0, 99999, this));
    // pour refraiche le tableau
    ui->tab_etudiant->setModel(E.afficher());
    ui->tab_entreprise->setModel(ep.afficher());
    ui->tab_of->setModel(o.afficher());
    // inserer image
    QPixmap pix("D:/download/ttp_1.png");
    QPixmap scaledPix = pix.scaled(ui->label_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_pic->setPixmap(scaledPix);
     // ---------
    afficherArchives();


}


MainWindow::~MainWindow()
{
    delete ui;
}

// ajouter etudiant
void MainWindow::on_pb_ajout_clicked()
{
    // recuperer les donnees de l'etudiant
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    Etudiant E(id,nom,prenom);
    qDebug() << "Attempting to add student...";

    if (E.ajouter()) {
        QMessageBox::information(this, "Succès", "L'étudiant a été ajouté avec succès.");
        // refraiche le tableau pour affiche du nouveau
        ui->tab_etudiant->setModel(E.afficher());

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'étudiant.");
    }
}

// Supprimer entreprise
void MainWindow::on_pb_supprimer_clicked()
{
    int entreprise_id = ui->id_sup_ep->text().toInt();
    Entreprise ep1;

    bool success = ep1.archiver(entreprise_id);

    QMessageBox msgBox;
    if (success) {
        msgBox.setText("Suppression et archivage avec succès.");
        // Rafraîchir les vues
        ui->tab_entreprise->setModel(ep1.afficher());
        afficherArchives(); // Rafraîchir la page d'archives
    } else {
        msgBox.setText("Échec de suppression et d'archivage.");
    }
    msgBox.exec();

}
void MainWindow::afficherArchives() {
    Entreprise ep;
    QSqlQueryModel* archiveModel = ep.afficherArchives();
    if (archiveModel) {
        ui->tab_ar->setModel(archiveModel); // Assurez-vous que tab_ar est le QTableView pour les archives
    } else {
        qDebug() << "Failed to load archive data.";
    }
}
// ----------------------------------------------------------------
// ajouter entreprise
void MainWindow::on_pb_ep_clicked()
{
    int id=ui->id_ep->text().toInt();
    QString nom=ui->n_ep->text();
    QString adresse=ui->ad_ep->text();
    QString tel=ui->tel_ep->text();
    QString email=ui->email_ep->text();
    QString secteur=ui->sec_ep->text();


    Entreprise E(id,nom,adresse,tel,email,secteur);
    if (E.ajouter()) {
        QMessageBox::information(this, "Succès", "L'Entreprise a été ajouté avec succès.");
        // refraiche le tableau pour affiche du nouveau
        ui->tab_entreprise->setModel(ep.afficher());

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'Entreprise.");
    }
}




void MainWindow::on_pb_sup_ep_clicked()
{
    Entreprise ep1; ep1.setentreprise_id(ui->id_sup_ep->text().toInt());
    bool test=ep1.archiver(ep1.getentreprise_id());
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("suppression avec succes.");
        // refraiche le tableau pour affiche du nouveau
        ui->tab_entreprise->setModel(ep1.afficher());
        ui->tab_ar->setModel(ep1.afficherArchives());


    }else
        msgBox.setText("echec de suppression.");
    msgBox.exec();
}

void MainWindow::on_modifier_ep_clicked()
{
    int id = ui->id_ep_md->text().toInt();
    int newId = ui->nv_ep_id->text().toInt();
    QString nom = ui->nv_ep_n->text();
    QString adresse = ui->nv_ep_ad->text();
    QString telephone = ui->nv_ep_t->text();
    QString email = ui->nv_ep_email->text();
    QString secteur = ui->nv_ep_sec->text();

    Entreprise entreprise;

    if (entreprise.modifierEntreprise(id, newId, nom, adresse, telephone, email,secteur)) {
        QMessageBox::information(this, "Succès", "L'entreprise a été modifiée avec succès.");
        // refraiche le tableau pour affiche du nouveau
        ui->tab_entreprise->setModel(entreprise.afficher());
    }

    else {
        QMessageBox::warning(this, "Erreur", "Impossible de modifier l'entreprise. Vérifiez l'ID.");
    }
}


void MainWindow::on_tabWidget_3_tabBarClicked(int index)
{
    if (index == 4) {
        afficherPieChart();
    }
}
void MainWindow::afficherPieChart()
{
    Entreprise entreprise;
    QPieSeries *series = entreprise.obtenirStatistiquesParSecteur();

    if (!series) {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer les statistiques.");
        return;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des entreprises par secteur");
    chart->legend()->show();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajustez la taille du QChartView pour qu'il remplisse l'espace du QGraphicsView
    chartView->resize(ui->graphicsViewStatistiques->size()); // Redimensionner le chartView pour correspondre à la taille du QGraphicsView

    // Créer une scène graphique et y ajouter le chartView
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addWidget(chartView);

    // Définir la scène graphique pour le QGraphicsView
    ui->graphicsViewStatistiques->setScene(scene);
}
// --------------------- tri entreprise ----------

void MainWindow::on_pb_trie_clicked()
{
    QString critere = ui->comboBox->currentText().toLower();

    // Récupérez et ajustez le critère de tri
    if (critere == "id") {
        critere = "entreprise_id";
    } else if (critere == "secteur") {
        critere = "secteur";
    } else if (critere == "nom") {
        critere = "nom_entreprise";
    }

    bool ascendant = true;  // Optionnel : Ajouter une logique pour gérer l'ordre de tri
    QSqlQueryModel* model = entreprise.trier(critere, ascendant);
    ui->tab_entreprise->setModel(model);
}

// ------------ Recherche entreprise
void MainWindow::on_pb_rech_ep_clicked()
{
    QString valeur = ui->rech_ep->text(); // Récupération de la valeur saisie

    QSqlQueryModel* model = entreprise.rechercher(valeur);
    ui->tab_entreprise->setModel(model);
}

// ------------ pdf entreprise -----------
void MainWindow::on_pb_pdf_clicked()
{
    Entreprise ep;
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");

    if (filePath.isEmpty()) {
        return; // L'utilisateur a annulé la boîte de dialogue
    }

    bool success = ep.genererPDFArchives(filePath);
    QMessageBox msgBox;
    if (success) {
        msgBox.setText("PDF généré avec succès.");
    } else {
        msgBox.setText("Échec de la génération du PDF.");
    }
    msgBox.exec();
}

// ---- email

void MainWindow::on_pb_email_clicked()
{
    QString entreprise_id = ui->id_email->text();
    QString sujet = "Sujet prédéfini";
    QString message = "Message prédéfini";

    if (entreprise.envoyerEmail(entreprise_id, sujet, message)) {
        QMessageBox::information(this, "Succès", "Email envoyé avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'envoi de l'email.");
    }
}

// ---- ----- --- ---- ------ ------- OFFRE EMPLOI ---- ----- ----- ------ ---- ----- ----


// -------- AJOUTER OFFRE ---------------
void MainWindow::on_pb_of_clicked()
{
    // Récupérer les valeurs des champs UI
    int offre_id = ui->id_of->text().toInt();
    QString titre = ui->titre_of->text();
    QString description = ui->d_of->toPlainText();
    QDate date_limit = ui->d_l->date();
    int entreprise_id = ui->id_ep_of->text().toInt();

    // Vérifier si la date de publication est fournie ou non
    QDate date_publication;
    if (!ui->date_pub->date().isNull()) {
        date_publication = ui->date_pub->date();
    } else {
        date_publication = QDate::currentDate();  // Utiliser la date actuelle
    }

    // Créer un objet Offre et l'ajouter à la base de données
    Offre offre(offre_id, titre, description, date_publication, date_limit, entreprise_id);
    bool success = offre.ajouter();

    // Vérifier le succès de l'ajout
    if (success) {
        QMessageBox::information(this, "Succès", "Offre d'emploi ajoutée avec succès.");
        // refraiche tableau offre
        ui->tab_of->setModel(o.afficher());

    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'ajout de l'offre d'emploi.");
    }
}

//----- SUPPRIMER OFFRE ---------

void MainWindow::on_pb_sup_of_clicked()
{
    Offre o ;
    int offre_id = ui->id_of_sup->text().toInt();

    bool success = o.supprimer(offre_id);

    QMessageBox msgBox;
    if (success) {
        msgBox.setText("Suppression avec succès.");
        // refraiche tableau offre
        ui->tab_of->setModel(o.afficher());

    } else {
        msgBox.setText("Échec de suppression .");
    }
    msgBox.exec();

}

// ------- modifer offre

void MainWindow::on_pb_of_md_clicked()
{
    // Récupérer les valeurs des champs UI
    int id_of = ui->id_of_md->text().toInt();
    int nouveau_id = ui->id_of_2->text().toInt();
    QString titre = ui->titre_of_2->text();
    QString description = ui->d_of_2->toPlainText();
    QDate date_limite = ui->d_l_2->date();
    QDate date_publication = ui->date_pub_2->date();
    int entreprise_id = ui->id_ep_of_2->text().toInt();

    // Créer un objet Offre et le modifier dans la base de données
    Offre offre(nouveau_id, titre, description, date_publication, date_limite, entreprise_id);
    bool success = offre.modifier(id_of);

    // Vérifier le succès de la modification
    QMessageBox msgBox;
    if (success) {
        msgBox.setText("Offre d'emploi modifiée avec succès.");
        // Rafraîchir le tableau offre, si nécessaire
        ui->tab_of->setModel(offre.afficher());
    } else {
        msgBox.setText("Échec de la modification de l'offre d'emploi.");
    }
    msgBox.exec();
}

// -------------- Tri Offre

void MainWindow::on_Tri_of_clicked()
{
    QString critere = ui->comboBox_2->currentText().toLower();
    Offre offre;
    // Adjust the criteria to match the actual column names in the 'offre' table
    if (critere == "id") {
        critere = "offre_id";
    } else if (critere == "date_pub") {
        critere = "date_publication";
    } else if (critere == "titre") {
        critere = "titre";
    }

    bool ascendant = true;  // Optionally, add logic to handle ascending/descending order
    QSqlQueryModel* model = offre.trier(critere, ascendant);
    ui->tab_of->setModel(model);
}


void MainWindow::on_rech_off_clicked()
{
    QString valeur = ui->rech_of->text(); // Récupération de la valeur saisie

    QSqlQueryModel* model = o.rechercher(valeur);
    ui->tab_of->setModel(model);

}

// -------------- stat offre

void MainWindow::afficherPieChartOffre() {
    Offre offre;
    QPieSeries *series = offre.stat_offre();

    if (!series) {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer les statistiques.");
        return;
    }


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des offres par secteur");
    chart->legend()->show();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajustez la taille du QChartView pour qu'il remplisse l'espace du QGraphicsView
    chartView->resize(ui->stat_offre->size());

    // Créer une scène graphique et y ajouter le chartView
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addWidget(chartView);

    // Définir la scène graphique pour le QGraphicsView
    ui->stat_offre->setScene(scene);
}

void MainWindow::on_tabWidget_4_tabBarClicked(int index)
{
    if (index == 4)
    {
        afficherPieChartOffre();

    }
}

