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
    QImage layerOne = QImage("D:/GitHub/weston/layerOneV2.png");
    QImage layerTwo = QImage("D:/GitHub/weston/layerTwoV2.png");
    QImage layerThree = QImage("D:/GitHub/weston/layerThreeV2.png");
    int alphaForTwoLayers = 0;
    int alphaForThreeLayers = 0;
    void repaintFromOneQImageToSecond(QImage *first, QImage *second);
    void putPixel(Point point, RGB rgb);
    void putPixel(QImage *qImage, Point point, RGB rgb);
    RGB getPointColor(Point point);
    RGB getPointColor(QImage *qImage, Point point);
    QImage alphaBlending(QImage images[], int size, int alpha);
    RGB alphaBlending(RGB layerOneRgb, RGB layerTwoRgb, int alpha);
    QImage blendMode(QImage images[], int size, RGB (BlendModesCanvas::*modeFunction)(RGB, RGB), int alpha);
    RGB multiplyMode(RGB layerOneRgb, RGB layerTwoRgb);
    RGB screenMode(RGB layerOneRgb, RGB layerTwoRgb);
    RGB overlayMode(RGB layerOneRgb, RGB layerTwoRgb);
    RGB darkenMode(RGB layerOneRgb, RGB layerTwoRgb);
    RGB lightenMode(RGB layerOneRgb, RGB layerTwoRgb);
    RGB differenceMode(RGB layerOneRgb, RGB layerTwoRgb);
    RGB additiveMode(RGB layerOneRgb, RGB layerTwoRgb);
    RGB subtractiveMode(RGB layerOneRgb, RGB layerTwoRgb);
};

#endif // BLENDMODESCANVAS_H
