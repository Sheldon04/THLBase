QT       += core gui
QT += charts
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutusdialog.cpp \
    adddata.cpp \
    deletedata.cpp \
    entrydialog.cpp \
    main.cpp \
    mainwindow.cpp \
    modifydata.cpp \
    personaldailog.cpp \
    register.cpp \
    searchdata.cpp \
    searchresult.cpp \
    statistic.cpp \
    databasemanager.cpp

HEADERS += \
    aboutusdialog.h \
    adddata.h \
    deletedata.h \
    entrydialog.h \
    mainwindow.h \
    modifydata.h \
    oneSearchInfo.h \
    personaldailog.h \
    register.h \
    searchdata.h \
    searchresult.h \
    statistic.h \
    databasemanager.h \
    global.h

FORMS += \
    aboutusdialog.ui \
    adddata.ui \
    deletedata.ui \
    entrydialog.ui \
    mainwindow.ui \
    modifydata.ui \
    personaldailog.ui \
    register.ui \
    searchdata.ui \
    searchresult.ui \
    statistic.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
