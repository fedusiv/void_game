#-------------------------------------------------
#
# Project created by QtCreator 2019-06-18T08:32:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = void
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        gamemanager.cpp \
        gui.cpp \
        main.cpp \
        player/paramscounting.cpp \
        player.cpp \
        player/playerinventory.cpp \
        player/playerclass.cpp \
        player/playerrace.cpp \
        player/playerstats.cpp \
        testwidget.cpp

HEADERS += \
    gamemanager.h \
    gui.h \
    player/paramscounting.h \
    player.h \
    player/playerinventory.h \
    player/playerclass.h \
    player/playerrace.h \
    player/playerstats.h \
    testwidget.h

FORMS += \
    testwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
