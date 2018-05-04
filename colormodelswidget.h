#ifndef COLORMODELSWIDGET_H
#define COLORMODELSWIDGET_H

#include <QWidget>
#include "rgb.h"
#include "hsv.h"

namespace Ui {
class ColorModelsWidget;
}

class ColorModelsWidget : public QWidget
{
    Q_OBJECT

public slots:
  changeSlidersValues(HSV, RGB);

public:
    explicit ColorModelsWidget(QWidget *parent = 0);
    ~ColorModelsWidget();

public:
    Ui::ColorModelsWidget *ui;
};

#endif // COLORMODELSWIDGET_H
