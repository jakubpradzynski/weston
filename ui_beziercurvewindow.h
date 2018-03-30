/********************************************************************************
** Form generated from reading UI file 'beziercurvewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEZIERCURVEWINDOW_H
#define UI_BEZIERCURVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mycanvas.h"

QT_BEGIN_NAMESPACE

class Ui_BezierCurveWidget
{
public:
    QWidget *centralWidget;
    MyCanvas *myCanvas;
    QPushButton *pencilButton;
    QPushButton *sprayButton;
    QPushButton *lineButton;
    QPushButton *rectangleButton;
    QPushButton *clearButton;
    QSpinBox *rValueSpinBox;
    QSpinBox *gValueSpinBox;
    QSpinBox *bValueSpinBox;
    QLabel *brushColorLabel;
    QPushButton *circleButton;
    QPushButton *filledCircleButton;
    QPushButton *ellipseButton;
    QLabel *ellipseSlopeLabel;
    QSlider *ellipseSlopeSlider;
    QPushButton *bezierCurveButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BezierCurveWidget)
    {
        if (BezierCurveWidget->objectName().isEmpty())
            BezierCurveWidget->setObjectName(QStringLiteral("BezierCurveWidget"));
        BezierCurveWidget->resize(836, 746);
        centralWidget = new QWidget(BezierCurveWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        myCanvas = new MyCanvas(centralWidget);
        myCanvas->setObjectName(QStringLiteral("myCanvas"));
        myCanvas->setGeometry(QRect(19, 29, 650, 500));
        pencilButton = new QPushButton(centralWidget);
        pencilButton->setObjectName(QStringLiteral("pencilButton"));
        pencilButton->setGeometry(QRect(700, 30, 113, 32));
        sprayButton = new QPushButton(centralWidget);
        sprayButton->setObjectName(QStringLiteral("sprayButton"));
        sprayButton->setGeometry(QRect(700, 70, 113, 32));
        lineButton = new QPushButton(centralWidget);
        lineButton->setObjectName(QStringLiteral("lineButton"));
        lineButton->setGeometry(QRect(700, 110, 113, 32));
        rectangleButton = new QPushButton(centralWidget);
        rectangleButton->setObjectName(QStringLiteral("rectangleButton"));
        rectangleButton->setGeometry(QRect(700, 150, 113, 32));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(700, 310, 113, 32));
        rValueSpinBox = new QSpinBox(centralWidget);
        rValueSpinBox->setObjectName(QStringLiteral("rValueSpinBox"));
        rValueSpinBox->setGeometry(QRect(30, 540, 60, 25));
        rValueSpinBox->setMaximum(255);
        gValueSpinBox = new QSpinBox(centralWidget);
        gValueSpinBox->setObjectName(QStringLiteral("gValueSpinBox"));
        gValueSpinBox->setGeometry(QRect(100, 540, 60, 25));
        gValueSpinBox->setMaximum(255);
        bValueSpinBox = new QSpinBox(centralWidget);
        bValueSpinBox->setObjectName(QStringLiteral("bValueSpinBox"));
        bValueSpinBox->setGeometry(QRect(170, 540, 60, 25));
        bValueSpinBox->setMaximum(255);
        brushColorLabel = new QLabel(centralWidget);
        brushColorLabel->setObjectName(QStringLiteral("brushColorLabel"));
        brushColorLabel->setGeometry(QRect(240, 543, 141, 16));
        circleButton = new QPushButton(centralWidget);
        circleButton->setObjectName(QStringLiteral("circleButton"));
        circleButton->setGeometry(QRect(700, 190, 113, 32));
        filledCircleButton = new QPushButton(centralWidget);
        filledCircleButton->setObjectName(QStringLiteral("filledCircleButton"));
        filledCircleButton->setGeometry(QRect(700, 230, 113, 32));
        ellipseButton = new QPushButton(centralWidget);
        ellipseButton->setObjectName(QStringLiteral("ellipseButton"));
        ellipseButton->setGeometry(QRect(700, 270, 113, 32));
        ellipseSlopeLabel = new QLabel(centralWidget);
        ellipseSlopeLabel->setObjectName(QStringLiteral("ellipseSlopeLabel"));
        ellipseSlopeLabel->setGeometry(QRect(580, 580, 171, 16));
        ellipseSlopeSlider = new QSlider(centralWidget);
        ellipseSlopeSlider->setObjectName(QStringLiteral("ellipseSlopeSlider"));
        ellipseSlopeSlider->setGeometry(QRect(30, 580, 531, 22));
        ellipseSlopeSlider->setMaximum(360);
        ellipseSlopeSlider->setValue(0);
        ellipseSlopeSlider->setSliderPosition(0);
        ellipseSlopeSlider->setOrientation(Qt::Horizontal);
        bezierCurveButton = new QPushButton(centralWidget);
        bezierCurveButton->setObjectName(QStringLiteral("bezierCurveButton"));
        bezierCurveButton->setGeometry(QRect(692, 410, 121, 32));
        BezierCurveWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BezierCurveWidget);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 836, 22));
        BezierCurveWidget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BezierCurveWidget);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BezierCurveWidget->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BezierCurveWidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BezierCurveWidget->setStatusBar(statusBar);

        retranslateUi(BezierCurveWidget);

        QMetaObject::connectSlotsByName(BezierCurveWidget);
    } // setupUi

    void retranslateUi(QMainWindow *BezierCurveWidget)
    {
        BezierCurveWidget->setWindowTitle(QApplication::translate("BezierCurveWidget", "MainWindow", nullptr));
        pencilButton->setText(QApplication::translate("BezierCurveWidget", "O\305\202\303\263wek", nullptr));
        sprayButton->setText(QApplication::translate("BezierCurveWidget", "Spray", nullptr));
        lineButton->setText(QApplication::translate("BezierCurveWidget", "Linia", nullptr));
        rectangleButton->setText(QApplication::translate("BezierCurveWidget", "Prostok\304\205t", nullptr));
        clearButton->setText(QApplication::translate("BezierCurveWidget", "Wyczy\305\233\304\207", nullptr));
        brushColorLabel->setText(QApplication::translate("BezierCurveWidget", "<- Zmie\305\204 kolor p\304\231dzla", nullptr));
        circleButton->setText(QApplication::translate("BezierCurveWidget", "Okr\304\205g", nullptr));
        filledCircleButton->setText(QApplication::translate("BezierCurveWidget", "Ko\305\202o", nullptr));
        ellipseButton->setText(QApplication::translate("BezierCurveWidget", "Elipsa", nullptr));
        ellipseSlopeLabel->setText(QApplication::translate("BezierCurveWidget", "<- Zmie\305\204 nachylenie elipsy", nullptr));
        bezierCurveButton->setText(QApplication::translate("BezierCurveWidget", "Krzywe Beziera", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BezierCurveWidget: public Ui_BezierCurveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEZIERCURVEWINDOW_H
