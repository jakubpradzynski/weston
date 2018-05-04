#ifndef COLORMODELCANVAS_H
#define COLORMODELCANVAS_H

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

class ColorModelCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit ColorModelCanvas(QWidget *parent = nullptr);

protected:
    // Events
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void valuesChanged(HSV hsv, RGB rgb);

public slots:
    void changeRValue(int);
    void changeGValue(int);
    void changeBValue(int);
    void changeHValue(int);
    void changeSValue(int);
    void changeVValue(int);

private:
    QSize canvasSize = QSize(650, 500); // Setting canvas size
    QImage qImage; // Place to draw
    RGB globalRGB = RGB();
    HSV globalHSV = HSV();
    HSV convertRGBtoHSV(RGB rgb);
    RGB convertHSVtoRGB(HSV hsv);
    float findMinOf3Numbers(float a, float b, float c);
    float findMaxOf3Numbers(float a, float b, float c);
    int findMinOf3Numbers(int a, int b, int c);
    int findMaxOf3Numbers(int a, int b, int c);
};

#endif // COLORMODELCANVAS_H
