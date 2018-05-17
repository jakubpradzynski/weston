#ifndef TRANSFORMATIONS2DCANVAS_H
#define TRANSFORMATIONS2DCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QSlider>
#include <QLabel>
#include "point.h"
#include "point3.h"
#include "rgb.h"
#include "hsv.h"
#include <math.h>


class Transformations2DCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit Transformations2DCanvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void rotationAlphaChanged(int);
    void scalingXChanged(int);
    void scalingYChanged(int);
    void translationXChanged(int);
    void translationYChanged(int);
    void shearingXChanged(int);
    void shearingYChanged(int);

private:
    QSize canvasSize = QSize(650, 500);
    QImage qImage;
    QImage image = QImage("transformations2d.png");
    int translationX, translationY, scalingX, scalingY, rotationAlpha, shearingX, shearingY;
    void repaintFromOneQImageToSecond(QImage *first, QImage *second, int X, int Y);
    void putPixel(QImage *qImage, Point point, RGB rgb);
    RGB getPointColor(QImage *qImage, Point point);
    QImage transform2DImage(QImage *image);
    Point3 translation(Point3 point3, int x, int y);
    Point3 rotation(Point3 point3, int alpha);
    Point3 scaling(Point3 point3, int x, int y);
    Point3 shearing(Point3 point3, int x, int y);
};

#endif // TRANSFORMATIONS2DCANVAS_H
