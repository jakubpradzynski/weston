/********************************************************************************
** Form generated from reading UI file 'bsplinecurvewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BSPLINECURVEWIDGET_H
#define UI_BSPLINECURVEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "bsplinecurvecanvas.h"

QT_BEGIN_NAMESPACE

class Ui_BSplineCurveWidget
{
public:
    QPushButton *addPointButton;
    QPushButton *slidePointButton;
    QLabel *pointSizeLabel;
    QSpinBox *pointSizeSpinBox;
    QPushButton *clearButton;
    QPushButton *removePointButton;
    BSplineCurveCanvas *bSplineCurveCanvas;

    void setupUi(QWidget *BSplineCurveWidget)
    {
        if (BSplineCurveWidget->objectName().isEmpty())
            BSplineCurveWidget->setObjectName(QStringLiteral("BSplineCurveWidget"));
        BSplineCurveWidget->resize(850, 750);
        addPointButton = new QPushButton(BSplineCurveWidget);
        addPointButton->setObjectName(QStringLiteral("addPointButton"));
        addPointButton->setGeometry(QRect(60, 30, 113, 32));
        slidePointButton = new QPushButton(BSplineCurveWidget);
        slidePointButton->setObjectName(QStringLiteral("slidePointButton"));
        slidePointButton->setGeometry(QRect(60, 130, 113, 32));
        pointSizeLabel = new QLabel(BSplineCurveWidget);
        pointSizeLabel->setObjectName(QStringLiteral("pointSizeLabel"));
        pointSizeLabel->setGeometry(QRect(40, 260, 161, 20));
        pointSizeSpinBox = new QSpinBox(BSplineCurveWidget);
        pointSizeSpinBox->setObjectName(QStringLiteral("pointSizeSpinBox"));
        pointSizeSpinBox->setGeometry(QRect(80, 300, 48, 24));
        pointSizeSpinBox->setMaximum(5);
        pointSizeSpinBox->setValue(1);
        clearButton = new QPushButton(BSplineCurveWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(60, 180, 113, 32));
        removePointButton = new QPushButton(BSplineCurveWidget);
        removePointButton->setObjectName(QStringLiteral("removePointButton"));
        removePointButton->setGeometry(QRect(60, 80, 113, 32));
        bSplineCurveCanvas = new BSplineCurveCanvas(BSplineCurveWidget);
        bSplineCurveCanvas->setObjectName(QStringLiteral("bSplineCurveCanvas"));
        bSplineCurveCanvas->setGeometry(QRect(250, 20, 561, 511));

        retranslateUi(BSplineCurveWidget);

        QMetaObject::connectSlotsByName(BSplineCurveWidget);
    } // setupUi

    void retranslateUi(QWidget *BSplineCurveWidget)
    {
        BSplineCurveWidget->setWindowTitle(QApplication::translate("BSplineCurveWidget", "Form", nullptr));
        addPointButton->setText(QApplication::translate("BSplineCurveWidget", "Dodaj punkt", nullptr));
        slidePointButton->setText(QApplication::translate("BSplineCurveWidget", "Przesu\305\204 punkt", nullptr));
        pointSizeLabel->setText(QApplication::translate("BSplineCurveWidget", "Zmie\305\204 rozmiar punkt\303\263w", nullptr));
        clearButton->setText(QApplication::translate("BSplineCurveWidget", "Wyczy\305\233\304\207", nullptr));
        removePointButton->setText(QApplication::translate("BSplineCurveWidget", "Usu\305\204 punkt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BSplineCurveWidget: public Ui_BSplineCurveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BSPLINECURVEWIDGET_H
