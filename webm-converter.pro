#-------------------------------------------------
#
# Project created by QtCreator 2015-09-24T18:45:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = webm-converter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    webmconverter.cpp \
    aboutwindow.cpp \
    iomodule.cpp

HEADERS  += mainwindow.h \
    webmconverter.h \
    aboutwindow.h \
    iomodule.h

FORMS    += mainwindow.ui \
    aboutwindow.ui
