/********************************************************************************
** Form generated from reading UI file 'transformations2dwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMATIONS2DWIDGET_H
#define UI_TRANSFORMATIONS2DWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "transformations2dcanvas.h"

QT_BEGIN_NAMESPACE

class Ui_Transformations2DWidget
{
public:
    Transformations2DCanvas *transformations2DCanvas;
    QLabel *rotation;
    QSlider *alphaRotationSlider;
    QLabel *alphaRotationLabel;
    QLabel *scaling;
    QSlider *xScalingSlider;
    QLabel *xScalingLabel;
    QLabel *translation;
    QSlider *xTranslationSlider;
    QLabel *yTranslationLabel;
    QSlider *yTranslationSlider;
    QLabel *xTranslationLabel;
    QLabel *yShearingLabel;
    QSlider *xShearingSlider;
    QSlider *yShearingSlider;
    QLabel *xShearingLabel;
    QLabel *shearing;
    QSlider *yScalingSlider;
    QLabel *yScalingLabel;

    void setupUi(QWidget *Transformations2DWidget)
    {
        if (Transformations2DWidget->objectName().isEmpty())
            Transformations2DWidget->setObjectName(QStringLiteral("Transformations2DWidget"));
        Transformations2DWidget->resize(1070, 684);
        transformations2DCanvas = new Transformations2DCanvas(Transformations2DWidget);
        transformations2DCanvas->setObjectName(QStringLiteral("transformations2DCanvas"));
        transformations2DCanvas->setGeometry(QRect(10, 10, 701, 641));
        rotation = new QLabel(Transformations2DWidget);
        rotation->setObjectName(QStringLiteral("rotation"));
        rotation->setGeometry(QRect(740, 23, 47, 20));
        rotation->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        alphaRotationSlider = new QSlider(Transformations2DWidget);
        alphaRotationSlider->setObjectName(QStringLiteral("alphaRotationSlider"));
        alphaRotationSlider->setGeometry(QRect(740, 50, 160, 22));
        alphaRotationSlider->setMinimum(-90);
        alphaRotationSlider->setMaximum(90);
        alphaRotationSlider->setOrientation(Qt::Horizontal);
        alphaRotationLabel = new QLabel(Transformations2DWidget);
        alphaRotationLabel->setObjectName(QStringLiteral("alphaRotationLabel"));
        alphaRotationLabel->setGeometry(QRect(920, 46, 51, 21));
        alphaRotationLabel->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        alphaRotationLabel->setLineWidth(2);
        scaling = new QLabel(Transformations2DWidget);
        scaling->setObjectName(QStringLiteral("scaling"));
        scaling->setGeometry(QRect(740, 106, 111, 20));
        scaling->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        xScalingSlider = new QSlider(Transformations2DWidget);
        xScalingSlider->setObjectName(QStringLiteral("xScalingSlider"));
        xScalingSlider->setGeometry(QRect(740, 130, 160, 22));
        xScalingSlider->setMaximum(10);
        xScalingSlider->setValue(1);
        xScalingSlider->setOrientation(Qt::Horizontal);
        xScalingLabel = new QLabel(Transformations2DWidget);
        xScalingLabel->setObjectName(QStringLiteral("xScalingLabel"));
        xScalingLabel->setGeometry(QRect(920, 130, 47, 13));
        xScalingLabel->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        xScalingLabel->setLineWidth(2);
        translation = new QLabel(Transformations2DWidget);
        translation->setObjectName(QStringLiteral("translation"));
        translation->setGeometry(QRect(740, 220, 101, 21));
        translation->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        xTranslationSlider = new QSlider(Transformations2DWidget);
        xTranslationSlider->setObjectName(QStringLiteral("xTranslationSlider"));
        xTranslationSlider->setGeometry(QRect(740, 245, 160, 21));
        xTranslationSlider->setMaximum(300);
        xTranslationSlider->setOrientation(Qt::Horizontal);
        yTranslationLabel = new QLabel(Transformations2DWidget);
        yTranslationLabel->setObjectName(QStringLiteral("yTranslationLabel"));
        yTranslationLabel->setGeometry(QRect(920, 275, 47, 13));
        yTranslationLabel->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        yTranslationSlider = new QSlider(Transformations2DWidget);
        yTranslationSlider->setObjectName(QStringLiteral("yTranslationSlider"));
        yTranslationSlider->setGeometry(QRect(740, 275, 160, 22));
        yTranslationSlider->setMaximum(300);
        yTranslationSlider->setOrientation(Qt::Horizontal);
        xTranslationLabel = new QLabel(Transformations2DWidget);
        xTranslationLabel->setObjectName(QStringLiteral("xTranslationLabel"));
        xTranslationLabel->setGeometry(QRect(920, 245, 47, 13));
        xTranslationLabel->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        xTranslationLabel->setLineWidth(2);
        yShearingLabel = new QLabel(Transformations2DWidget);
        yShearingLabel->setObjectName(QStringLiteral("yShearingLabel"));
        yShearingLabel->setGeometry(QRect(920, 385, 47, 13));
        yShearingLabel->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        xShearingSlider = new QSlider(Transformations2DWidget);
        xShearingSlider->setObjectName(QStringLiteral("xShearingSlider"));
        xShearingSlider->setGeometry(QRect(740, 355, 160, 21));
        xShearingSlider->setMaximum(10);
        xShearingSlider->setOrientation(Qt::Horizontal);
        yShearingSlider = new QSlider(Transformations2DWidget);
        yShearingSlider->setObjectName(QStringLiteral("yShearingSlider"));
        yShearingSlider->setGeometry(QRect(740, 385, 160, 22));
        yShearingSlider->setMaximum(10);
        yShearingSlider->setOrientation(Qt::Horizontal);
        xShearingLabel = new QLabel(Transformations2DWidget);
        xShearingLabel->setObjectName(QStringLiteral("xShearingLabel"));
        xShearingLabel->setGeometry(QRect(920, 355, 47, 13));
        xShearingLabel->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        xShearingLabel->setLineWidth(2);
        shearing = new QLabel(Transformations2DWidget);
        shearing->setObjectName(QStringLiteral("shearing"));
        shearing->setGeometry(QRect(740, 330, 101, 21));
        shearing->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        yScalingSlider = new QSlider(Transformations2DWidget);
        yScalingSlider->setObjectName(QStringLiteral("yScalingSlider"));
        yScalingSlider->setGeometry(QRect(740, 160, 160, 22));
        yScalingSlider->setMaximum(10);
        yScalingSlider->setValue(1);
        yScalingSlider->setOrientation(Qt::Horizontal);
        yScalingLabel = new QLabel(Transformations2DWidget);
        yScalingLabel->setObjectName(QStringLiteral("yScalingLabel"));
        yScalingLabel->setGeometry(QRect(920, 160, 47, 13));
        yScalingLabel->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        yScalingLabel->setLineWidth(2);

        retranslateUi(Transformations2DWidget);

        QMetaObject::connectSlotsByName(Transformations2DWidget);
    } // setupUi

    void retranslateUi(QWidget *Transformations2DWidget)
    {
        Transformations2DWidget->setWindowTitle(QApplication::translate("Transformations2DWidget", "Form", nullptr));
        rotation->setText(QApplication::translate("Transformations2DWidget", "Obr\303\263t", nullptr));
        alphaRotationLabel->setText(QApplication::translate("Transformations2DWidget", "Alpha", nullptr));
        scaling->setText(QApplication::translate("Transformations2DWidget", "Skalowanie", nullptr));
        xScalingLabel->setText(QApplication::translate("Transformations2DWidget", "X", nullptr));
        translation->setText(QApplication::translate("Transformations2DWidget", "Translacja", nullptr));
        yTranslationLabel->setText(QApplication::translate("Transformations2DWidget", "Y", nullptr));
        xTranslationLabel->setText(QApplication::translate("Transformations2DWidget", "X", nullptr));
        yShearingLabel->setText(QApplication::translate("Transformations2DWidget", "Y", nullptr));
        xShearingLabel->setText(QApplication::translate("Transformations2DWidget", "X", nullptr));
        shearing->setText(QApplication::translate("Transformations2DWidget", "Pochylenie", nullptr));
        yScalingLabel->setText(QApplication::translate("Transformations2DWidget", "Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transformations2DWidget: public Ui_Transformations2DWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMATIONS2DWIDGET_H
