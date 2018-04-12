#ifndef SCANELINEWIDGET_H
#define SCANELINEWIDGET_H

#include <QWidget>

namespace Ui {
class ScaneLineWidget;
}

class ScaneLineWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScaneLineWidget(QWidget *parent = 0);
    ~ScaneLineWidget();

private:
    Ui::ScaneLineWidget *ui;
};

#endif // SCANELINEWIDGET_H
