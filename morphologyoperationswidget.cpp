#include "morphologyoperationswidget.h"
#include "ui_morphologyoperationswidget.h"

MorphologyOperationsWidget::MorphologyOperationsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MorphologyOperationsWidget)
{
    ui->setupUi(this);

    connect(ui->dylationButton, SIGNAL(pressed()), ui->morphologyOperationsCanvas, SLOT(putDilation()));
    connect(ui->erosionButton, SIGNAL(pressed()), ui->morphologyOperationsCanvas, SLOT(putErosion()));
    connect(ui->clearButton, SIGNAL(pressed()), ui->morphologyOperationsCanvas, SLOT(clearCanvas()));
}

MorphologyOperationsWidget::~MorphologyOperationsWidget()
{
    delete ui;
}
