#include "mycanvas.h"

#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QPushButton>

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
        qDebug("Started drawing line in this point");
        break;
    case RECTANGLE:
        qDebug("Started drawing rectangle in this point");
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
        drawLineByBrasenhamsAlgorithm(start, end, brushRGB);
        qDebug("Ended drawing line in this point");
        break;
    case RECTANGLE:
        drawRectangle(start, end, brushRGB);
        qDebug("Ended drawing rectangle in this point");
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
