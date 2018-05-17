#-------------------------------------------------
#
# Project created by QtCreator 2018-03-02T14:32:02
#
#-------------------------------------------------

QT       += core gui network
#multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = temp

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += main.cpp\
        mainwindow.cpp \
        inputmanager.cpp \
        keyboardinputmanager.cpp \
        outputmanager.cpp \
        consoleoutputmanager.cpp \
        direction.cpp \
        connexionmanager.cpp \
        wificonnexionmanager.cpp \
        tcpconnexionmanager.cpp \
        joypad.cpp \
        robotoutputmanager.cpp

HEADERS  += mainwindow.h \
        inputmanager.h \
        keyboardinputmanager.h \
        outputmanager.h \
        consoleoutputmanager.h \
        direction.h \
        connexionmanager.h \
        wificonnexionmanager.h \
        tcpconnexionmanager.h \
        joypad.h \
        robotoutputmanager.h

FORMS    += mainwindow.ui
#mainwindow2.ui

CONFIG   += console
