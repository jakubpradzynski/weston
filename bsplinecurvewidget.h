#ifndef BSPLINECURVEWIDGET_H
#define BSPLINECURVEWIDGET_H

#include <QWidget>

namespace Ui {
class BSplineCurveWidget;
}

class BSplineCurveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BSplineCurveWidget(QWidget *parent = 0);
    ~BSplineCurveWidget();

private:
    Ui::BSplineCurveWidget *ui;
};

#endif // BSPLINECURVEWIDGET_H
