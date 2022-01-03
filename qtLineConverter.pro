#-------------------------------------------------
#
# Project created by QtCreator 2021-09-27T11:41:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

ICON = qtLineConverter.png
#win32:RC_ICONS = qtLineConverter.ico
#ICON = qtLineConverter.icns

TARGET = qtLineConverter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        ataripalgen.cpp \
        ataripic.cpp

HEADERS  += mainwindow.h \
    ataripalgen.h \
    ataripic.h \
    basexex.h

FORMS    += mainwindow.ui

RESOURCES += qtLineConverter.qrc
