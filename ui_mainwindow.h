/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mycanvas.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *bezierCurveAction;
    QAction *bSplineCurveAction;
    QAction *scaneLineAction;
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
    QPushButton *bSplineCurveButton;
    QPushButton *floodFillButton;
    QPushButton *scaneLineButton;
    QMenuBar *menuBar;
    QMenu *curveMenu;
    QMenu *menuScaneLine;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(850, 750);
        bezierCurveAction = new QAction(MainWindow);
        bezierCurveAction->setObjectName(QStringLiteral("bezierCurveAction"));
        bSplineCurveAction = new QAction(MainWindow);
        bSplineCurveAction->setObjectName(QStringLiteral("bSplineCurveAction"));
        scaneLineAction = new QAction(MainWindow);
        scaneLineAction->setObjectName(QStringLiteral("scaneLineAction"));
        centralWidget = new QWidget(MainWindow);
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
        clearButton->setGeometry(QRect(700, 350, 113, 32));
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
        bezierCurveButton->setGeometry(QRect(30, 620, 141, 32));
        bSplineCurveButton = new QPushButton(centralWidget);
        bSplineCurveButton->setObjectName(QStringLiteral("bSplineCurveButton"));
        bSplineCurveButton->setGeometry(QRect(180, 620, 151, 32));
        floodFillButton = new QPushButton(centralWidget);
        floodFillButton->setObjectName(QStringLiteral("floodFillButton"));
        floodFillButton->setGeometry(QRect(700, 310, 113, 32));
        scaneLineButton = new QPushButton(centralWidget);
        scaneLineButton->setObjectName(QStringLiteral("scaneLineButton"));
        scaneLineButton->setGeometry(QRect(350, 620, 113, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 22));
        curveMenu = new QMenu(menuBar);
        curveMenu->setObjectName(QStringLiteral("curveMenu"));
        menuScaneLine = new QMenu(menuBar);
        menuScaneLine->setObjectName(QStringLiteral("menuScaneLine"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(curveMenu->menuAction());
        menuBar->addAction(menuScaneLine->menuAction());
        curveMenu->addAction(bezierCurveAction);
        curveMenu->addAction(bSplineCurveAction);
        menuScaneLine->addAction(scaneLineAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        bezierCurveAction->setText(QApplication::translate("MainWindow", "Beziera", nullptr));
        bSplineCurveAction->setText(QApplication::translate("MainWindow", "B-sklejone", nullptr));
        scaneLineAction->setText(QApplication::translate("MainWindow", "Uruchom", nullptr));
        pencilButton->setText(QApplication::translate("MainWindow", "O\305\202\303\263wek", nullptr));
        sprayButton->setText(QApplication::translate("MainWindow", "Spray", nullptr));
        lineButton->setText(QApplication::translate("MainWindow", "Linia", nullptr));
        rectangleButton->setText(QApplication::translate("MainWindow", "Prostok\304\205t", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "Wyczy\305\233\304\207", nullptr));
        brushColorLabel->setText(QApplication::translate("MainWindow", "<- Zmie\305\204 kolor p\304\231dzla", nullptr));
        circleButton->setText(QApplication::translate("MainWindow", "Okr\304\205g", nullptr));
        filledCircleButton->setText(QApplication::translate("MainWindow", "Ko\305\202o", nullptr));
        ellipseButton->setText(QApplication::translate("MainWindow", "Elipsa", nullptr));
        ellipseSlopeLabel->setText(QApplication::translate("MainWindow", "<- Zmie\305\204 nachylenie elipsy", nullptr));
        bezierCurveButton->setText(QApplication::translate("MainWindow", "Krzywe Beziera", nullptr));
        bSplineCurveButton->setText(QApplication::translate("MainWindow", "Krzywe B-sklejane", nullptr));
        floodFillButton->setText(QApplication::translate("MainWindow", "Wype\305\202nij", nullptr));
        scaneLineButton->setText(QApplication::translate("MainWindow", "ScanLine", nullptr));
        curveMenu->setTitle(QApplication::translate("MainWindow", "Krzywe", nullptr));
        menuScaneLine->setTitle(QApplication::translate("MainWindow", "ScanLine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
