#-------------------------------------------------
#
# Project created by QtCreator 2018-12-13T12:09:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DeprCalcQt

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
        main.cpp \
        deprcalc.cpp

HEADERS += \
        deprcalc.h \
    Asset.h

FORMS += \
        deprcalc.ui

# Default rules for deployment.
basic.path=~/Programs/$${TARGET}/deploy
basic.files=/home/adam/Qt/5.12.0/gcc_64/lib/libQt5Widgets.so.5 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libQt5Widgets.so.5.12.0 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libQt5Gui.so.5 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libQt5Gui.so.5.12.0 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libQt5Core.so.5 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libQt5Core.so.5.12.0 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libicui18n.so.56 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libicui18n.so.56.1 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libicuuc.so.56 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libicuuc.so.56.1 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libicudata.so.56 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libicudata.so.56.1 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libQt5XcbQpa.so.5 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libQt5XcbQpa.so.5.12 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libQt5DBus.so.5 \
            /home/adam/Qt/5.12.0/gcc_64/lib/libQt5DBus.so.5.12.0

platform.path=~/Programs/$${TARGET}/deploy/platforms
platform.files=/home/adam/Qt/5.12.0/gcc_64/plugins/platforms/libqxcb.so


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = ~/Programs/$${TARGET}/deploy
!isEmpty(target.path): INSTALLS += target basic platform

DISTFILES += \
    readme.md
