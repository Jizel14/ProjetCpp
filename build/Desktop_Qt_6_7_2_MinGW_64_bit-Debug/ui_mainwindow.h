/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QTabWidget *tabWidget_3;
    QWidget *tab_7;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *id_ep;
    QLineEdit *n_ep;
    QLineEdit *ad_ep;
    QLineEdit *tel_ep;
    QLineEdit *email_ep;
    QPushButton *pb_ep;
    QLineEdit *sec_ep;
    QLabel *label_26;
    QWidget *tab_8;
    QLabel *label_18;
    QLineEdit *id_ep_md;
    QLineEdit *nv_ep_id;
    QLineEdit *nv_ep_n;
    QLineEdit *nv_ep_t;
    QLineEdit *nv_ep_ad;
    QLineEdit *nv_ep_email;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QGroupBox *groupBox_4;
    QPushButton *modifier_ep;
    QLabel *label_25;
    QLineEdit *nv_ep_sec;
    QLabel *label_24;
    QWidget *tab_9;
    QTableView *tab_entreprise;
    QComboBox *comboBox;
    QPushButton *pb_trie;
    QLineEdit *rech_ep;
    QPushButton *pb_rech_ep;
    QWidget *tab_18;
    QPushButton *pb_email;
    QLineEdit *id_email;
    QWidget *tab_11;
    QGraphicsView *graphicsViewStatistiques;
    QWidget *tab_10;
    QLabel *label_5;
    QLineEdit *id_sup_ep;
    QPushButton *pb_sup_ep;
    QWidget *tab_17;
    QTableView *tab_ar;
    QPushButton *pb_pdf;
    QWidget *tab_6;
    QTabWidget *tabWidget_4;
    QWidget *tab_12;
    QGroupBox *groupBox_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *id_of;
    QLineEdit *titre_of;
    QPushButton *pb_of;
    QLabel *label_17;
    QTextEdit *d_of;
    QDateTimeEdit *date_pub;
    QDateEdit *d_l;
    QLineEdit *id_ep_of;
    QWidget *tab_13;
    QGroupBox *groupBox_5;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *id_of_2;
    QLineEdit *titre_of_2;
    QPushButton *pb_of_md;
    QLabel *label_32;
    QTextEdit *d_of_2;
    QDateTimeEdit *date_pub_2;
    QDateEdit *d_l_2;
    QLineEdit *id_ep_of_2;
    QLabel *label_33;
    QLineEdit *id_of_md;
    QWidget *tab_14;
    QTableView *tab_of;
    QComboBox *comboBox_2;
    QPushButton *Tri_of;
    QPushButton *rech_off;
    QLineEdit *rech_of;
    QPushButton *pb_of_pdf;
    QPushButton *pb_arof;
    QWidget *tab_15;
    QLabel *label_16;
    QLineEdit *id_of_sup;
    QPushButton *pb_sup_of;
    QWidget *tab_16;
    QGraphicsView *stat_offre;
    QWidget *tab_19;
    QTableView *tab_arof;
    QWidget *tab_20;
    QGraphicsView *graph_of;
    QLabel *label_pic;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1181, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 1081, 501));
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tabWidget_3 = new QTabWidget(tab_5);
        tabWidget_3->setObjectName("tabWidget_3");
        tabWidget_3->setGeometry(QRect(0, 0, 1011, 461));
        tabWidget_3->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        groupBox_2 = new QGroupBox(tab_7);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 0, 701, 381));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 40, 91, 20));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 80, 63, 20));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 130, 63, 20));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 180, 63, 20));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 230, 63, 20));
        id_ep = new QLineEdit(groupBox_2);
        id_ep->setObjectName("id_ep");
        id_ep->setGeometry(QRect(120, 40, 113, 28));
        n_ep = new QLineEdit(groupBox_2);
        n_ep->setObjectName("n_ep");
        n_ep->setGeometry(QRect(120, 80, 113, 28));
        ad_ep = new QLineEdit(groupBox_2);
        ad_ep->setObjectName("ad_ep");
        ad_ep->setGeometry(QRect(120, 120, 113, 28));
        tel_ep = new QLineEdit(groupBox_2);
        tel_ep->setObjectName("tel_ep");
        tel_ep->setGeometry(QRect(120, 170, 113, 28));
        email_ep = new QLineEdit(groupBox_2);
        email_ep->setObjectName("email_ep");
        email_ep->setGeometry(QRect(120, 220, 113, 28));
        pb_ep = new QPushButton(groupBox_2);
        pb_ep->setObjectName("pb_ep");
        pb_ep->setGeometry(QRect(520, 280, 83, 29));
        QFont font;
        font.setBold(true);
        pb_ep->setFont(font);
        pb_ep->setCheckable(false);
        sec_ep = new QLineEdit(groupBox_2);
        sec_ep->setObjectName("sec_ep");
        sec_ep->setGeometry(QRect(120, 270, 113, 28));
        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 280, 63, 20));
        tabWidget_3->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        label_18 = new QLabel(tab_8);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(60, 40, 101, 20));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(true);
        label_18->setFont(font1);
        id_ep_md = new QLineEdit(tab_8);
        id_ep_md->setObjectName("id_ep_md");
        id_ep_md->setGeometry(QRect(170, 30, 113, 28));
        nv_ep_id = new QLineEdit(tab_8);
        nv_ep_id->setObjectName("nv_ep_id");
        nv_ep_id->setGeometry(QRect(230, 110, 113, 28));
        nv_ep_n = new QLineEdit(tab_8);
        nv_ep_n->setObjectName("nv_ep_n");
        nv_ep_n->setGeometry(QRect(230, 160, 113, 28));
        nv_ep_t = new QLineEdit(tab_8);
        nv_ep_t->setObjectName("nv_ep_t");
        nv_ep_t->setGeometry(QRect(230, 260, 113, 28));
        nv_ep_ad = new QLineEdit(tab_8);
        nv_ep_ad->setObjectName("nv_ep_ad");
        nv_ep_ad->setGeometry(QRect(230, 210, 113, 28));
        nv_ep_email = new QLineEdit(tab_8);
        nv_ep_email->setObjectName("nv_ep_email");
        nv_ep_email->setGeometry(QRect(230, 310, 113, 28));
        label_19 = new QLabel(tab_8);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(62, 120, 111, 20));
        label_20 = new QLabel(tab_8);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(60, 170, 111, 20));
        label_21 = new QLabel(tab_8);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(60, 220, 111, 20));
        label_22 = new QLabel(tab_8);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(60, 270, 111, 20));
        label_23 = new QLabel(tab_8);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(60, 320, 111, 20));
        groupBox_4 = new QGroupBox(tab_8);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(50, 80, 451, 311));
        modifier_ep = new QPushButton(groupBox_4);
        modifier_ep->setObjectName("modifier_ep");
        modifier_ep->setGeometry(QRect(350, 270, 83, 29));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(true);
        modifier_ep->setFont(font2);
        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(10, 280, 111, 20));
        nv_ep_sec = new QLineEdit(groupBox_4);
        nv_ep_sec->setObjectName("nv_ep_sec");
        nv_ep_sec->setGeometry(QRect(180, 280, 113, 28));
        label_24 = new QLabel(tab_8);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(60, 120, 111, 20));
        tabWidget_3->addTab(tab_8, QString());
        groupBox_4->raise();
        label_18->raise();
        id_ep_md->raise();
        nv_ep_id->raise();
        nv_ep_n->raise();
        nv_ep_t->raise();
        nv_ep_ad->raise();
        nv_ep_email->raise();
        label_19->raise();
        label_20->raise();
        label_21->raise();
        label_22->raise();
        label_23->raise();
        label_24->raise();
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        tab_entreprise = new QTableView(tab_9);
        tab_entreprise->setObjectName("tab_entreprise");
        tab_entreprise->setGeometry(QRect(0, 0, 841, 421));
        comboBox = new QComboBox(tab_9);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(700, 20, 82, 28));
        comboBox->setStyleSheet(QString::fromUtf8(""));
        pb_trie = new QPushButton(tab_9);
        pb_trie->setObjectName("pb_trie");
        pb_trie->setGeometry(QRect(700, 70, 83, 29));
        rech_ep = new QLineEdit(tab_9);
        rech_ep->setObjectName("rech_ep");
        rech_ep->setGeometry(QRect(30, 220, 113, 28));
        pb_rech_ep = new QPushButton(tab_9);
        pb_rech_ep->setObjectName("pb_rech_ep");
        pb_rech_ep->setGeometry(QRect(160, 220, 83, 29));
        tabWidget_3->addTab(tab_9, QString());
        tab_18 = new QWidget();
        tab_18->setObjectName("tab_18");
        pb_email = new QPushButton(tab_18);
        pb_email->setObjectName("pb_email");
        pb_email->setGeometry(QRect(120, 130, 101, 29));
        id_email = new QLineEdit(tab_18);
        id_email->setObjectName("id_email");
        id_email->setGeometry(QRect(120, 70, 113, 28));
        tabWidget_3->addTab(tab_18, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName("tab_11");
        graphicsViewStatistiques = new QGraphicsView(tab_11);
        graphicsViewStatistiques->setObjectName("graphicsViewStatistiques");
        graphicsViewStatistiques->setGeometry(QRect(10, 10, 1001, 411));
        graphicsViewStatistiques->setAutoFillBackground(false);
        tabWidget_3->addTab(tab_11, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        label_5 = new QLabel(tab_10);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 40, 91, 20));
        id_sup_ep = new QLineEdit(tab_10);
        id_sup_ep->setObjectName("id_sup_ep");
        id_sup_ep->setGeometry(QRect(120, 40, 141, 28));
        pb_sup_ep = new QPushButton(tab_10);
        pb_sup_ep->setObjectName("pb_sup_ep");
        pb_sup_ep->setGeometry(QRect(140, 140, 83, 29));
        pb_sup_ep->setFont(font2);
        pb_sup_ep->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        pb_sup_ep->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        pb_sup_ep->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        tabWidget_3->addTab(tab_10, QString());
        tab_17 = new QWidget();
        tab_17->setObjectName("tab_17");
        tab_ar = new QTableView(tab_17);
        tab_ar->setObjectName("tab_ar");
        tab_ar->setGeometry(QRect(0, 0, 1011, 431));
        pb_pdf = new QPushButton(tab_17);
        pb_pdf->setObjectName("pb_pdf");
        pb_pdf->setGeometry(QRect(880, 20, 83, 29));
        tabWidget_3->addTab(tab_17, QString());
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget_4 = new QTabWidget(tab_6);
        tabWidget_4->setObjectName("tabWidget_4");
        tabWidget_4->setGeometry(QRect(0, 0, 1011, 461));
        tabWidget_4->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        tab_12 = new QWidget();
        tab_12->setObjectName("tab_12");
        groupBox_3 = new QGroupBox(tab_12);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(0, 0, 701, 381));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 40, 91, 20));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 80, 63, 20));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 130, 81, 20));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(380, 40, 63, 20));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(380, 90, 63, 20));
        id_of = new QLineEdit(groupBox_3);
        id_of->setObjectName("id_of");
        id_of->setGeometry(QRect(120, 40, 113, 28));
        titre_of = new QLineEdit(groupBox_3);
        titre_of->setObjectName("titre_of");
        titre_of->setGeometry(QRect(120, 80, 113, 28));
        pb_of = new QPushButton(groupBox_3);
        pb_of->setObjectName("pb_of");
        pb_of->setGeometry(QRect(520, 280, 83, 29));
        pb_of->setFont(font);
        pb_of->setCheckable(false);
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(380, 170, 101, 20));
        d_of = new QTextEdit(groupBox_3);
        d_of->setObjectName("d_of");
        d_of->setGeometry(QRect(120, 130, 161, 141));
        date_pub = new QDateTimeEdit(groupBox_3);
        date_pub->setObjectName("date_pub");
        date_pub->setGeometry(QRect(470, 40, 194, 29));
        d_l = new QDateEdit(groupBox_3);
        d_l->setObjectName("d_l");
        d_l->setGeometry(QRect(470, 90, 141, 29));
        id_ep_of = new QLineEdit(groupBox_3);
        id_ep_of->setObjectName("id_ep_of");
        id_ep_of->setGeometry(QRect(470, 160, 113, 28));
        tabWidget_4->addTab(tab_12, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName("tab_13");
        groupBox_5 = new QGroupBox(tab_13);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 40, 701, 371));
        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 40, 91, 20));
        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 80, 63, 20));
        label_29 = new QLabel(groupBox_5);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(10, 130, 81, 20));
        label_30 = new QLabel(groupBox_5);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(380, 40, 63, 20));
        label_31 = new QLabel(groupBox_5);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(380, 90, 63, 20));
        id_of_2 = new QLineEdit(groupBox_5);
        id_of_2->setObjectName("id_of_2");
        id_of_2->setGeometry(QRect(120, 40, 113, 28));
        titre_of_2 = new QLineEdit(groupBox_5);
        titre_of_2->setObjectName("titre_of_2");
        titre_of_2->setGeometry(QRect(120, 80, 113, 28));
        pb_of_md = new QPushButton(groupBox_5);
        pb_of_md->setObjectName("pb_of_md");
        pb_of_md->setGeometry(QRect(520, 280, 83, 29));
        pb_of_md->setFont(font);
        pb_of_md->setCheckable(false);
        label_32 = new QLabel(groupBox_5);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(380, 170, 101, 20));
        d_of_2 = new QTextEdit(groupBox_5);
        d_of_2->setObjectName("d_of_2");
        d_of_2->setGeometry(QRect(120, 130, 161, 141));
        date_pub_2 = new QDateTimeEdit(groupBox_5);
        date_pub_2->setObjectName("date_pub_2");
        date_pub_2->setGeometry(QRect(470, 40, 194, 29));
        d_l_2 = new QDateEdit(groupBox_5);
        d_l_2->setObjectName("d_l_2");
        d_l_2->setGeometry(QRect(470, 90, 141, 29));
        id_ep_of_2 = new QLineEdit(groupBox_5);
        id_ep_of_2->setObjectName("id_ep_of_2");
        id_ep_of_2->setGeometry(QRect(470, 160, 113, 28));
        label_33 = new QLabel(tab_13);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(10, 20, 101, 20));
        label_33->setFont(font1);
        id_of_md = new QLineEdit(tab_13);
        id_of_md->setObjectName("id_of_md");
        id_of_md->setGeometry(QRect(130, 20, 113, 28));
        tabWidget_4->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName("tab_14");
        tab_of = new QTableView(tab_14);
        tab_of->setObjectName("tab_of");
        tab_of->setGeometry(QRect(0, 0, 841, 421));
        comboBox_2 = new QComboBox(tab_14);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(680, 60, 82, 28));
        Tri_of = new QPushButton(tab_14);
        Tri_of->setObjectName("Tri_of");
        Tri_of->setGeometry(QRect(680, 110, 83, 29));
        rech_off = new QPushButton(tab_14);
        rech_off->setObjectName("rech_off");
        rech_off->setGeometry(QRect(210, 240, 83, 29));
        rech_of = new QLineEdit(tab_14);
        rech_of->setObjectName("rech_of");
        rech_of->setGeometry(QRect(60, 240, 113, 28));
        pb_of_pdf = new QPushButton(tab_14);
        pb_of_pdf->setObjectName("pb_of_pdf");
        pb_of_pdf->setGeometry(QRect(650, 320, 91, 51));
        pb_arof = new QPushButton(tab_14);
        pb_arof->setObjectName("pb_arof");
        pb_arof->setGeometry(QRect(60, 320, 101, 51));
        tabWidget_4->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName("tab_15");
        label_16 = new QLabel(tab_15);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(30, 40, 91, 20));
        id_of_sup = new QLineEdit(tab_15);
        id_of_sup->setObjectName("id_of_sup");
        id_of_sup->setGeometry(QRect(120, 40, 141, 28));
        pb_sup_of = new QPushButton(tab_15);
        pb_sup_of->setObjectName("pb_sup_of");
        pb_sup_of->setGeometry(QRect(140, 140, 83, 29));
        pb_sup_of->setFont(font2);
        tabWidget_4->addTab(tab_15, QString());
        tab_16 = new QWidget();
        tab_16->setObjectName("tab_16");
        stat_offre = new QGraphicsView(tab_16);
        stat_offre->setObjectName("stat_offre");
        stat_offre->setGeometry(QRect(0, 0, 1001, 421));
        tabWidget_4->addTab(tab_16, QString());
        tab_19 = new QWidget();
        tab_19->setObjectName("tab_19");
        tab_arof = new QTableView(tab_19);
        tab_arof->setObjectName("tab_arof");
        tab_arof->setGeometry(QRect(0, 0, 1011, 431));
        tabWidget_4->addTab(tab_19, QString());
        tab_20 = new QWidget();
        tab_20->setObjectName("tab_20");
        graph_of = new QGraphicsView(tab_20);
        graph_of->setObjectName("graph_of");
        graph_of->setGeometry(QRect(0, 0, 1011, 421));
        tabWidget_4->addTab(tab_20, QString());
        label_pic = new QLabel(tab_6);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(1000, 0, 81, 61));
        tabWidget_2->addTab(tab_6, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        tabWidget_4->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Entreprise id :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "adresse", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "N\302\260 tel", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "e-mail", nullptr));
        pb_ep->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Secteur", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Ajouter Entreprise", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "ID \303\240 modifier ", nullptr));
        label_19->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "adresse", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Nouvelle Valeur", nullptr));
        modifier_ep->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Secteur", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QCoreApplication::translate("MainWindow", "Modifier Entreprise", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "id", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Secteur", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("MainWindow", "id", nullptr));
        pb_trie->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        pb_rech_ep->setText(QCoreApplication::translate("MainWindow", "Rechrche", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        pb_email->setText(QCoreApplication::translate("MainWindow", "envoyer email", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_18), QCoreApplication::translate("MainWindow", "e-mail", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_11), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Taper le ID", nullptr));
        pb_sup_ep->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pb_pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_17), QCoreApplication::translate("MainWindow", "Archive", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Gestion Entreprise", nullptr));
        groupBox_3->setTitle(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "offre id :", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "titre", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Date_pub", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "D_limte", nullptr));
        pb_of->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Entreprise_id", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_12), QCoreApplication::translate("MainWindow", "Ajouter Offre", nullptr));
        groupBox_5->setTitle(QString());
        label_27->setText(QCoreApplication::translate("MainWindow", "offre id :", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "titre", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Date_pub", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "D_limte", nullptr));
        pb_of_md->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Entreprise_id", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "ID \303\240 modifier ", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_13), QCoreApplication::translate("MainWindow", "Modifier Offre", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Id", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Date_pub", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Titre", nullptr));

        Tri_of->setText(QCoreApplication::translate("MainWindow", "Tri", nullptr));
        rech_off->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        pb_of_pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pb_arof->setText(QCoreApplication::translate("MainWindow", "Archiver", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_14), QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Taper le ID", nullptr));
        pb_sup_of->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_15), QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_16), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_19), QCoreApplication::translate("MainWindow", "Archive", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_20), QCoreApplication::translate("MainWindow", "Activit\303\251s", nullptr));
        label_pic->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Gestion d'offre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
