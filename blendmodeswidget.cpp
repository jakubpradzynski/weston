#include "blendmodeswidget.h"
#include "ui_blendmodeswidget.h"

BlendModesWidget::BlendModesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlendModesWidget)
{
    ui->setupUi(this);

    connect(ui->layerOneButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(showLayerOne()));
    connect(ui->layerTwoButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(showLayerTwo()));
    connect(ui->layerThreeButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(showLayerThree()));
    connect(ui->clearButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(clearCanvas()));

    connect(ui->alphaBlendingSlider, SIGNAL(valueChanged(int)), ui->blendModesCanvas, SLOT(applyAlphaBlending(int)));
    connect(ui->alphaBlendingForThreeLayersSlider, SIGNAL(valueChanged(int)), ui->blendModesCanvas, SLOT(applyAlphaBlendingForThreeLayers(int)));

    connect(ui->multiplyButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyMultiplyMode()));
    connect(ui->screenButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyScreenMode()));
    connect(ui->overlayButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyOverlayMode()));
    connect(ui->darkenButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyDarkenMode()));
    connect(ui->lightenButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyLightenMode()));
    connect(ui->differenceButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyDifferenceMode()));
    connect(ui->additiveButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyAdditiveMode()));
    connect(ui->subtractiveButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applySubtractiveMode()));

    connect(ui->multiplyForThreeLayersButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyMultiplyModeForThreeLayers()));
    connect(ui->screenForThreeLayersButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyScreenModeForThreeLayers()));
    connect(ui->overlayForThreeLayersButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyOverlayModeForThreeLayers()));
    connect(ui->darkenForThreeLayersButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyDarkenModeForThreeLayers()));
    connect(ui->lightenForThreeLayersButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyLightenModeForThreeLayers()));
    connect(ui->differenceForThreeLayersButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyDifferenceModeForThreeLayers()));
    connect(ui->additiveForThreeLayersButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applyAdditiveModeForThreeLayers()));
    connect(ui->subtractiveForThreeLayersButton, SIGNAL(pressed()), ui->blendModesCanvas, SLOT(applySubtractiveModeForThreeLayers()));
}

BlendModesWidget::~BlendModesWidget()
{
    delete ui;
}
