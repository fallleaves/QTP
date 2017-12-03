#-------------------------------------------------
#
# Project created by QtCreator 2017-03-12T13:55:44
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTP
TEMPLATE = app


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    Tools/datagenerator.cpp \
    Tools/timer.cpp \
    Modules/inputmanager.cpp \
    Core/core.cpp

HEADERS  += \
    mainwindow.hpp \
    Core/core.hpp \
    Modules/inputmanager.hpp \
    Tools/datagenerator.hpp \
    Tools/defines.hpp \
    Tools/timer.hpp

FORMS    += mainwindow.ui
