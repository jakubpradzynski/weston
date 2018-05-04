/********************************************************************************
** Form generated from reading UI file 'colormodelswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORMODELSWIDGET_H
#define UI_COLORMODELSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "colormodelcanvas.h"

QT_BEGIN_NAMESPACE

class Ui_ColorModelsWidget
{
public:
    ColorModelCanvas *colorModelCanvas;
    QSlider *rValueSlider;
    QLabel *rLabel;
    QLabel *gLabel;
    QSlider *gValueSlider;
    QLabel *bLabel;
    QSlider *bValueSlider;
    QLabel *hLabel;
    QSlider *hValueSlider;
    QLabel *sLabel;
    QSlider *sValueSlider;
    QLabel *vLabel;
    QSlider *vValueSlider;
    QLabel *rValue;
    QLabel *gValue;
    QLabel *bValue;
    QLabel *hValue;
    QLabel *sValue;
    QLabel *vValue;

    void setupUi(QWidget *ColorModelsWidget)
    {
        if (ColorModelsWidget->objectName().isEmpty())
            ColorModelsWidget->setObjectName(QStringLiteral("ColorModelsWidget"));
        ColorModelsWidget->resize(993, 615);
        colorModelCanvas = new ColorModelCanvas(ColorModelsWidget);
        colorModelCanvas->setObjectName(QStringLiteral("colorModelCanvas"));
        colorModelCanvas->setGeometry(QRect(50, 50, 421, 331));
        rValueSlider = new QSlider(ColorModelsWidget);
        rValueSlider->setObjectName(QStringLiteral("rValueSlider"));
        rValueSlider->setGeometry(QRect(550, 70, 160, 22));
        rValueSlider->setMaximum(255);
        rValueSlider->setOrientation(Qt::Horizontal);
        rLabel = new QLabel(ColorModelsWidget);
        rLabel->setObjectName(QStringLiteral("rLabel"));
        rLabel->setGeometry(QRect(550, 50, 81, 16));
        gLabel = new QLabel(ColorModelsWidget);
        gLabel->setObjectName(QStringLiteral("gLabel"));
        gLabel->setGeometry(QRect(550, 100, 81, 16));
        gValueSlider = new QSlider(ColorModelsWidget);
        gValueSlider->setObjectName(QStringLiteral("gValueSlider"));
        gValueSlider->setGeometry(QRect(550, 120, 160, 22));
        gValueSlider->setMaximum(255);
        gValueSlider->setOrientation(Qt::Horizontal);
        bLabel = new QLabel(ColorModelsWidget);
        bLabel->setObjectName(QStringLiteral("bLabel"));
        bLabel->setGeometry(QRect(550, 150, 81, 16));
        bValueSlider = new QSlider(ColorModelsWidget);
        bValueSlider->setObjectName(QStringLiteral("bValueSlider"));
        bValueSlider->setGeometry(QRect(550, 170, 160, 22));
        bValueSlider->setMaximum(255);
        bValueSlider->setOrientation(Qt::Horizontal);
        hLabel = new QLabel(ColorModelsWidget);
        hLabel->setObjectName(QStringLiteral("hLabel"));
        hLabel->setGeometry(QRect(550, 220, 81, 16));
        hValueSlider = new QSlider(ColorModelsWidget);
        hValueSlider->setObjectName(QStringLiteral("hValueSlider"));
        hValueSlider->setGeometry(QRect(550, 240, 160, 22));
        hValueSlider->setMaximum(359);
        hValueSlider->setOrientation(Qt::Horizontal);
        sLabel = new QLabel(ColorModelsWidget);
        sLabel->setObjectName(QStringLiteral("sLabel"));
        sLabel->setGeometry(QRect(550, 270, 81, 16));
        sValueSlider = new QSlider(ColorModelsWidget);
        sValueSlider->setObjectName(QStringLiteral("sValueSlider"));
        sValueSlider->setGeometry(QRect(550, 290, 160, 22));
        sValueSlider->setMaximum(100);
        sValueSlider->setOrientation(Qt::Horizontal);
        vLabel = new QLabel(ColorModelsWidget);
        vLabel->setObjectName(QStringLiteral("vLabel"));
        vLabel->setGeometry(QRect(550, 320, 81, 16));
        vValueSlider = new QSlider(ColorModelsWidget);
        vValueSlider->setObjectName(QStringLiteral("vValueSlider"));
        vValueSlider->setGeometry(QRect(550, 340, 160, 22));
        vValueSlider->setMaximum(100);
        vValueSlider->setOrientation(Qt::Horizontal);
        rValue = new QLabel(ColorModelsWidget);
        rValue->setObjectName(QStringLiteral("rValue"));
        rValue->setGeometry(QRect(650, 50, 81, 16));
        gValue = new QLabel(ColorModelsWidget);
        gValue->setObjectName(QStringLiteral("gValue"));
        gValue->setGeometry(QRect(650, 100, 81, 16));
        bValue = new QLabel(ColorModelsWidget);
        bValue->setObjectName(QStringLiteral("bValue"));
        bValue->setGeometry(QRect(650, 150, 81, 16));
        hValue = new QLabel(ColorModelsWidget);
        hValue->setObjectName(QStringLiteral("hValue"));
        hValue->setGeometry(QRect(650, 220, 81, 16));
        sValue = new QLabel(ColorModelsWidget);
        sValue->setObjectName(QStringLiteral("sValue"));
        sValue->setGeometry(QRect(650, 270, 81, 16));
        vValue = new QLabel(ColorModelsWidget);
        vValue->setObjectName(QStringLiteral("vValue"));
        vValue->setGeometry(QRect(650, 320, 81, 16));

        retranslateUi(ColorModelsWidget);

        QMetaObject::connectSlotsByName(ColorModelsWidget);
    } // setupUi

    void retranslateUi(QWidget *ColorModelsWidget)
    {
        ColorModelsWidget->setWindowTitle(QApplication::translate("ColorModelsWidget", "Form", nullptr));
        rLabel->setText(QApplication::translate("ColorModelsWidget", "Warto\305\233\304\207 R", nullptr));
        gLabel->setText(QApplication::translate("ColorModelsWidget", "Warto\305\233\304\207 G", nullptr));
        bLabel->setText(QApplication::translate("ColorModelsWidget", "Warto\305\233\304\207 B", nullptr));
        hLabel->setText(QApplication::translate("ColorModelsWidget", "Warto\305\233\304\207 H", nullptr));
        sLabel->setText(QApplication::translate("ColorModelsWidget", "Warto\305\233\304\207 S", nullptr));
        vLabel->setText(QApplication::translate("ColorModelsWidget", "Warto\305\233\304\207 V", nullptr));
        rValue->setText(QApplication::translate("ColorModelsWidget", "0", nullptr));
        gValue->setText(QApplication::translate("ColorModelsWidget", "0", nullptr));
        bValue->setText(QApplication::translate("ColorModelsWidget", "0", nullptr));
        hValue->setText(QApplication::translate("ColorModelsWidget", "0", nullptr));
        sValue->setText(QApplication::translate("ColorModelsWidget", "0", nullptr));
        vValue->setText(QApplication::translate("ColorModelsWidget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorModelsWidget: public Ui_ColorModelsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORMODELSWIDGET_H
