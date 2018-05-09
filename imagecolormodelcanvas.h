#ifndef IMAGECOLORMODELCANVAS_H
#define IMAGECOLORMODELCANVAS_H

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

class ImageColorModelCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit ImageColorModelCanvas(QWidget *parent = nullptr);

protected:
    // Events
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void valuesChanged(int H, int S, int V);

public slots:
    void changeHValue(int);
    void changeSValue(int);
    void changeVValue(int);

private:
    QSize canvasSize = QSize(650, 500); // Setting canvas size
    QImage qImage; // Place to draw
    QImage painting = QImage("google.png");
    int H = 0, S = 0, V = 0;
    void repaintFromOneQImageToSecond(QImage *first, QImage *second);
    RGB globalRGB = RGB();
    HSV globalHSV = HSV();
    HSV convertRGBtoHSV(RGB rgb);
    RGB convertHSVtoRGB(HSV hsv);
    void putPixel(Point point, RGB rgb);
    void putPixel(QImage *qImage, Point point, RGB rgb);
    RGB getPointColor(Point point);
    RGB getPointColor(QImage *qImage, Point point);
    float findMinOf3Numbers(float a, float b, float c);
    float findMaxOf3Numbers(float a, float b, float c);
    int findMinOf3Numbers(int a, int b, int c);
    int findMaxOf3Numbers(int a, int b, int c);
    void repaintImageWithHSV(QImage *first, QImage *second, int h, int s, int v);
    HSV addValuesToHSV(HSV hsv, int h, int s, int v);
};

#endif // IMAGECOLORMODELCANVAS_H
