#ifndef BLENDMODESCANVAS_H
#define BLENDMODESCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QSlider>
#include <QLabel>
#include "point.h"
#include "rgb.h"
#include "hsv.h"
#include <math.h>

class BlendModesCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit BlendModesCanvas(QWidget *parent = nullptr);

protected:
    // Events
    void paintEvent(QPaintEvent *event);

public slots:
    void showLayerOne();
    void showLayerTwo();
    void showLayerThree();
    void clearCanvas();
    void applyAlphaBlending(int);
    void applyAlphaBlendingForThreeLayers(int);
    void applyMultiplyMode();
    void applyScreenMode();
    void applyOverlayMode();
    void applyDarkenMode();
    void applyLightenMode();
    void applyDifferenceMode();
    void applyAdditiveMode();
    void applySubtractiveMode();
    void applyMultiplyModeForThreeLayers();
    void applyScreenModeForThreeLayers();
    void applyOverlayModeForThreeLayers();
    void applyDarkenModeForThreeLayers();
    void applyLightenModeForThreeLayers();
    void applyDifferenceModeForThreeLayers();
    void applyAdditiveModeForThreeLayers();
    void applySubtractiveModeForThreeLayers();

private:
    QSize canvasSize = QSize(650, 500); // Setting canvas size
    QImage qImage; // Place to draw
    QSize layerSize = QSize(500, 500);
    QImage layerOne = QImage("layerOneV2.png");
    QImage layerTwo = QImage("layerTwoV2.png");
    QImage layerThree = QImage("layerThreeV2.png");
    void repaintFromOneQImageToSecond(QImage *first, QImage *second);
    void putPixel(Point point, RGB rgb);
    void putPixel(QImage *qImage, Point point, RGB rgb);
    RGB getPointColor(Point point);
    RGB getPointColor(QImage *qImage, Point point);
    void alphaBlending(int alpha);
    void alphaBlendingForThreeLayers(int alpha);
    void multiplyMode();
    void screenMode();
    void overlayMode();
    void darkenMode();
    void lightenMode();
    void differenceMode();
    void additiveMode();
    void subtractiveMode();
    void multiplyModeForThreeLayers();
    void screenModeForThreeLayers();
    void overlayModeForThreeLayers();
    void darkenModeForThreeLayers();
    void lightenModeForThreeLayers();
    void differenceModeForThreeLayers();
    void additiveModeForThreeLayers();
    void subtractiveModeForThreeLayers();
};

#endif // BLENDMODESCANVAS_H
