#-------------------------------------------------
#
# Project created by QtCreator 2014-05-02T14:56:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TremProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    trilhos.cpp \
    trem.cpp \
    thread.cpp \
    semaforo.cpp \
    myqthread.cpp \
    sobre.cpp

HEADERS  += mainwindow.h \
    trilhos.h \
    trem.h \
    thread.h \
    semaforo.h \
    myqthread.h \
    sobre.h

FORMS    += mainwindow.ui \
    sobre.ui
