#-------------------------------------------------
#
# Project created by QtCreator 2015-01-15T20:51:10
#
#-------------------------------------------------

QT       += core gui printsupport opengl sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LocoLayout
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    gridscene.cpp \
    trackonexone.cpp \
    tracktwoxtwo.cpp \
    trackpiece.cpp \
    detectionsection.cpp \
    trackfourxtwo.cpp \
    tracktwoxfour.cpp

HEADERS  += mainwindow.h \
    view.h \
    gridscene.h \
    trackonexone.h \
    tracktwoxtwo.h \
    trackpiece.h \
    detectionsection.h \
    trackfourxtwo.h \
    tracktwoxfour.h

FORMS    += mainwindow.ui

RESOURCES += \
    images/trackpieces/trackpieces.qrc \
    images/images.qrc

CONFIG += static
QMAKE_CXXFLAGS += -std=c++0x

OTHER_FILES +=

win32:RC_ICONS += images/icon.ico

