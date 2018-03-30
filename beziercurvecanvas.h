#ifndef BEZIERCURVECANVAS_H
#define BEZIERCURVECANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QPushButton>
#include <math.h>
#include "mycanvas.h"
#include "point.h"
#include "rgb.h"
#include "beziercurveoption.cpp"

class BezierCurveCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit BezierCurveCanvas(QWidget *parent = nullptr);

protected:
    // Events
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:
    void changeOption(); // Method changing what user do after click on canvas while draw Bezier Curve
    void clearCanvas(); // Method clearing canvas
    void clearCanvasAndPoints(); // Method clearing canvas and points in pointsVector
    void changePointSize(int); // Method change point size

private:
    QSize canvasSize = QSize(650, 500); // Setting canvas size
    QImage qImage; // Place to draw
    BezierCurveOption bezierCurveOption = ADD_POINT; // Starting option is add point
    RGB brushRGB; // Brush color
    std::vector<Point> pointsVector; // All added points
    int pointsCounter; // Counter to check if points number is enough to draw next curve
    int slidePointIndex; // Index of point in pointsVector which will be slide
    int removePointIndex; // Index of point in pointsVector which will be remove
    int pointSize; // Point size value
    void putPixel(Point point, RGB rgb); // Method draw single pixel
    void drawHorizontalLine(Point start, Point end, RGB rgb); // Draw horizontal line
    void drawLineUsingNaiveAlgorithm(Point start, Point end, RGB rgb); // Draw line using naive algorithm
    void drawBezierCurveForFourPoints(int firstPointIndex, RGB rgb); // Draw Bezier's curve for four points
    int findNearestPointIndex(Point point); // Find index in pointsVector of nearest point to point variable
    void redrawBezierCurveForEveryPoints(RGB rgb); // Redraw all Bezier's curve which can be draw from points in pointsVector
    void drawAllPoints(RGB rgb, int size = 1); // Draw all points from pointsVector in specific size
};

#endif // BEZIERCURVECANVAS_H
