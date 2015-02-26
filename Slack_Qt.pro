#-------------------------------------------------
#
# Project created by QtCreator 2015-02-23T22:40:08
#
#-------------------------------------------------

QT       += core gui network widgets webkitwidgets winextras

TARGET = Slack_Qt
TEMPLATE = app

include(asemantools/asemantools.pri)
include(plugins/qtwebkit/qtwebkit-plugins.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    mainapplication.cpp \
    cookiejar.cpp \
    autosaver.cpp \
    networkaccessmanager.cpp \
    teamform.cpp

HEADERS  += mainwindow.h \
    mainapplication.h \
    cookiejar.h \
    autosaver.h \
    networkaccessmanager.h \
    teamform.h

FORMS    += mainwindow.ui \
    teamform.ui

RESOURCES += \
    icons.qrc

DISTFILES += \
    readme.md \
    fonts/Lato-Black.ttf \
    fonts/Lato-BlackItalic.ttf \
    fonts/Lato-Bold.ttf \
    fonts/Lato-BoldItalic.ttf \
    fonts/Lato-Hairline.ttf \
    fonts/Lato-HairlineItalic.ttf \
    fonts/Lato-Heavy.ttf \
    fonts/Lato-HeavyItalic.ttf \
    fonts/Lato-Italic.ttf \
    fonts/Lato-Light.ttf \
    fonts/Lato-LightItalic.ttf \
    fonts/Lato-Medium.ttf \
    fonts/Lato-MediumItalic.ttf \
    fonts/Lato-Regular.ttf \
    fonts/Lato-Semibold.ttf \
    fonts/Lato-SemiboldItalic.ttf \
    fonts/Lato-Thin.ttf \
    fonts/Lato-ThinItalic.ttf
