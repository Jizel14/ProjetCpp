#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "etudiant.h"
#include"entreprise.h"
#include"offre.h"
#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajout_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ep_clicked();

    void on_pb_sup_ep_clicked();

    void on_modifier_ep_clicked();

    void on_tabWidget_3_tabBarClicked(int index);

    void afficherPieChart();

    void afficherPieChartOffre();



    void on_pb_trie_clicked();

    void on_pb_rech_ep_clicked();
    void afficherArchives();


    void on_pb_pdf_clicked();

    void on_pb_email_clicked();

    void on_pb_of_clicked();

    void on_pb_sup_of_clicked();

    void on_pb_of_md_clicked();

    void on_Tri_of_clicked();

    void on_rech_off_clicked();

    void on_tabWidget_4_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
    Etudiant E;
    Entreprise ep;
    Entreprise entreprise;
    Offre o;


};
#endif // MAINWINDOW_H
