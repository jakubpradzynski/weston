#ifndef IMAGECOLORMODELWIDGET_H
#define IMAGECOLORMODELWIDGET_H

#include <QWidget>
#include "rgb.h"
#include "hsv.h"

namespace Ui {
class ImageColorModelWidget;
}

class ImageColorModelWidget : public QWidget
{
    Q_OBJECT

public slots:
    changeSlidersValues(int, int, int);

public:
    explicit ImageColorModelWidget(QWidget *parent = 0);
    ~ImageColorModelWidget();

private:
    Ui::ImageColorModelWidget *ui;
};

#endif // IMAGECOLORMODELWIDGET_H
