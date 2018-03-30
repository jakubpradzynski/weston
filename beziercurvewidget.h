#ifndef BEZIERCURVEWIDGET_H
#define BEZIERCURVEWIDGET_H

#include <QWidget>

namespace Ui {
class BezierCurveWidget;
}

class BezierCurveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BezierCurveWidget(QWidget *parent = 0);
    ~BezierCurveWidget();

private:
    Ui::BezierCurveWidget *ui;
};

#endif // BEZIERCURVEWIDGET_H
