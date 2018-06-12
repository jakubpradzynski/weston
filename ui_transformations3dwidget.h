/********************************************************************************
** Form generated from reading UI file 'transformations3dwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMATIONS3DWIDGET_H
#define UI_TRANSFORMATIONS3DWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "transformations3dcanvas.h"

QT_BEGIN_NAMESPACE

class Ui_Transformations3DWidget
{
public:
    Transformations3DCanvas *transformations3DCanvas;
    QLabel *translationLabel;
    QSlider *translationXSlider;
    QSlider *translationYSlider;
    QSlider *translationZSlider;
    QLabel *translationXLabel;
    QLabel *translationYLabel;
    QLabel *translationZLabel;
    QLabel *scalingLabel;
    QLabel *scalingZLabel;
    QSlider *scalingYSlider;
    QLabel *scalingXLabel;
    QSlider *scalingXSlider;
    QLabel *scalingYLabel;
    QSlider *scalingZSlider;
    QLabel *rotationLabel;
    QLabel *rotationZLabel;
    QSlider *rotationYSlider;
    QLabel *rotationXLabel;
    QSlider *rotationXSlider;
    QLabel *rotationYLabel;
    QSlider *rotationZSlider;
    QLabel *perspectiveLabel;
    QLabel *perspectiveFLabel;
    QSlider *perspectiveSlider;

    void setupUi(QWidget *Transformations3DWidget)
    {
        if (Transformations3DWidget->objectName().isEmpty())
            Transformations3DWidget->setObjectName(QStringLiteral("Transformations3DWidget"));
        Transformations3DWidget->resize(1535, 870);
        transformations3DCanvas = new Transformations3DCanvas(Transformations3DWidget);
        transformations3DCanvas->setObjectName(QStringLiteral("transformations3DCanvas"));
        transformations3DCanvas->setGeometry(QRect(20, 20, 1100, 800));
        translationLabel = new QLabel(Transformations3DWidget);
        translationLabel->setObjectName(QStringLiteral("translationLabel"));
        translationLabel->setGeometry(QRect(1150, 20, 131, 31));
        translationLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        translationXSlider = new QSlider(Transformations3DWidget);
        translationXSlider->setObjectName(QStringLiteral("translationXSlider"));
        translationXSlider->setGeometry(QRect(1150, 70, 291, 22));
        translationXSlider->setMinimum(-100);
        translationXSlider->setMaximum(100);
        translationXSlider->setValue(0);
        translationXSlider->setOrientation(Qt::Horizontal);
        translationYSlider = new QSlider(Transformations3DWidget);
        translationYSlider->setObjectName(QStringLiteral("translationYSlider"));
        translationYSlider->setGeometry(QRect(1150, 110, 291, 22));
        translationYSlider->setMinimum(-100);
        translationYSlider->setMaximum(100);
        translationYSlider->setValue(0);
        translationYSlider->setOrientation(Qt::Horizontal);
        translationZSlider = new QSlider(Transformations3DWidget);
        translationZSlider->setObjectName(QStringLiteral("translationZSlider"));
        translationZSlider->setGeometry(QRect(1150, 150, 291, 22));
        translationZSlider->setMinimum(-100);
        translationZSlider->setMaximum(100);
        translationZSlider->setValue(0);
        translationZSlider->setOrientation(Qt::Horizontal);
        translationXLabel = new QLabel(Transformations3DWidget);
        translationXLabel->setObjectName(QStringLiteral("translationXLabel"));
        translationXLabel->setGeometry(QRect(1460, 60, 31, 31));
        translationXLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        translationYLabel = new QLabel(Transformations3DWidget);
        translationYLabel->setObjectName(QStringLiteral("translationYLabel"));
        translationYLabel->setGeometry(QRect(1460, 100, 31, 31));
        translationYLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        translationZLabel = new QLabel(Transformations3DWidget);
        translationZLabel->setObjectName(QStringLiteral("translationZLabel"));
        translationZLabel->setGeometry(QRect(1460, 140, 31, 31));
        translationZLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        scalingLabel = new QLabel(Transformations3DWidget);
        scalingLabel->setObjectName(QStringLiteral("scalingLabel"));
        scalingLabel->setGeometry(QRect(1150, 200, 131, 31));
        scalingLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        scalingZLabel = new QLabel(Transformations3DWidget);
        scalingZLabel->setObjectName(QStringLiteral("scalingZLabel"));
        scalingZLabel->setGeometry(QRect(1460, 320, 31, 31));
        scalingZLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        scalingYSlider = new QSlider(Transformations3DWidget);
        scalingYSlider->setObjectName(QStringLiteral("scalingYSlider"));
        scalingYSlider->setGeometry(QRect(1150, 290, 291, 22));
        scalingYSlider->setMinimum(0);
        scalingYSlider->setMaximum(20);
        scalingYSlider->setValue(10);
        scalingYSlider->setOrientation(Qt::Horizontal);
        scalingXLabel = new QLabel(Transformations3DWidget);
        scalingXLabel->setObjectName(QStringLiteral("scalingXLabel"));
        scalingXLabel->setGeometry(QRect(1460, 240, 31, 31));
        scalingXLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        scalingXSlider = new QSlider(Transformations3DWidget);
        scalingXSlider->setObjectName(QStringLiteral("scalingXSlider"));
        scalingXSlider->setGeometry(QRect(1150, 250, 291, 22));
        scalingXSlider->setMinimum(0);
        scalingXSlider->setMaximum(20);
        scalingXSlider->setValue(10);
        scalingXSlider->setOrientation(Qt::Horizontal);
        scalingYLabel = new QLabel(Transformations3DWidget);
        scalingYLabel->setObjectName(QStringLiteral("scalingYLabel"));
        scalingYLabel->setGeometry(QRect(1460, 280, 31, 31));
        scalingYLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        scalingZSlider = new QSlider(Transformations3DWidget);
        scalingZSlider->setObjectName(QStringLiteral("scalingZSlider"));
        scalingZSlider->setGeometry(QRect(1150, 330, 291, 22));
        scalingZSlider->setMinimum(0);
        scalingZSlider->setMaximum(20);
        scalingZSlider->setValue(10);
        scalingZSlider->setOrientation(Qt::Horizontal);
        rotationLabel = new QLabel(Transformations3DWidget);
        rotationLabel->setObjectName(QStringLiteral("rotationLabel"));
        rotationLabel->setGeometry(QRect(1150, 380, 131, 31));
        rotationLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        rotationZLabel = new QLabel(Transformations3DWidget);
        rotationZLabel->setObjectName(QStringLiteral("rotationZLabel"));
        rotationZLabel->setGeometry(QRect(1460, 500, 31, 31));
        rotationZLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        rotationYSlider = new QSlider(Transformations3DWidget);
        rotationYSlider->setObjectName(QStringLiteral("rotationYSlider"));
        rotationYSlider->setGeometry(QRect(1150, 470, 291, 22));
        rotationYSlider->setMinimum(-360);
        rotationYSlider->setMaximum(360);
        rotationYSlider->setOrientation(Qt::Horizontal);
        rotationXLabel = new QLabel(Transformations3DWidget);
        rotationXLabel->setObjectName(QStringLiteral("rotationXLabel"));
        rotationXLabel->setGeometry(QRect(1460, 420, 31, 31));
        rotationXLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        rotationXSlider = new QSlider(Transformations3DWidget);
        rotationXSlider->setObjectName(QStringLiteral("rotationXSlider"));
        rotationXSlider->setGeometry(QRect(1150, 430, 291, 22));
        rotationXSlider->setMinimum(-360);
        rotationXSlider->setMaximum(360);
        rotationXSlider->setOrientation(Qt::Horizontal);
        rotationYLabel = new QLabel(Transformations3DWidget);
        rotationYLabel->setObjectName(QStringLiteral("rotationYLabel"));
        rotationYLabel->setGeometry(QRect(1460, 460, 31, 31));
        rotationYLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        rotationZSlider = new QSlider(Transformations3DWidget);
        rotationZSlider->setObjectName(QStringLiteral("rotationZSlider"));
        rotationZSlider->setGeometry(QRect(1150, 510, 291, 22));
        rotationZSlider->setMinimum(-360);
        rotationZSlider->setMaximum(360);
        rotationZSlider->setOrientation(Qt::Horizontal);
        perspectiveLabel = new QLabel(Transformations3DWidget);
        perspectiveLabel->setObjectName(QStringLiteral("perspectiveLabel"));
        perspectiveLabel->setGeometry(QRect(1150, 550, 131, 31));
        perspectiveLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        perspectiveFLabel = new QLabel(Transformations3DWidget);
        perspectiveFLabel->setObjectName(QStringLiteral("perspectiveFLabel"));
        perspectiveFLabel->setGeometry(QRect(1460, 590, 31, 31));
        perspectiveFLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        perspectiveSlider = new QSlider(Transformations3DWidget);
        perspectiveSlider->setObjectName(QStringLiteral("perspectiveSlider"));
        perspectiveSlider->setGeometry(QRect(1150, 600, 291, 22));
        perspectiveSlider->setMinimum(0);
        perspectiveSlider->setMaximum(1000);
        perspectiveSlider->setValue(50);
        perspectiveSlider->setOrientation(Qt::Horizontal);

        retranslateUi(Transformations3DWidget);

        QMetaObject::connectSlotsByName(Transformations3DWidget);
    } // setupUi

    void retranslateUi(QWidget *Transformations3DWidget)
    {
        Transformations3DWidget->setWindowTitle(QApplication::translate("Transformations3DWidget", "Form", nullptr));
        translationLabel->setText(QApplication::translate("Transformations3DWidget", "Translacja", nullptr));
        translationXLabel->setText(QApplication::translate("Transformations3DWidget", "X", nullptr));
        translationYLabel->setText(QApplication::translate("Transformations3DWidget", "Y", nullptr));
        translationZLabel->setText(QApplication::translate("Transformations3DWidget", "Z", nullptr));
        scalingLabel->setText(QApplication::translate("Transformations3DWidget", "Skalowanie", nullptr));
        scalingZLabel->setText(QApplication::translate("Transformations3DWidget", "Z", nullptr));
        scalingXLabel->setText(QApplication::translate("Transformations3DWidget", "X", nullptr));
        scalingYLabel->setText(QApplication::translate("Transformations3DWidget", "Y", nullptr));
        rotationLabel->setText(QApplication::translate("Transformations3DWidget", "Rotacja", nullptr));
        rotationZLabel->setText(QApplication::translate("Transformations3DWidget", "Z", nullptr));
        rotationXLabel->setText(QApplication::translate("Transformations3DWidget", "X", nullptr));
        rotationYLabel->setText(QApplication::translate("Transformations3DWidget", "Y", nullptr));
        perspectiveLabel->setText(QApplication::translate("Transformations3DWidget", "Perspektywa", nullptr));
        perspectiveFLabel->setText(QApplication::translate("Transformations3DWidget", "F", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transformations3DWidget: public Ui_Transformations3DWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMATIONS3DWIDGET_H
