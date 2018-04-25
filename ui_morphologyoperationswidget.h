/********************************************************************************
** Form generated from reading UI file 'morphologyoperationswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORPHOLOGYOPERATIONSWIDGET_H
#define UI_MORPHOLOGYOPERATIONSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "morphologyoperationscanvas.h"

QT_BEGIN_NAMESPACE

class Ui_MorphologyOperationsWidget
{
public:
    MorphologyOperationsCanvas *morphologyOperationsCanvas;
    QPushButton *dylationButton;
    QPushButton *erosionButton;
    QPushButton *clearButton;

    void setupUi(QWidget *MorphologyOperationsWidget)
    {
        if (MorphologyOperationsWidget->objectName().isEmpty())
            MorphologyOperationsWidget->setObjectName(QStringLiteral("MorphologyOperationsWidget"));
        MorphologyOperationsWidget->resize(826, 814);
        morphologyOperationsCanvas = new MorphologyOperationsCanvas(MorphologyOperationsWidget);
        morphologyOperationsCanvas->setObjectName(QStringLiteral("morphologyOperationsCanvas"));
        morphologyOperationsCanvas->setGeometry(QRect(30, 20, 571, 641));
        dylationButton = new QPushButton(MorphologyOperationsWidget);
        dylationButton->setObjectName(QStringLiteral("dylationButton"));
        dylationButton->setGeometry(QRect(660, 30, 113, 32));
        erosionButton = new QPushButton(MorphologyOperationsWidget);
        erosionButton->setObjectName(QStringLiteral("erosionButton"));
        erosionButton->setGeometry(QRect(660, 70, 113, 32));
        clearButton = new QPushButton(MorphologyOperationsWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(660, 110, 113, 32));

        retranslateUi(MorphologyOperationsWidget);

        QMetaObject::connectSlotsByName(MorphologyOperationsWidget);
    } // setupUi

    void retranslateUi(QWidget *MorphologyOperationsWidget)
    {
        MorphologyOperationsWidget->setWindowTitle(QApplication::translate("MorphologyOperationsWidget", "Form", nullptr));
        dylationButton->setText(QApplication::translate("MorphologyOperationsWidget", "Dylatacja", nullptr));
        erosionButton->setText(QApplication::translate("MorphologyOperationsWidget", "Erozja", nullptr));
        clearButton->setText(QApplication::translate("MorphologyOperationsWidget", "Wyczy\305\233\304\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MorphologyOperationsWidget: public Ui_MorphologyOperationsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORPHOLOGYOPERATIONSWIDGET_H
