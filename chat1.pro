#-------------------------------------------------
#
# Project created by QtCreator 2017-05-07T21:19:44
#
#-------------------------------------------------

QT       += core gui
QT       += core network

TARGET = chat1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    userlistwindow.cpp \
    chatwindow.cpp

HEADERS  += mainwindow.h \
    userlistwindow.h \
    chatwindow.h

FORMS    += mainwindow.ui \
    userlistwindow.ui \
    chatwindow.ui

RESOURCES += \
    resource.qrc
