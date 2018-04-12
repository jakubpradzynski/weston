#include "bsplinecurvewidget.h"
#include "ui_bsplinecurvewidget.h"

BSplineCurveWidget::BSplineCurveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BSplineCurveWidget)
{
    ui->setupUi(this);

    // Connect option buttons to method changeOption
    connect(ui->addPointButton, SIGNAL(pressed()), ui->bSplineCurveCanvas, SLOT(changeOption()));
    connect(ui->removePointButton, SIGNAL(pressed()), ui->bSplineCurveCanvas, SLOT(changeOption()));
    connect(ui->slidePointButton, SIGNAL(pressed()), ui->bSplineCurveCanvas, SLOT(changeOption()));

    // Connect clear button to method clearing canvas and pointsVector
    connect(ui->clearButton, SIGNAL(pressed()), ui->bSplineCurveCanvas, SLOT(clearCanvasAndPoints()));

    // Connect spin box to method changing point size
    connect(ui->pointSizeSpinBox, SIGNAL(valueChanged(int)), ui->bSplineCurveCanvas, SLOT(changePointSize(int)));

}

BSplineCurveWidget::~BSplineCurveWidget()
{
    delete ui;
}
