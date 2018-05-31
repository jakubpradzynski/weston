#ifndef TEXTURINGCANVAS_H
#define TEXTURINGCANVAS_H

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
#include "floatpoint.h"
#include "four.h"

class TexturingCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit TexturingCanvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:

private:
    QSize canvasSize = QSize(1100, 620);
    QSize textureShift = QSize(0, 0);
    QImage qImage;
    QImage texture = QImage("texture.bmp");
    bool isDraw = false;
    int nearestPoint = -1;
    int nearestTexturePoint = -1;
    std::vector<Point> pointsVector;
    std::vector<Point> pointsOnTextureVector;
    void putPixel(QImage *qImage, Point point, RGB rgb);
    RGB getPointColor(QImage *qImage, Point point);
    void drawHorizontalLine(QImage *qImage, Point start, Point end, RGB rgb);
    void drawTriangleUsingScanLine(QImage *qImage, std::vector<Point> points, RGB rgb);
    std::vector<Point> sortPointsByY(std::vector<Point> points);
    std::vector<Point> sortPointsByX(std::vector<Point> points);
    float calculateLinearInterpolation(Point A, Point B, int y);
    void drawTextureOnCanvas(QImage *qImage, QImage *texture);
    void drawTexturedTriangle(QImage *qImage, std::vector<Point> trianglePoints, std::vector<Point> texturePoint);
    void drawHorizontalTexturedLine(QImage *qImage, Four X1, Four X2);
    float linearInterpolation(float alpha, float x1, float x2);
    int findNearestPointIndex(Point point, std::vector<Point> points);
    void drawAllPoints(QImage *qImage, std::vector<Point> points, RGB rgb, int size = 1);
    void clearHalfOfCanvas(QImage *qImage);
    RGB getTextureColor(QImage *qImage, float x, float y);
    float round(float x);
};

#endif // TEXTURINGCANVAS_H
