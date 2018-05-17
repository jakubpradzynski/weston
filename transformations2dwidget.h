#ifndef TRANSFORMATIONS2DWIDGET_H
#define TRANSFORMATIONS2DWIDGET_H

#include <QWidget>

namespace Ui {
class Transformations2DWidget;
}

class Transformations2DWidget : public QWidget
{
    Q_OBJECT

public:
    explicit Transformations2DWidget(QWidget *parent = 0);
    ~Transformations2DWidget();

private:
    Ui::Transformations2DWidget *ui;
};

#endif // TRANSFORMATIONS2DWIDGET_H
