#include "imagecolormodelwidget.h"
#include "ui_imagecolormodelwidget.h"

ImageColorModelWidget::changeSlidersValues(int H, int S, int V)
{
    ui->hValueSlider->setValue(H);
    ui->sValueSlider->setValue(S);
    ui->vValueSlider->setValue(V);
    ui->hValue->setText(QString::number(H));
    ui->sValue->setText(QString::number(S));
    ui->vValue->setText(QString::number(V));
}

ImageColorModelWidget::ImageColorModelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageColorModelWidget)
{
    ui->setupUi(this);
    connect(ui->hValueSlider, SIGNAL(sliderMoved(int)), ui->colorModelCanvas, SLOT(changeHValue(int)));
    connect(ui->sValueSlider, SIGNAL(sliderMoved(int)), ui->colorModelCanvas, SLOT(changeSValue(int)));
    connect(ui->vValueSlider, SIGNAL(sliderMoved(int)), ui->colorModelCanvas, SLOT(changeVValue(int)));

    connect(ui->colorModelCanvas, SIGNAL(valuesChanged(int, int, int)), this, SLOT(changeSlidersValues(int, int, int)));
}

ImageColorModelWidget::~ImageColorModelWidget()
{
    delete ui;
}
