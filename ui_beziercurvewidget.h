/********************************************************************************
** Form generated from reading UI file 'beziercurvewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEZIERCURVEWIDGET_H
#define UI_BEZIERCURVEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "beziercurvecanvas.h"

QT_BEGIN_NAMESPACE

class Ui_BezierCurveWidget
{
public:
    QPushButton *slidePointButton;
    QPushButton *addPointButton;
    QLabel *pointSizeLabel;
    QSpinBox *pointSizeSpinBox;
    QPushButton *clearButton;
    BezierCurveCanvas *bezierCurveCanvas;
    QPushButton *removePointButton;

    void setupUi(QWidget *BezierCurveWidget)
    {
        if (BezierCurveWidget->objectName().isEmpty())
            BezierCurveWidget->setObjectName(QStringLiteral("BezierCurveWidget"));
        BezierCurveWidget->resize(850, 750);
        slidePointButton = new QPushButton(BezierCurveWidget);
        slidePointButton->setObjectName(QStringLiteral("slidePointButton"));
        slidePointButton->setGeometry(QRect(50, 130, 113, 32));
        addPointButton = new QPushButton(BezierCurveWidget);
        addPointButton->setObjectName(QStringLiteral("addPointButton"));
        addPointButton->setGeometry(QRect(50, 30, 113, 32));
        pointSizeLabel = new QLabel(BezierCurveWidget);
        pointSizeLabel->setObjectName(QStringLiteral("pointSizeLabel"));
        pointSizeLabel->setGeometry(QRect(40, 260, 161, 20));
        pointSizeSpinBox = new QSpinBox(BezierCurveWidget);
        pointSizeSpinBox->setObjectName(QStringLiteral("pointSizeSpinBox"));
        pointSizeSpinBox->setGeometry(QRect(80, 300, 48, 24));
        pointSizeSpinBox->setMaximum(5);
        pointSizeSpinBox->setValue(1);
        clearButton = new QPushButton(BezierCurveWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(50, 180, 113, 32));
        bezierCurveCanvas = new BezierCurveCanvas(BezierCurveWidget);
        bezierCurveCanvas->setObjectName(QStringLiteral("bezierCurveCanvas"));
        bezierCurveCanvas->setGeometry(QRect(250, 20, 561, 511));
        removePointButton = new QPushButton(BezierCurveWidget);
        removePointButton->setObjectName(QStringLiteral("removePointButton"));
        removePointButton->setGeometry(QRect(50, 80, 113, 32));

        retranslateUi(BezierCurveWidget);

        QMetaObject::connectSlotsByName(BezierCurveWidget);
    } // setupUi

    void retranslateUi(QWidget *BezierCurveWidget)
    {
        BezierCurveWidget->setWindowTitle(QApplication::translate("BezierCurveWidget", "Form", nullptr));
        slidePointButton->setText(QApplication::translate("BezierCurveWidget", "Przesu\305\204 punkt", nullptr));
        addPointButton->setText(QApplication::translate("BezierCurveWidget", "Dodaj punkt", nullptr));
        pointSizeLabel->setText(QApplication::translate("BezierCurveWidget", "Zmie\305\204 rozmiar punkt\303\263w", nullptr));
        clearButton->setText(QApplication::translate("BezierCurveWidget", "Wyczy\305\233\304\207", nullptr));
        removePointButton->setText(QApplication::translate("BezierCurveWidget", "Usu\305\204 punkt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BezierCurveWidget: public Ui_BezierCurveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEZIERCURVEWIDGET_H
