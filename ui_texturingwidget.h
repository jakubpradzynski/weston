/********************************************************************************
** Form generated from reading UI file 'texturingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTURINGWIDGET_H
#define UI_TEXTURINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "texturingcanvas.h"

QT_BEGIN_NAMESPACE

class Ui_TexturingWidget
{
public:
    TexturingCanvas *texturingCanvas;

    void setupUi(QWidget *TexturingWidget)
    {
        if (TexturingWidget->objectName().isEmpty())
            TexturingWidget->setObjectName(QStringLiteral("TexturingWidget"));
        TexturingWidget->resize(1186, 679);
        texturingCanvas = new TexturingCanvas(TexturingWidget);
        texturingCanvas->setObjectName(QStringLiteral("texturingCanvas"));
        texturingCanvas->setGeometry(QRect(30, 20, 1111, 621));

        retranslateUi(TexturingWidget);

        QMetaObject::connectSlotsByName(TexturingWidget);
    } // setupUi

    void retranslateUi(QWidget *TexturingWidget)
    {
        TexturingWidget->setWindowTitle(QApplication::translate("TexturingWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TexturingWidget: public Ui_TexturingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTURINGWIDGET_H
