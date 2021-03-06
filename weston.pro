#-------------------------------------------------
#
# Project created by QtCreator 2018-03-11T10:11:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = weston
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mycanvas.cpp \
    point.cpp \
    rgb.cpp \
    option.cpp \
    beziercurvewidget.cpp \
    beziercurvecanvas.cpp \
    beziercurveoption.cpp \
    bsplinecurvewidget.cpp \
    bsplinecurvecanvas.cpp \
    scanelinewidget.cpp \
    scanelinecanvas.cpp \
    morphologyoperationswidget.cpp \
    morphologyoperationscanvas.cpp \
    colormodelswidget.cpp \
    colormodelcanvas.cpp \
    hsv.cpp \
    imagecolormodelwidget.cpp \
    imagecolormodelcanvas.cpp \
    blendmodeswidget.cpp \
    blendmodescanvas.cpp \
    transformations2dwidget.cpp \
    transformations2dcanvas.cpp \
    point3.cpp \
    texturingwidget.cpp \
    texturingcanvas.cpp \
    floatpoint.cpp \
    four.cpp \
    transformations3dwidget.cpp \
    transformations3dcanvas.cpp \
    matrix.cpp

HEADERS += \
        mainwindow.h \
    mycanvas.h \
    point.h \
    rgb.h \
    beziercurvewidget.h \
    beziercurvecanvas.h \
    bsplinecurvewidget.h \
    bsplinecurvecanvas.h \
    scanelinewidget.h \
    scanelinecanvas.h \
    morphologyoperationswidget.h \
    morphologyoperationscanvas.h \
    colormodelswidget.h \
    colormodelcanvas.h \
    hsv.h \
    imagecolormodelwidget.h \
    imagecolormodelcanvas.h \
    blendmodeswidget.h \
    blendmodescanvas.h \
    transformations2dwidget.h \
    transformations2dcanvas.h \
    point3.h \
    texturingwidget.h \
    texturingcanvas.h \
    floatpoint.h \
    four.h \
    transformations3dwidget.h \
    transformations3dcanvas.h \
    matrix.h

FORMS += \
        mainwindow.ui \
    beziercurvewidget.ui \
    bsplinecurvewidget.ui \
    scanelinewidget.ui \
    morphologyoperationswidget.ui \
    colormodelswidget.ui \
    imagecolormodelwidget.ui \
    blendmodeswidget.ui \
    transformations2dwidget.ui \
    texturingwidget.ui \
    transformations3dwidget.ui
