#include "colormodelswidget.h"
#include "ui_colormodelswidget.h"

ColorModelsWidget::changeSlidersValues(HSV hsv, RGB rgb)
{
    ui->rValueSlider->setValue(rgb.getR());
    ui->gValueSlider->setValue(rgb.getG());
    ui->bValueSlider->setValue(rgb.getB());
    ui->hValueSlider->setValue(hsv.getH());
    ui->sValueSlider->setValue(hsv.getS());
    ui->vValueSlider->setValue(hsv.getV());
    ui->rValue->setText(QString::number(rgb.getR()));
    ui->gValue->setText(QString::number(rgb.getG()));
    ui->bValue->setText(QString::number(rgb.getB()));
    ui->hValue->setText(QString::number(hsv.getH()));
    ui->sValue->setText(QString::number(hsv.getS()));
    ui->vValue->setText(QString::number(hsv.getV()));
}

ColorModelsWidget::ColorModelsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorModelsWidget)
{
    ui->setupUi(this);

    connect(ui->rValueSlider, SIGNAL(sliderMoved(int)), ui->colorModelCanvas, SLOT(changeRValue(int)));
    connect(ui->gValueSlider, SIGNAL(sliderMoved(int)), ui->colorModelCanvas, SLOT(changeGValue(int)));
    connect(ui->bValueSlider, SIGNAL(sliderMoved(int)), ui->colorModelCanvas, SLOT(changeBValue(int)));
    connect(ui->hValueSlider, SIGNAL(sliderMoved(int)), ui->colorModelCanvas, SLOT(changeHValue(int)));
    connect(ui->sValueSlider, SIGNAL(sliderMoved(int)), ui->colorModelCanvas, SLOT(changeSValue(int)));
    connect(ui->vValueSlider, SIGNAL(sliderMoved(int)), ui->colorModelCanvas, SLOT(changeVValue(int)));

    connect(ui->colorModelCanvas, SIGNAL(valuesChanged(HSV,RGB)), this, SLOT(changeSlidersValues(HSV, RGB)));
}

ColorModelsWidget::~ColorModelsWidget()
{
    delete ui;
}
