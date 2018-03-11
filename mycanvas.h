#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "point.h"
#include "rgb.h"
#include "option.cpp"

#include <QWidget>

class MyCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit MyCanvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:
    void changeOption();
    void clearCanvas();
    void changeBrushRValue(int);
    void changeBrushGValue(int);
    void changeBrushBValue(int);

private:
    QSize canvasSize = QSize(650, 500); // Setting canvas size
    QImage qImage;
    Option option = PENCIL; // First tool is pencil
    Point start;
    Point end;
    RGB brushRGB; // Brush color
    void putPixel(Point point, RGB rgb); // Method draw single pixel
    void spray(Point point, RGB rgb); // Spray method
    void drawHorizontalLine(Point start, Point end, RGB rgb); // Draw horizontal line
    void drawRectangle(Point start, Point end, RGB rgb); // Draw rectangle
    void drawLineByBrasenhamsAlgorithm(Point start, Point end, RGB rgb); // Draw line using Brasenham's Algorithms
};

#endif // MYCANVAS_H
