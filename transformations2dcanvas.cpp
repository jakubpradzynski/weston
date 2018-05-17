#include "transformations2dcanvas.h"

Transformations2DCanvas::Transformations2DCanvas(QWidget *parent) : QWidget(parent)
{
    translationX = translationY = rotationAlpha = shearingX = shearingY = 0;
    scalingX = scalingY = 1;
    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::white);
    repaintFromOneQImageToSecond(&image, &qImage, 0, 0);
}

void Transformations2DCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::white);
    qPainter.drawImage(0, 0, qImage);
}

void Transformations2DCanvas::rotationAlphaChanged(int alpha)
{
    rotationAlpha = alpha;
    transform2DImage(&image);
}

void Transformations2DCanvas::scalingXChanged(int x)
{
    scalingX = x;
    transform2DImage(&image);
}

void Transformations2DCanvas::scalingYChanged(int y)
{
    scalingY = y;
    transform2DImage(&image);
}

void Transformations2DCanvas::translationXChanged(int x)
{
    translationX = x;
    transform2DImage(&image);
}

void Transformations2DCanvas::translationYChanged(int y)
{
    translationY = y;
    transform2DImage(&image);
}

void Transformations2DCanvas::shearingXChanged(int x)
{
    shearingX = x;
    transform2DImage(&image);
}

void Transformations2DCanvas::shearingYChanged(int y)
{
    shearingY = y;
    transform2DImage(&image);
}

void Transformations2DCanvas::repaintFromOneQImageToSecond(QImage *first, QImage *second, int X, int Y)
{
    for(int x = 0; x <= second->width(); x++) {
        for(int y = 0; y <= second->height(); y++) {
            putPixel(second, Point(x, y), RGB(255, 255, 255));
        }
    }
    for(int x = 0; x < first->width(); x++) {
        for(int y = 0; y < first->height(); y++) {
            putPixel(second, Point(x + X, y + Y), getPointColor(first, Point(x, y)));
        }
    }
}

void Transformations2DCanvas::putPixel(QImage *qImage, Point point, RGB rgb)
{
    if (point.getX() < 0 || point.getY() < 0 || point.getX() >= qImage->width() || point.getY() >= qImage->height()) {
        return;
    }
    uchar *pix = qImage->scanLine(point.getY());
    pix[4 * point.getX()] = rgb.getB();
    pix[4 * point.getX() + 1] = rgb.getG();
    pix[4 * point.getX() + 2] = rgb.getR();
    update();
}

RGB Transformations2DCanvas::getPointColor(QImage *qImage, Point point)
{
    int r, g, b;
    QColor qColor = qImage->pixel(point.getX(), point.getY());
    qColor.getRgb(&r, &g, &b);
    return RGB(r, g, b);
}

QImage Transformations2DCanvas::transform2DImage(QImage *image)
{
    qImage.fill(Qt::white);
    update();
    for (int x = 0; x < image->width(); x++) {
        for (int y = 0; y < image->height(); y++) {
            RGB pointColor = getPointColor(image, Point(x, y));
            if (pointColor != RGB(255, 255, 255)) {
                Point3 point3 = translation(Point3(x, y, 1), translationX, translationY);
                point3 = rotation(point3, rotationAlpha);
                point3 = scaling(point3, scalingX, scalingY);
                point3 = shearing(point3, shearingX, shearingY);
                putPixel(&qImage, Point(point3.getX(), point3.getY()), pointColor);
            }
        }
    }
}

Point3 Transformations2DCanvas::translation(Point3 point3, int x, int y)
{
    return Point3(point3.getX() + x, point3.getY() + y, 1);
}

Point3 Transformations2DCanvas::rotation(Point3 point3, int alpha)
{
    float newAlpha = (float) alpha * M_PI/180;
    return Point3(point3.getX() * cos(newAlpha) - point3.getY() * sin(newAlpha), point3.getX() * sin(newAlpha) + point3.getY() * cos(newAlpha), 1);
}

Point3 Transformations2DCanvas::scaling(Point3 point3, int x, int y)
{
    return Point3(point3.getX() * x, point3.getY() * y, 1);
}

Point3 Transformations2DCanvas::shearing(Point3 point3, int x, int y)
{
    return Point3(point3.getX() + x * point3.getY(), point3.getX() * y + point3.getY(), 1);
}
