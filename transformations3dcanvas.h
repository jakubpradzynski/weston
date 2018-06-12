#ifndef TRANSFORMATIONS3DCANVAS_H
#define TRANSFORMATIONS3DCANVAS_H

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
#include <cmath>
#include "floatpoint.h"
#include "four.h"
#include "matrix.h"

class Transformations3DCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit Transformations3DCanvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void translationXChanged(int);
    void translationYChanged(int);
    void translationZChanged(int);
    void scalingXChanged(int);
    void scalingYChanged(int);
    void scalingZChanged(int);
    void rotationXChanged(int);
    void rotationYChanged(int);
    void rotationZChanged(int);
    void perspectiveChanged(int);

private:
    QSize canvasSize = QSize(1100, 800);
    Point centralPoint = Point(canvasSize.width() / 2, canvasSize.height() / 2);
    QImage qImage;
    int translationX, translationY, translationZ, scalingX, scalingY, scalingZ, rotationX, rotationY, rotationZ;
    std::vector<Point3> cubePoints;
    RGB cubeColor = RGB(0, 0, 255);
    int perspective = 50;
    void putPixel(QImage *qImage, Point point, RGB rgb);
    RGB getPointColor(QImage *qImage, Point point);
    void drawHorizontalLine(QImage *qImage, Point start, Point end, RGB rgb);
    void drawLine(QImage *qImage, Point start, Point end, RGB rgb);
    void setCubePoints();
    Matrix getTranslationMatrix(int x, int y, int z);
    Matrix getScalingMatrix(int x, int y, int z);
    Matrix getXRotationMatrix(int xAlpha);
    Matrix getYRotationMatrix(int yAlpha);
    Matrix getZRotationMatrix(int zAlpha);
    Matrix getTransformationMatrix();
    void draw3DCube(QImage *qImage, std::vector<Point3> cubePoints);
    Point calculateProjection(Point3 point3, Point centralPoint, double perspective);
    void drawCubeEdges(QImage *qImage, std::vector<Point3> cubePoints, std::vector<Point> projectionPoints);
};

#endif // TRANSFORMATIONS3DCANVAS_H
