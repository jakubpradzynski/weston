#include "beziercurvewidget.h"
#include "ui_beziercurvewidget.h"

BezierCurveWidget::BezierCurveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BezierCurveWidget)
{
    ui->setupUi(this);

    // Connect option buttons to method changeOption
    connect(ui->addPointButton, SIGNAL(pressed()), ui->bezierCurveCanvas, SLOT(changeOption()));
    connect(ui->removePointButton, SIGNAL(pressed()), ui->bezierCurveCanvas, SLOT(changeOption()));
    connect(ui->slidePointButton, SIGNAL(pressed()), ui->bezierCurveCanvas, SLOT(changeOption()));

    // Connect clear button to method clearing canvas and pointsVector
    connect(ui->clearButton, SIGNAL(pressed()), ui->bezierCurveCanvas, SLOT(clearCanvasAndPoints()));

    // Connect spin box to method changing point size
    connect(ui->pointSizeSpinBox, SIGNAL(valueChanged(int)), ui->bezierCurveCanvas, SLOT(changePointSize(int)));
}

BezierCurveWidget::~BezierCurveWidget()
{
    delete ui;
}
