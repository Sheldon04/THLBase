QT       += core gui
QT += charts
QT       += sql
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += qaxcontainer

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
    addrecord.cpp \
    baseEncode.cpp \
    datavisualize.cpp \
    entrydialog.cpp \
    env.cpp \
    httptrace.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp \
    searchdata.cpp \
    databasemanager.cpp \
    userwindow.cpp \
    service.cpp \
    avltree.cpp \
    detailinfowindow.cpp

HEADERS += \
    aboutusdialog.h \
    addrecord.h \
    baseEncode.h \
    datavisualize.h \
    entrydialog.h \
    env.h \
    httptrace.h \
    huffTree.h \
    mainwindow.h \
    oneSearchInfo.h \
    register.h \
    searchdata.h \
    databasemanager.h \
    global.h \
    userwindow.h \
    diffexpinfoitem.h \
    service.h \
    avltree.h \
    detailinfowindow.h

FORMS += \
    aboutusdialog.ui \
    addrecord.ui \
    datavisualize.ui \
    entrydialog.ui \
    env.ui \
    httptrace.ui \
    mainwindow.ui \
    register.ui \
    searchdata.ui \
    userwindow.ui \
    detailinfowindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
