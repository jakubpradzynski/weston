#ifndef SCANELINECANVAS_H
#define SCANELINECANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QPushButton>
#include <math.h>
#include <algorithm>
#include "mycanvas.h"
#include "point.h"
#include "rgb.h"
#include "beziercurveoption.cpp"

class ScaneLineCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit ScaneLineCanvas(QWidget *parent = nullptr);

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
    void draw(); // Method draw polygon using scan line algorithm

private:
    QSize canvasSize = QSize(650, 500); // Setting canvas size
    QImage qImage; // Place to draw
    BezierCurveOption bezierCurveOption = ADD_POINT; // Starting option is add point
    RGB brushRGB; // Brush color
    std::vector<Point> pointsVector; // All added points
    int slidePointIndex; // Index of point in pointsVector which will be slide
    int removePointIndex; // Index of point in pointsVector which will be remove
    int pointSize; // Point size value
    bool wasDrawing; // Check if polygon has been already drawn
    void putPixel(Point point, RGB rgb); // Method draw single pixel
    void drawHorizontalLine(Point start, Point end, RGB rgb); // Draw horizontal line
    int findNearestPointIndex(Point point); // Find index in pointsVector of nearest point to point variable
    void drawAllPoints(std::vector<Point> points, RGB rgb, int size = 1); // Draw all points from pointsVector in specific size
    static bool sortPointsByXValue(Point p1, Point p2); // Sort points vector by x value
    void drawPolygonUsingScaneLine(std::vector<Point> polygon, RGB rgb); // Draw polygon using scan line algorithm
    std::vector<Point> removeBadPointsFromVector(std::vector<Point> points); // Remove incorrect points from vector
};

#endif // SCANELINECANVAS_H
