#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T10:30:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ListAllWindows
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    workwindow.cpp

HEADERS  += mainwindow.h \
    workwindow.h

FORMS    += mainwindow.ui \
    workwindow.ui \
    information.ui

LIBS += -lUser32
