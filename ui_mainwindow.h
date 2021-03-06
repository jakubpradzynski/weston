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
    QAction *morphologyOperationsAction;
    QAction *colorModelsAction;
    QAction *imageColorModelAction;
    QAction *blendModesAction;
    QAction *transformations2DAction;
    QAction *texturingAction;
    QAction *transformations3DAction;
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
    QPushButton *morphologyOperationsButton;
    QPushButton *colorModelsButton;
    QPushButton *blendModesButton;
    QPushButton *transformations2DButton;
    QPushButton *texturingButton;
    QPushButton *transformations3DButton;
    QMenuBar *menuBar;
    QMenu *curveMenu;
    QMenu *menuScaneLine;
    QMenu *menuOperacje_morfologiczne;
    QMenu *menuModele_barw;
    QMenu *menuBlend_modes;
    QMenu *menuTransformacje;
    QMenu *menuTexturing;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1180, 789);
        bezierCurveAction = new QAction(MainWindow);
        bezierCurveAction->setObjectName(QStringLiteral("bezierCurveAction"));
        bSplineCurveAction = new QAction(MainWindow);
        bSplineCurveAction->setObjectName(QStringLiteral("bSplineCurveAction"));
        scaneLineAction = new QAction(MainWindow);
        scaneLineAction->setObjectName(QStringLiteral("scaneLineAction"));
        morphologyOperationsAction = new QAction(MainWindow);
        morphologyOperationsAction->setObjectName(QStringLiteral("morphologyOperationsAction"));
        colorModelsAction = new QAction(MainWindow);
        colorModelsAction->setObjectName(QStringLiteral("colorModelsAction"));
        imageColorModelAction = new QAction(MainWindow);
        imageColorModelAction->setObjectName(QStringLiteral("imageColorModelAction"));
        blendModesAction = new QAction(MainWindow);
        blendModesAction->setObjectName(QStringLiteral("blendModesAction"));
        transformations2DAction = new QAction(MainWindow);
        transformations2DAction->setObjectName(QStringLiteral("transformations2DAction"));
        texturingAction = new QAction(MainWindow);
        texturingAction->setObjectName(QStringLiteral("texturingAction"));
        transformations3DAction = new QAction(MainWindow);
        transformations3DAction->setObjectName(QStringLiteral("transformations3DAction"));
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
        scaneLineButton->setGeometry(QRect(340, 620, 113, 32));
        morphologyOperationsButton = new QPushButton(centralWidget);
        morphologyOperationsButton->setObjectName(QStringLiteral("morphologyOperationsButton"));
        morphologyOperationsButton->setGeometry(QRect(460, 620, 181, 32));
        colorModelsButton = new QPushButton(centralWidget);
        colorModelsButton->setObjectName(QStringLiteral("colorModelsButton"));
        colorModelsButton->setGeometry(QRect(650, 620, 141, 31));
        blendModesButton = new QPushButton(centralWidget);
        blendModesButton->setObjectName(QStringLiteral("blendModesButton"));
        blendModesButton->setGeometry(QRect(800, 620, 141, 31));
        transformations2DButton = new QPushButton(centralWidget);
        transformations2DButton->setObjectName(QStringLiteral("transformations2DButton"));
        transformations2DButton->setGeometry(QRect(950, 620, 141, 31));
        texturingButton = new QPushButton(centralWidget);
        texturingButton->setObjectName(QStringLiteral("texturingButton"));
        texturingButton->setGeometry(QRect(30, 670, 141, 31));
        transformations3DButton = new QPushButton(centralWidget);
        transformations3DButton->setObjectName(QStringLiteral("transformations3DButton"));
        transformations3DButton->setGeometry(QRect(180, 670, 141, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1180, 21));
        curveMenu = new QMenu(menuBar);
        curveMenu->setObjectName(QStringLiteral("curveMenu"));
        menuScaneLine = new QMenu(menuBar);
        menuScaneLine->setObjectName(QStringLiteral("menuScaneLine"));
        menuOperacje_morfologiczne = new QMenu(menuBar);
        menuOperacje_morfologiczne->setObjectName(QStringLiteral("menuOperacje_morfologiczne"));
        menuModele_barw = new QMenu(menuBar);
        menuModele_barw->setObjectName(QStringLiteral("menuModele_barw"));
        menuBlend_modes = new QMenu(menuBar);
        menuBlend_modes->setObjectName(QStringLiteral("menuBlend_modes"));
        menuTransformacje = new QMenu(menuBar);
        menuTransformacje->setObjectName(QStringLiteral("menuTransformacje"));
        menuTexturing = new QMenu(menuBar);
        menuTexturing->setObjectName(QStringLiteral("menuTexturing"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(curveMenu->menuAction());
        menuBar->addAction(menuScaneLine->menuAction());
        menuBar->addAction(menuOperacje_morfologiczne->menuAction());
        menuBar->addAction(menuModele_barw->menuAction());
        menuBar->addAction(menuBlend_modes->menuAction());
        menuBar->addAction(menuTransformacje->menuAction());
        menuBar->addAction(menuTexturing->menuAction());
        curveMenu->addAction(bezierCurveAction);
        curveMenu->addAction(bSplineCurveAction);
        menuScaneLine->addAction(scaneLineAction);
        menuOperacje_morfologiczne->addAction(morphologyOperationsAction);
        menuModele_barw->addAction(colorModelsAction);
        menuModele_barw->addAction(imageColorModelAction);
        menuBlend_modes->addAction(blendModesAction);
        menuTransformacje->addAction(transformations2DAction);
        menuTransformacje->addAction(transformations3DAction);
        menuTexturing->addAction(texturingAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        bezierCurveAction->setText(QApplication::translate("MainWindow", "Beziera", nullptr));
        bSplineCurveAction->setText(QApplication::translate("MainWindow", "B-sklejone", nullptr));
        scaneLineAction->setText(QApplication::translate("MainWindow", "Uruchom", nullptr));
        morphologyOperationsAction->setText(QApplication::translate("MainWindow", "Uruchom", nullptr));
        colorModelsAction->setText(QApplication::translate("MainWindow", "Uruchom", nullptr));
        imageColorModelAction->setText(QApplication::translate("MainWindow", "Na obrazku", nullptr));
        blendModesAction->setText(QApplication::translate("MainWindow", "Uruchom", nullptr));
        transformations2DAction->setText(QApplication::translate("MainWindow", "2D", nullptr));
        texturingAction->setText(QApplication::translate("MainWindow", "Uruchom", nullptr));
        transformations3DAction->setText(QApplication::translate("MainWindow", "3D", nullptr));
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
        morphologyOperationsButton->setText(QApplication::translate("MainWindow", "Operacje morfologiczne", nullptr));
        colorModelsButton->setText(QApplication::translate("MainWindow", "Modele barw", nullptr));
        blendModesButton->setText(QApplication::translate("MainWindow", "Blend modes", nullptr));
        transformations2DButton->setText(QApplication::translate("MainWindow", "Transformacje 2D", nullptr));
        texturingButton->setText(QApplication::translate("MainWindow", "Teksturowanie", nullptr));
        transformations3DButton->setText(QApplication::translate("MainWindow", "Transformacje 3D", nullptr));
        curveMenu->setTitle(QApplication::translate("MainWindow", "Krzywe", nullptr));
        menuScaneLine->setTitle(QApplication::translate("MainWindow", "ScanLine", nullptr));
        menuOperacje_morfologiczne->setTitle(QApplication::translate("MainWindow", "Operacje morfologiczne", nullptr));
        menuModele_barw->setTitle(QApplication::translate("MainWindow", "Modele barw", nullptr));
        menuBlend_modes->setTitle(QApplication::translate("MainWindow", "Blend modes", nullptr));
        menuTransformacje->setTitle(QApplication::translate("MainWindow", "Transformacje", nullptr));
        menuTexturing->setTitle(QApplication::translate("MainWindow", "Texturing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
