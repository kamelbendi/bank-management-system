QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    investmentwindow.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    normalaccount.cpp \
    normalwindow.cpp \
    registerdialog.cpp \
    savingwindow.cpp

HEADERS += \
    investmentwindow.h \
    logindialog.h \
    bank.h \
    mainwindow.h \
    normalaccount.h \
    normalwindow.h \
    registerdialog.h \
    savingaccount.h \
    investmentaccount.h \
    savingwindow.h \
    stock.h

FORMS += \
    investmentwindow.ui \
    logindialog.ui \
    mainwindow.ui \
    normalwindow.ui \
    registerdialog.ui \
    savingwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Resources/santander.dat
