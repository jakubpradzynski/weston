#include "mycanvas.h"

#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QPushButton>

#include <math.h>

MyCanvas::MyCanvas(QWidget *parent) : QWidget(parent)
{
    // Setting brush color to black
    brushRGB = RGB(0, 0, 0);
    // Settin qImage color and size (place where can draw other elements)
    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::white);
}

void MyCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    // Drawing qImage on canvas using qPainter
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::black);
    qPainter.drawImage(0, 0, qImage);
}

// Switch change what happen (depending on option value) when mouse move
void MyCanvas::mouseMoveEvent(QMouseEvent *event)
{
    end = Point(event->x(), event->y());

    switch (option) {
    case PENCIL:
        putPixel(end, brushRGB);
        break;
    case SPRAY:
        spray(end, brushRGB);
        break;
    case LINE:
        // drawLineByBrasenhamsAlgorithm(start, end, brushRGB);
        break;
    case RECTANGLE:
        drawRectangle(start, end, brushRGB);
        break;
    case CIRCLE:
        break;
    case FILLEDCIRCLE:
        break;
    default:
        break;
    }
}

// Switch change what happen (depending on option value) when mouse press
void MyCanvas::mousePressEvent(QMouseEvent *event)
{
    start = Point(event->x(), event->y());
    qDebug("Press point: (%d, %d)", start.getX(), start.getY());

    switch (option) {
    case PENCIL:
        putPixel(start, brushRGB);
        break;
    case SPRAY:
        spray(start, brushRGB);
        break;
    case LINE:
        break;
    case RECTANGLE:
        break;
    case CIRCLE:
        break;
    case FILLEDCIRCLE:
        break;
    default:
        break;
    }
}

// Switch change what happen (depending on option value) when mouse release
void MyCanvas::mouseReleaseEvent(QMouseEvent *event)
{
    end = Point(event->x(), event->y());
    qDebug("Release point: (%d, %d)", end.getX(), end.getY());

    switch (option) {
    case PENCIL:
        break;
    case SPRAY:
        break;
    case LINE:
        // drawLineByBrasenhamsAlgorithm(start, end, brushRGB);
        // drawLineUsingLinearInterpolation(start, end, brushRGB);
        drawLineUsingNaiveAlgorithm(start, end, brushRGB);
        break;
    case RECTANGLE:
        drawRectangle(start, end, brushRGB);
        break;
    case CIRCLE:
        drawCircle(start, calculateRadius(start, end), brushRGB);
        break;
    case FILLEDCIRCLE:
        drawFilledCircle(start, calculateRadius(start, end), brushRGB);
        break;
    default:
        break;
    }
}

// Method changing option after click on buttons
void MyCanvas::changeOption()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonName = buttonSender->objectName();
    qDebug("%s was clicked", qUtf8Printable(buttonName));
    if(buttonName == "pencilButton") {
        option = PENCIL;
        qDebug("Option changed to %i - PENCIL", option);
    } else if(buttonName == "sprayButton") {
        option = SPRAY;
        qDebug("Option changed to %i - SPRAY", option);
    } else if(buttonName == "lineButton") {
        option = LINE;
        qDebug("Option changed to %i - LINE", option);
    } else if(buttonName == "rectangleButton") {
        option = RECTANGLE;
        qDebug("Option changed to %i - RECTANGLE", option);
    } else if(buttonName == "circleButton") {
        option = CIRCLE;
        qDebug("Option changed to %i - CIRCLE", option);
    } else if(buttonName == "filledCircleButton") {
        option = FILLEDCIRCLE;
        qDebug("Option changed to %i - FILLEDCIRCLE", option);
    } else {
        qDebug("WRONG BUTTTON!");
    }
}

// Clearing canvas
void MyCanvas::clearCanvas()
{
    qImage.fill(Qt::white);
    repaint();
}

// Method's for changing brush color
void MyCanvas::changeBrushRValue(int r)
{
    brushRGB.setR(r);
}

void MyCanvas::changeBrushGValue(int g)
{
    brushRGB.setG(g);
}

void MyCanvas::changeBrushBValue(int b)
{
    brushRGB.setB(b);
}

// Method drawing single pixel in point
void MyCanvas::putPixel(Point point, RGB rgb)
{
    if (point.getX() < 0 || point.getY() < 0 || point.getX() >= qImage.width() || point.getY() >= qImage.height()) {
        return;
    }
    uchar *pix = qImage.scanLine(point.getY());
    pix[4 * point.getX()] = rgb.getB();
    pix[4 * point.getX() + 1] = rgb.getG();
    pix[4 * point.getX() + 2] = rgb.getR();
    update();
}

// Method simulate spray
void MyCanvas::spray(Point point, RGB rgb)
{
    int scope = 20;
    int density = 20;
    putPixel(point, rgb);
    for(int i = 0; i < density; i++) {
        putPixel(Point(point.getX() + rand() % scope, point.getY() + rand() % scope), rgb);
    }
}

// Method drawing horizontal line
void MyCanvas::drawHorizontalLine(Point start, Point end, RGB rgb)
{
    if (end.getX() >= qImage.width()) {
        end.setX(qImage.width());
    }
    for(int i = start.getX(); i < end.getX(); i++) {
        putPixel(Point(i, start.getY()), rgb);
        update();
    }
}

// Method drawing rectangle using method drawing horizontal line
void MyCanvas::drawRectangle(Point start, Point end, RGB rgb)
{
    qDebug("Drawing rectangle");
    Point first = start, second = end;
    if(start.getX() > end.getX()) {
        first.setX(end.getX());
        second.setX(start.getX());
    }
    if(start.getY() > end.getY()) {
        first.setY(end.getY());
        second.setY(start.getY());
    }
    for(int i = first.getY(); i < second.getY(); i++) {
        drawHorizontalLine(Point(first.getX(), i), second, rgb);
    }
}

// Method drawing line using Brasenham's Algorithm
void MyCanvas::drawLineByBrasenhamsAlgorithm(Point start, Point end, RGB rgb)
{
    qDebug("Drawing line using Brasenham's Algorithm");
    Point first = start, second = end;
    if(start.getX() > end.getX()) {
        first.setX(end.getX());
        second.setX(start.getX());
    }
    if(start.getY() > end.getY()) {
        first.setY(end.getY());
        second.setY(start.getY());
    }
    int dx, dy, p, x, y;
    dx = second.getX() - first.getX();
    dy = second.getY() - first.getY();
    x = first.getX();
    y = first.getY();
    p = 2 * dy - dx;
    while(x < second.getX()) {
        if(p >= 0) {
            putPixel(Point(x, y), rgb);
            y += 1;
            p = p + 2*dy - 2*dx;
        } else {
            putPixel(Point(x, y), rgb);
            p = p + 2*dy;
        }
        x += 1;
    }
}

// Method drawing line using linear interpolation
void MyCanvas::drawLineUsingLinearInterpolation(Point start, Point end, RGB rgb)
{
    qDebug("Drawing line using linear interpolation");
    int N = (int)(2 * sqrt(pow(end.getX() - start.getX(), 2) + pow(end.getY() - start.getY(), 2)));
    for (int i = 0; i < N; i++) {
        float a = (float) i / (N - 1);
        float x = start.getX() + a * (end.getX() - start.getX());
        float y = start.getY() + a * (end.getY() - start.getY());
        putPixel(Point(x, y), rgb);
    }
}

// Method drawing line using naive algorithm
void MyCanvas::drawLineUsingNaiveAlgorithm(Point start, Point end, RGB rgb)
{
    qDebug("Drawing line using naive algorithm");
    if(start == end) {
        qDebug("Start point == end point");
        putPixel(start, rgb);
        return;
    }
    float dx = (float) end.getX() - start.getX();
    float dy = (float) end.getY() - start.getY();
    qDebug("Start: (%d, %d), End: (%d, %d)", start.getX(), start.getY(), end.getX(), end.getY());
    qDebug("dx = %f .... dy = %f", dx, dy);
    if (abs(dx) >= abs(dy)) {
        if(start.getX() > end.getX()) {
            Point tmp = start;
            start = end;
            end = tmp;
        }
        for (int x = start.getX(); x <= end.getX(); x++) {
            float y = (float) start.getY() + dy * (x - start.getX()) / dx;
            putPixel(Point(x, y), rgb);
        }
    } else {
        if(start.getY() > end.getY()) {
            Point tmp = start;
            start = end;
            end = tmp;
        }
        for (int y = start.getY(); y <= end.getY(); y++) {
            float x = (float) start.getX() + dx * (y - start.getY()) / dy;
            putPixel(Point(x, y), rgb);
        }
    }
}

// Method drawing empty circle
void MyCanvas::drawCircle(Point center, int radius, RGB rgb)
{
    qDebug("Drawing circle");
    qDebug("Center point = (%d, %d)", center.getX(), center.getY());
    qDebug("Radius = %d", radius);
    for(int y = 0; y <= radius / sqrt(2); y++) {
        float x = sqrt(pow(radius, 2) - pow(y, 2));
        qDebug("(%f, %d)", x, y);
        putPixel(Point(x + center.getX(), y + center.getY()), rgb);
        putPixel(Point(-x + center.getX(), y + center.getY()), rgb);
        putPixel(Point(x + center.getX(), -y + center.getY()), rgb);
        putPixel(Point(-x + center.getX(), -y + center.getY()), rgb);
        putPixel(Point(y + center.getX(), x + center.getY()), rgb);
        putPixel(Point(-y + center.getX(), x + center.getY()), rgb);
        putPixel(Point(y + center.getX(), -x + center.getY()), rgb);
        putPixel(Point(-y + center.getX(), -x + center.getY()), rgb);
    }
}

// Method return radius for circles
int MyCanvas::calculateRadius(Point start, Point end)
{
    float dx = end.getX() - start.getX();
    float dy = end.getY() - start.getY();
    return (int) sqrt(pow(dx, 2) + pow(dy, 2));
}

// Method drawing filled circle
void MyCanvas::drawFilledCircle(Point center, int radius, RGB rgb)
{
    qDebug("Drawing filled circle");
    qDebug("Center point = (%d, %d)", center.getX(), center.getY());
    qDebug("Radius = %d", radius);
    for(int y = 0; y <= radius / sqrt(2); y++) {
        float x = sqrt(pow(radius, 2) - pow(y, 2));
        drawHorizontalLine(Point(-x + center.getX(), y + center.getY()), Point(x + center.getX(), y + center.getY()), rgb);
        drawHorizontalLine(Point(-y + center.getX(), x + center.getY()), Point(y + center.getX(), x + center.getY()), rgb);
        drawHorizontalLine(Point(-y + center.getX(), -x + center.getY()), Point(y + center.getX(), -x + center.getY()), rgb);
        drawHorizontalLine(Point(-x + center.getX(), -y + center.getY()), Point(x + center.getX(), -y + center.getY()), rgb);
    }
}


