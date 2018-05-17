/********************************************************************************
** Form generated from reading UI file 'blendmodeswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLENDMODESWIDGET_H
#define UI_BLENDMODESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "blendmodescanvas.h"

QT_BEGIN_NAMESPACE

class Ui_BlendModesWidget
{
public:
    BlendModesCanvas *blendModesCanvas;
    QPushButton *layerOneButton;
    QPushButton *layerTwoButton;
    QPushButton *layerThreeButton;
    QSlider *alphaBlendingSlider;
    QPushButton *clearButton;
    QSlider *alphaBlendingForThreeLayersSlider;
    QPushButton *multiplyButton;
    QPushButton *screenButton;
    QPushButton *overlayButton;
    QPushButton *darkenButton;
    QPushButton *lightenButton;
    QLabel *blendingModesLabel;
    QPushButton *differenceButton;
    QPushButton *additiveButton;
    QPushButton *subtractiveButton;
    QLabel *blendingModesForThreeLayersLabel;
    QPushButton *lightenForThreeLayersButton;
    QPushButton *differenceForThreeLayersButton;
    QPushButton *subtractiveForThreeLayersButton;
    QPushButton *darkenForThreeLayersButton;
    QPushButton *additiveForThreeLayersButton;
    QPushButton *multiplyForThreeLayersButton;
    QPushButton *overlayForThreeLayersButton;
    QPushButton *screenForThreeLayersButton;

    void setupUi(QWidget *BlendModesWidget)
    {
        if (BlendModesWidget->objectName().isEmpty())
            BlendModesWidget->setObjectName(QStringLiteral("BlendModesWidget"));
        BlendModesWidget->resize(1284, 827);
        blendModesCanvas = new BlendModesCanvas(BlendModesWidget);
        blendModesCanvas->setObjectName(QStringLiteral("blendModesCanvas"));
        blendModesCanvas->setGeometry(QRect(50, 40, 611, 561));
        layerOneButton = new QPushButton(BlendModesWidget);
        layerOneButton->setObjectName(QStringLiteral("layerOneButton"));
        layerOneButton->setGeometry(QRect(800, 40, 111, 31));
        layerTwoButton = new QPushButton(BlendModesWidget);
        layerTwoButton->setObjectName(QStringLiteral("layerTwoButton"));
        layerTwoButton->setGeometry(QRect(800, 80, 111, 31));
        layerThreeButton = new QPushButton(BlendModesWidget);
        layerThreeButton->setObjectName(QStringLiteral("layerThreeButton"));
        layerThreeButton->setGeometry(QRect(800, 120, 111, 31));
        alphaBlendingSlider = new QSlider(BlendModesWidget);
        alphaBlendingSlider->setObjectName(QStringLiteral("alphaBlendingSlider"));
        alphaBlendingSlider->setGeometry(QRect(730, 590, 251, 22));
        alphaBlendingSlider->setMaximum(100);
        alphaBlendingSlider->setOrientation(Qt::Horizontal);
        clearButton = new QPushButton(BlendModesWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(800, 160, 111, 31));
        alphaBlendingForThreeLayersSlider = new QSlider(BlendModesWidget);
        alphaBlendingForThreeLayersSlider->setObjectName(QStringLiteral("alphaBlendingForThreeLayersSlider"));
        alphaBlendingForThreeLayersSlider->setGeometry(QRect(990, 590, 251, 22));
        alphaBlendingForThreeLayersSlider->setMaximum(100);
        alphaBlendingForThreeLayersSlider->setOrientation(Qt::Horizontal);
        multiplyButton = new QPushButton(BlendModesWidget);
        multiplyButton->setObjectName(QStringLiteral("multiplyButton"));
        multiplyButton->setGeometry(QRect(820, 260, 111, 31));
        screenButton = new QPushButton(BlendModesWidget);
        screenButton->setObjectName(QStringLiteral("screenButton"));
        screenButton->setGeometry(QRect(820, 300, 111, 31));
        overlayButton = new QPushButton(BlendModesWidget);
        overlayButton->setObjectName(QStringLiteral("overlayButton"));
        overlayButton->setGeometry(QRect(820, 340, 111, 31));
        darkenButton = new QPushButton(BlendModesWidget);
        darkenButton->setObjectName(QStringLiteral("darkenButton"));
        darkenButton->setGeometry(QRect(820, 380, 111, 31));
        lightenButton = new QPushButton(BlendModesWidget);
        lightenButton->setObjectName(QStringLiteral("lightenButton"));
        lightenButton->setGeometry(QRect(820, 420, 111, 31));
        blendingModesLabel = new QLabel(BlendModesWidget);
        blendingModesLabel->setObjectName(QStringLiteral("blendingModesLabel"));
        blendingModesLabel->setGeometry(QRect(810, 230, 141, 20));
        differenceButton = new QPushButton(BlendModesWidget);
        differenceButton->setObjectName(QStringLiteral("differenceButton"));
        differenceButton->setGeometry(QRect(820, 460, 111, 31));
        additiveButton = new QPushButton(BlendModesWidget);
        additiveButton->setObjectName(QStringLiteral("additiveButton"));
        additiveButton->setGeometry(QRect(820, 500, 111, 31));
        subtractiveButton = new QPushButton(BlendModesWidget);
        subtractiveButton->setObjectName(QStringLiteral("subtractiveButton"));
        subtractiveButton->setGeometry(QRect(820, 540, 111, 31));
        blendingModesForThreeLayersLabel = new QLabel(BlendModesWidget);
        blendingModesForThreeLayersLabel->setObjectName(QStringLiteral("blendingModesForThreeLayersLabel"));
        blendingModesForThreeLayersLabel->setGeometry(QRect(1040, 230, 141, 20));
        lightenForThreeLayersButton = new QPushButton(BlendModesWidget);
        lightenForThreeLayersButton->setObjectName(QStringLiteral("lightenForThreeLayersButton"));
        lightenForThreeLayersButton->setGeometry(QRect(1050, 420, 111, 31));
        differenceForThreeLayersButton = new QPushButton(BlendModesWidget);
        differenceForThreeLayersButton->setObjectName(QStringLiteral("differenceForThreeLayersButton"));
        differenceForThreeLayersButton->setGeometry(QRect(1050, 460, 111, 31));
        subtractiveForThreeLayersButton = new QPushButton(BlendModesWidget);
        subtractiveForThreeLayersButton->setObjectName(QStringLiteral("subtractiveForThreeLayersButton"));
        subtractiveForThreeLayersButton->setGeometry(QRect(1050, 540, 111, 31));
        darkenForThreeLayersButton = new QPushButton(BlendModesWidget);
        darkenForThreeLayersButton->setObjectName(QStringLiteral("darkenForThreeLayersButton"));
        darkenForThreeLayersButton->setGeometry(QRect(1050, 380, 111, 31));
        additiveForThreeLayersButton = new QPushButton(BlendModesWidget);
        additiveForThreeLayersButton->setObjectName(QStringLiteral("additiveForThreeLayersButton"));
        additiveForThreeLayersButton->setGeometry(QRect(1050, 500, 111, 31));
        multiplyForThreeLayersButton = new QPushButton(BlendModesWidget);
        multiplyForThreeLayersButton->setObjectName(QStringLiteral("multiplyForThreeLayersButton"));
        multiplyForThreeLayersButton->setGeometry(QRect(1050, 260, 111, 31));
        overlayForThreeLayersButton = new QPushButton(BlendModesWidget);
        overlayForThreeLayersButton->setObjectName(QStringLiteral("overlayForThreeLayersButton"));
        overlayForThreeLayersButton->setGeometry(QRect(1050, 340, 111, 31));
        screenForThreeLayersButton = new QPushButton(BlendModesWidget);
        screenForThreeLayersButton->setObjectName(QStringLiteral("screenForThreeLayersButton"));
        screenForThreeLayersButton->setGeometry(QRect(1050, 300, 111, 31));

        retranslateUi(BlendModesWidget);

        QMetaObject::connectSlotsByName(BlendModesWidget);
    } // setupUi

    void retranslateUi(QWidget *BlendModesWidget)
    {
        BlendModesWidget->setWindowTitle(QApplication::translate("BlendModesWidget", "Form", nullptr));
        layerOneButton->setText(QApplication::translate("BlendModesWidget", "Warstwa 1", nullptr));
        layerTwoButton->setText(QApplication::translate("BlendModesWidget", "Warstwa 2", nullptr));
        layerThreeButton->setText(QApplication::translate("BlendModesWidget", "Warstwa 3", nullptr));
        clearButton->setText(QApplication::translate("BlendModesWidget", "Wyczy\305\233\304\207", nullptr));
        multiplyButton->setText(QApplication::translate("BlendModesWidget", "Multiply", nullptr));
        screenButton->setText(QApplication::translate("BlendModesWidget", "Screen", nullptr));
        overlayButton->setText(QApplication::translate("BlendModesWidget", "Overlay", nullptr));
        darkenButton->setText(QApplication::translate("BlendModesWidget", "Darken", nullptr));
        lightenButton->setText(QApplication::translate("BlendModesWidget", "Lighten", nullptr));
        blendingModesLabel->setText(QApplication::translate("BlendModesWidget", "Blending modes for 2 layers", nullptr));
        differenceButton->setText(QApplication::translate("BlendModesWidget", "Difference", nullptr));
        additiveButton->setText(QApplication::translate("BlendModesWidget", "Additive", nullptr));
        subtractiveButton->setText(QApplication::translate("BlendModesWidget", "Subtractive", nullptr));
        blendingModesForThreeLayersLabel->setText(QApplication::translate("BlendModesWidget", "Blending modes for 3 layers", nullptr));
        lightenForThreeLayersButton->setText(QApplication::translate("BlendModesWidget", "Lighten", nullptr));
        differenceForThreeLayersButton->setText(QApplication::translate("BlendModesWidget", "Difference", nullptr));
        subtractiveForThreeLayersButton->setText(QApplication::translate("BlendModesWidget", "Subtractive", nullptr));
        darkenForThreeLayersButton->setText(QApplication::translate("BlendModesWidget", "Darken", nullptr));
        additiveForThreeLayersButton->setText(QApplication::translate("BlendModesWidget", "Additive", nullptr));
        multiplyForThreeLayersButton->setText(QApplication::translate("BlendModesWidget", "Multiply", nullptr));
        overlayForThreeLayersButton->setText(QApplication::translate("BlendModesWidget", "Overlay", nullptr));
        screenForThreeLayersButton->setText(QApplication::translate("BlendModesWidget", "Screen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlendModesWidget: public Ui_BlendModesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLENDMODESWIDGET_H
