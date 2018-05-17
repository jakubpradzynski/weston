#include "transformations2dwidget.h"
#include "ui_transformations2dwidget.h"

Transformations2DWidget::Transformations2DWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transformations2DWidget)
{
    ui->setupUi(this);

    connect(ui->alphaRotationSlider, SIGNAL(valueChanged(int)), ui->transformations2DCanvas, SLOT(rotationAlphaChanged(int)));

    connect(ui->xScalingSlider, SIGNAL(valueChanged(int)), ui->transformations2DCanvas, SLOT(scalingXChanged(int)));
    connect(ui->yScalingSlider, SIGNAL(valueChanged(int)), ui->transformations2DCanvas, SLOT(scalingYChanged(int)));

    connect(ui->xTranslationSlider, SIGNAL(valueChanged(int)), ui->transformations2DCanvas, SLOT(translationXChanged(int)));
    connect(ui->yTranslationSlider, SIGNAL(valueChanged(int)), ui->transformations2DCanvas, SLOT(translationYChanged(int)));

    connect(ui->xShearingSlider, SIGNAL(valueChanged(int)), ui->transformations2DCanvas, SLOT(shearingXChanged(int)));
    connect(ui->yShearingSlider, SIGNAL(valueChanged(int)), ui->transformations2DCanvas, SLOT(shearingYChanged(int)));

}

Transformations2DWidget::~Transformations2DWidget()
{
    delete ui;
}
