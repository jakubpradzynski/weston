#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "beziercurvewidget.h"
#include "bsplinecurvewidget.h"
#include "scanelinewidget.h"
#include "morphologyoperationswidget.h"
#include "colormodelswidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openBezierCurveWidget(); // Method open new window with Bezier Curve Widget
    void openBSplineCurveWidget(); // Method open new window with B-spline Curve Widget
    void openScaneLineWidget(); // Method open new window with ScaneLine algorithm
    void openMorphologyOperationsWidget();
    void openColorModelsWidget();

private:
    Ui::MainWindow *ui;
    BezierCurveWidget *bezierCurveWidget; // Bezier Curve Widget window
    BSplineCurveWidget *bSplineCurveWidget; // B-spline Curve Widget window
    ScaneLineWidget *scaneLineWidget; // ScaneLine Widget window
    MorphologyOperationsWidget *morphologyOperationsWidget;
    ColorModelsWidget *colorModelsWidget;
};

#endif // MAINWINDOW_H
