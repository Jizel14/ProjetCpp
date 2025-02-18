QT       += core gui sql charts printsupport widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    entreprise.cpp \
    main.cpp \
    mainwindow.cpp \
    offre.cpp

HEADERS += \
    connection.h \
    entreprise.h \
    mainwindow.h \
    offre.h

FORMS += \
    mainwindow.ui
    QT += charts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
