/********************************************************************************
** Form generated from reading UI file 'scanelinewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANELINEWIDGET_H
#define UI_SCANELINEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "scanelinecanvas.h"

QT_BEGIN_NAMESPACE

class Ui_ScaneLineWidget
{
public:
    QPushButton *slidePointButton;
    QPushButton *addPointButton;
    QLabel *pointSizeLabel;
    QPushButton *removePointButton;
    QSpinBox *pointSizeSpinBox;
    QPushButton *clearButton;
    ScaneLineCanvas *scaneLineCanvas;
    QPushButton *drawButton;

    void setupUi(QWidget *ScaneLineWidget)
    {
        if (ScaneLineWidget->objectName().isEmpty())
            ScaneLineWidget->setObjectName(QStringLiteral("ScaneLineWidget"));
        ScaneLineWidget->resize(850, 750);
        slidePointButton = new QPushButton(ScaneLineWidget);
        slidePointButton->setObjectName(QStringLiteral("slidePointButton"));
        slidePointButton->setGeometry(QRect(50, 240, 113, 32));
        addPointButton = new QPushButton(ScaneLineWidget);
        addPointButton->setObjectName(QStringLiteral("addPointButton"));
        addPointButton->setGeometry(QRect(50, 160, 113, 32));
        pointSizeLabel = new QLabel(ScaneLineWidget);
        pointSizeLabel->setObjectName(QStringLiteral("pointSizeLabel"));
        pointSizeLabel->setGeometry(QRect(40, 340, 161, 20));
        removePointButton = new QPushButton(ScaneLineWidget);
        removePointButton->setObjectName(QStringLiteral("removePointButton"));
        removePointButton->setGeometry(QRect(50, 200, 113, 32));
        pointSizeSpinBox = new QSpinBox(ScaneLineWidget);
        pointSizeSpinBox->setObjectName(QStringLiteral("pointSizeSpinBox"));
        pointSizeSpinBox->setGeometry(QRect(90, 390, 48, 24));
        pointSizeSpinBox->setMaximum(5);
        pointSizeSpinBox->setValue(1);
        clearButton = new QPushButton(ScaneLineWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(50, 280, 113, 32));
        scaneLineCanvas = new ScaneLineCanvas(ScaneLineWidget);
        scaneLineCanvas->setObjectName(QStringLiteral("scaneLineCanvas"));
        scaneLineCanvas->setGeometry(QRect(270, 30, 531, 531));
        drawButton = new QPushButton(ScaneLineWidget);
        drawButton->setObjectName(QStringLiteral("drawButton"));
        drawButton->setGeometry(QRect(50, 70, 113, 32));

        retranslateUi(ScaneLineWidget);

        QMetaObject::connectSlotsByName(ScaneLineWidget);
    } // setupUi

    void retranslateUi(QWidget *ScaneLineWidget)
    {
        ScaneLineWidget->setWindowTitle(QApplication::translate("ScaneLineWidget", "Form", nullptr));
        slidePointButton->setText(QApplication::translate("ScaneLineWidget", "Przesu\305\204 punkt", nullptr));
        addPointButton->setText(QApplication::translate("ScaneLineWidget", "Dodaj punkt", nullptr));
        pointSizeLabel->setText(QApplication::translate("ScaneLineWidget", "Zmie\305\204 rozmiar punkt\303\263w", nullptr));
        removePointButton->setText(QApplication::translate("ScaneLineWidget", "Usu\305\204 punkt", nullptr));
        clearButton->setText(QApplication::translate("ScaneLineWidget", "Wyczy\305\233\304\207", nullptr));
        drawButton->setText(QApplication::translate("ScaneLineWidget", "Rysuj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScaneLineWidget: public Ui_ScaneLineWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANELINEWIDGET_H
