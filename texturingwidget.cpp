#include "texturingwidget.h"
#include "ui_texturingwidget.h"

TexturingWidget::TexturingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TexturingWidget)
{
    ui->setupUi(this);
}

TexturingWidget::~TexturingWidget()
{
    delete ui;
}
