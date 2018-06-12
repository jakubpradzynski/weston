#ifndef TRANSFORMATIONS3DWIDGET_H
#define TRANSFORMATIONS3DWIDGET_H

#include <QWidget>

namespace Ui {
class Transformations3DWidget;
}

class Transformations3DWidget : public QWidget
{
    Q_OBJECT

public:
    explicit Transformations3DWidget(QWidget *parent = 0);
    ~Transformations3DWidget();

private:
    Ui::Transformations3DWidget *ui;
};

#endif // TRANSFORMATIONS3DWIDGET_H
