#include "scanelinewidget.h"
#include "ui_scanelinewidget.h"

ScaneLineWidget::ScaneLineWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScaneLineWidget)
{
    ui->setupUi(this);

    // Connect option buttons to method changeOption
    connect(ui->addPointButton, SIGNAL(pressed()), ui->scaneLineCanvas, SLOT(changeOption()));
    connect(ui->removePointButton, SIGNAL(pressed()), ui->scaneLineCanvas, SLOT(changeOption()));
    connect(ui->slidePointButton, SIGNAL(pressed()), ui->scaneLineCanvas, SLOT(changeOption()));

    // Connect clear button to method clearing canvas and pointsVector
    connect(ui->clearButton, SIGNAL(pressed()), ui->scaneLineCanvas, SLOT(clearCanvasAndPoints()));

    // Connect spin box to method changing point size
    connect(ui->pointSizeSpinBox, SIGNAL(valueChanged(int)), ui->scaneLineCanvas, SLOT(changePointSize(int)));

    // Connect draw button with method drawing polygon using scan line algorithm
    connect(ui->drawButton, SIGNAL(pressed()), ui->scaneLineCanvas, SLOT(draw()));
}

ScaneLineWidget::~ScaneLineWidget()
{
    delete ui;
}
