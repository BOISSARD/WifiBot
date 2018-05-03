#-------------------------------------------------
#
# Project created by QtCreator 2018-03-02T14:32:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = temp

TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        inputmanager.cpp \
        keyboardinputmanager.cpp \
        outputmanager.cpp \
        consoleoutputmanager.cpp

HEADERS  += mainwindow.h \
        inputmanager.h \
        keyboardinputmanager.h \
        outputmanager.h \
        consoleoutputmanager.h

FORMS    += mainwindow.ui

#CONFIG   -= qt
CONFIG   += console
