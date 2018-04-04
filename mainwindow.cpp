#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect option buttons to method changeOption
    connect(ui->pencilButton, SIGNAL(pressed()), ui->myCanvas, SLOT(changeOption()));
    connect(ui->sprayButton, SIGNAL(pressed()), ui->myCanvas, SLOT(changeOption()));
    connect(ui->lineButton, SIGNAL(pressed()), ui->myCanvas, SLOT(changeOption()));
    connect(ui->rectangleButton, SIGNAL(pressed()), ui->myCanvas, SLOT(changeOption()));
    connect(ui->circleButton, SIGNAL(pressed()), ui->myCanvas, SLOT(changeOption()));
    connect(ui->filledCircleButton, SIGNAL(pressed()), ui->myCanvas, SLOT(changeOption()));
    connect(ui->ellipseButton, SIGNAL(pressed()), ui->myCanvas, SLOT(changeOption()));
    connect(ui->floodFillButton, SIGNAL(pressed()), ui->myCanvas, SLOT(changeOption()));
    connect(ui->clearButton, SIGNAL(pressed()), ui->myCanvas, SLOT(clearCanvas()));

    // Connect spin boxes to methods changing rgb values
    connect(ui->rValueSpinBox, SIGNAL(valueChanged(int)), ui->myCanvas, SLOT(changeBrushRValue(int)));
    connect(ui->gValueSpinBox, SIGNAL(valueChanged(int)), ui->myCanvas, SLOT(changeBrushGValue(int)));
    connect(ui->bValueSpinBox, SIGNAL(valueChanged(int)), ui->myCanvas, SLOT(changeBrushBValue(int)));

    // Connect ellipse slope value horizontal slider to method rotating ellipse
    connect(ui->ellipseSlopeSlider, SIGNAL(sliderMoved(int)), ui->myCanvas, SLOT(rotateEllipse(int)));

    // Connect button to open Bezier Curve Widget window
    connect(ui->bezierCurveButton, SIGNAL(pressed()), this, SLOT(openBezierCurveWidget()));
    connect(ui->bezierCurveAction, SIGNAL(triggered(bool)), this, SLOT(openBezierCurveWidget()));

    // Connect button to open Bezier Curve Widget window
    connect(ui->bSplineCurveButton, SIGNAL(pressed()), this, SLOT(openBSplineCurveWidget()));
    connect(ui->bSplineCurveAction, SIGNAL(triggered(bool)), this, SLOT(openBSplineCurveWidget()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Method open new window with Bezier Curve Widget
void MainWindow::openBezierCurveWidget()
{
    bezierCurveWidget = new BezierCurveWidget();
    bezierCurveWidget->show();
    bezierCurveWidget->setWindowTitle("Krzywe Beziera");
}

// Method open new window with B-spline Curve Widget
void MainWindow::openBSplineCurveWidget()
{
    bSplineCurveWidget = new BSplineCurveWidget();
    bSplineCurveWidget->show();
    bSplineCurveWidget->setWindowTitle("Krzywe B-sklejane");
}
