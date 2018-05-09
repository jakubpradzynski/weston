/********************************************************************************
** Form generated from reading UI file 'imagecolormodelwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGECOLORMODELWIDGET_H
#define UI_IMAGECOLORMODELWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "imagecolormodelcanvas.h"

QT_BEGIN_NAMESPACE

class Ui_ImageColorModelWidget
{
public:
    QLabel *hLabel;
    QLabel *sLabel;
    QLabel *vLabel;
    QLabel *vValue;
    QSlider *hValueSlider;
    QSlider *vValueSlider;
    ImageColorModelCanvas *colorModelCanvas;
    QSlider *sValueSlider;
    QLabel *hValue;
    QLabel *sValue;

    void setupUi(QWidget *ImageColorModelWidget)
    {
        if (ImageColorModelWidget->objectName().isEmpty())
            ImageColorModelWidget->setObjectName(QStringLiteral("ImageColorModelWidget"));
        ImageColorModelWidget->resize(1000, 624);
        hLabel = new QLabel(ImageColorModelWidget);
        hLabel->setObjectName(QStringLiteral("hLabel"));
        hLabel->setGeometry(QRect(600, 120, 81, 16));
        sLabel = new QLabel(ImageColorModelWidget);
        sLabel->setObjectName(QStringLiteral("sLabel"));
        sLabel->setGeometry(QRect(600, 170, 81, 16));
        vLabel = new QLabel(ImageColorModelWidget);
        vLabel->setObjectName(QStringLiteral("vLabel"));
        vLabel->setGeometry(QRect(600, 220, 81, 16));
        vValue = new QLabel(ImageColorModelWidget);
        vValue->setObjectName(QStringLiteral("vValue"));
        vValue->setGeometry(QRect(700, 220, 81, 16));
        hValueSlider = new QSlider(ImageColorModelWidget);
        hValueSlider->setObjectName(QStringLiteral("hValueSlider"));
        hValueSlider->setGeometry(QRect(600, 140, 291, 22));
        hValueSlider->setMinimum(-359);
        hValueSlider->setMaximum(359);
        hValueSlider->setOrientation(Qt::Horizontal);
        vValueSlider = new QSlider(ImageColorModelWidget);
        vValueSlider->setObjectName(QStringLiteral("vValueSlider"));
        vValueSlider->setGeometry(QRect(600, 240, 291, 22));
        vValueSlider->setMinimum(-100);
        vValueSlider->setMaximum(100);
        vValueSlider->setOrientation(Qt::Horizontal);
        colorModelCanvas = new ImageColorModelCanvas(ImageColorModelWidget);
        colorModelCanvas->setObjectName(QStringLiteral("colorModelCanvas"));
        colorModelCanvas->setGeometry(QRect(20, 20, 551, 561));
        sValueSlider = new QSlider(ImageColorModelWidget);
        sValueSlider->setObjectName(QStringLiteral("sValueSlider"));
        sValueSlider->setGeometry(QRect(600, 190, 291, 22));
        sValueSlider->setMinimum(-100);
        sValueSlider->setMaximum(100);
        sValueSlider->setOrientation(Qt::Horizontal);
        hValue = new QLabel(ImageColorModelWidget);
        hValue->setObjectName(QStringLiteral("hValue"));
        hValue->setGeometry(QRect(700, 120, 81, 16));
        sValue = new QLabel(ImageColorModelWidget);
        sValue->setObjectName(QStringLiteral("sValue"));
        sValue->setGeometry(QRect(700, 170, 81, 16));

        retranslateUi(ImageColorModelWidget);

        QMetaObject::connectSlotsByName(ImageColorModelWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageColorModelWidget)
    {
        ImageColorModelWidget->setWindowTitle(QApplication::translate("ImageColorModelWidget", "Form", nullptr));
        hLabel->setText(QApplication::translate("ImageColorModelWidget", "Warto\305\233\304\207 H", nullptr));
        sLabel->setText(QApplication::translate("ImageColorModelWidget", "Warto\305\233\304\207 S", nullptr));
        vLabel->setText(QApplication::translate("ImageColorModelWidget", "Warto\305\233\304\207 V", nullptr));
        vValue->setText(QApplication::translate("ImageColorModelWidget", "0", nullptr));
        hValue->setText(QApplication::translate("ImageColorModelWidget", "0", nullptr));
        sValue->setText(QApplication::translate("ImageColorModelWidget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageColorModelWidget: public Ui_ImageColorModelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGECOLORMODELWIDGET_H
