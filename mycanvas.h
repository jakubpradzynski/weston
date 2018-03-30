#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "point.h"
#include "rgb.h"
#include "option.cpp"
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QPushButton>
#include <math.h>
#include <QWidget>

class MyCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit MyCanvas(QWidget *parent = nullptr);

protected:
    // Events
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:
    void changeOption(); // Method changing what tools will be used next after user interaction
    void clearCanvas(); // Method cleaning canvas
    void changeBrushRValue(int); // Method for changing global brush r value
    void changeBrushGValue(int); // Method for changing global brush g value
    void changeBrushBValue(int); // Method for changing global brush b value
    void rotateEllipse(int); // Method rotating ellipse using horizontal slider

private:
    QSize canvasSize = QSize(650, 500); // Setting canvas size
    QImage qImage; // Place to draw
    Option option = PENCIL; // First tool is pencil
    Point start; // Global point which change on mouse press event
    Point end; // Global point which change after mouse release event
    RGB brushRGB; // Brush color
    void putPixel(Point point, RGB rgb); // Method draw single pixel
    void spray(Point point, RGB rgb); // Spray method
    void drawHorizontalLine(Point start, Point end, RGB rgb); // Draw horizontal line
    void drawRectangle(Point start, Point end, RGB rgb); // Draw rectangle
    void drawLineByBrasenhamsAlgorithm(Point start, Point end, RGB rgb); // Draw line using Brasenham's Algorithms
    void drawLineUsingLinearInterpolation(Point start, Point end, RGB rgb); // Draw line using linear interpolation
    void drawLineUsingNaiveAlgorithm(Point start, Point end, RGB rgb); // Draw line using naive algorithm
    void drawCircle(Point center, int radius, RGB rgb); // Draw empty circle
    int calculateRadius(Point start, Point end); // Return radius for circles
    void drawFilledCircle(Point center, int radius, RGB rgb); // Draw filled circle
    void drawCircleUsingParametricCircleEquation(Point center, int radius, RGB rgb); // Draw empty circle using parametric circle equation
    void drawEllipse(Point center, int firstRadius, int secondRadius, RGB rgb); // Draw empty ellipse
    Point calculateCenterPointForEllipse(Point start, Point end); // Calculate center point for ellipse
    int calculateFirstRadiusForEllipse(Point start, Point end); // Calculate first, horizontal radius for ellipse
    int calculateSecondRadiusForEllipse(Point start, Point end); // Calculate first, vertical radius for ellipse
    void drawEllipseWithSlope(Point center, int firstRadius, int secondRadius, int slope, RGB rgb); // Draw ellipse with slope

};

#endif // MYCANVAS_H
