#include "transformations3dwidget.h"
#include "ui_transformations3dwidget.h"

Transformations3DWidget::Transformations3DWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transformations3DWidget)
{
    ui->setupUi(this);

    connect(ui->translationXSlider, SIGNAL(valueChanged(int)), ui->transformations3DCanvas, SLOT(translationXChanged(int)));
    connect(ui->translationYSlider, SIGNAL(valueChanged(int)), ui->transformations3DCanvas, SLOT(translationYChanged(int)));
    connect(ui->translationZSlider, SIGNAL(valueChanged(int)), ui->transformations3DCanvas, SLOT(translationZChanged(int)));

    connect(ui->scalingXSlider, SIGNAL(valueChanged(int)), ui->transformations3DCanvas, SLOT(scalingXChanged(int)));
    connect(ui->scalingYSlider, SIGNAL(valueChanged(int)), ui->transformations3DCanvas, SLOT(scalingYChanged(int)));
    connect(ui->scalingZSlider, SIGNAL(valueChanged(int)), ui->transformations3DCanvas, SLOT(scalingZChanged(int)));

    connect(ui->rotationXSlider, SIGNAL(valueChanged(int)), ui->transformations3DCanvas, SLOT(rotationXChanged(int)));
    connect(ui->rotationYSlider, SIGNAL(valueChanged(int)), ui->transformations3DCanvas, SLOT(rotationYChanged(int)));
    connect(ui->rotationZSlider, SIGNAL(valueChanged(int)), ui->transformations3DCanvas, SLOT(rotationZChanged(int)));

    connect(ui->perspectiveSlider, SIGNAL(valueChanged(int)), ui->transformations3DCanvas, SLOT(perspectiveChanged(int)));
}

Transformations3DWidget::~Transformations3DWidget()
{
    delete ui;
}
