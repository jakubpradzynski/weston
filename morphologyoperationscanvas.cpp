#include "morphologyoperationscanvas.h"

MorphologyOperationsCanvas::MorphologyOperationsCanvas(QWidget *parent) : QWidget(parent)
{
    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::white);
    repaintFromOneQImageToSecond(&painting, &qImage);
    qImage.convertToFormat(QImage::Format_RGB32);
//    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
//    qImage.loadFromData(QByteArray::fromStdString("/Users/jakub.pradzynski/Prywatne/Nauka/LGiM/weston/example.jpg"));
}

void MorphologyOperationsCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    // Drawing qImage on canvas using qPainter
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::white);
    qPainter.drawImage(0, 0, qImage);
}

void MorphologyOperationsCanvas::putDilation()
{
    QImage newQImage = dilation(kernelSize);
    qImage = newQImage;
    update();
}

void MorphologyOperationsCanvas::putErosion()
{
    QImage newQImage = erosion(kernelSize);
    qImage = newQImage;
    update();
}

void MorphologyOperationsCanvas::repaintFromOneQImageToSecond(QImage *first, QImage *second)
{
    for(int x = 0; x <= second->width(); x++) {
        for(int y = 0; y <= second->height(); y++) {
            putPixel(second, Point(x, y), RGB(255, 255, 255));
        }
    }
    for(int x = 0; x < first->width(); x++) {
        for(int y = 0; y < first->height(); y++) {
            putPixel(second, Point(x, y), getPointColor(first, Point(x, y)));
        }
    }
}

// Method drawing single pixel
void MorphologyOperationsCanvas::putPixel(Point point, RGB rgb)
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

void MorphologyOperationsCanvas::putPixel(QImage *qImage, Point point, RGB rgb)
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

QImage MorphologyOperationsCanvas::dilation(int kernelSize)
{
    QImage *newQImage = new QImage(qImage.width(), qImage.height(), QImage::Format_RGB32);
    for (int x = 0; x < qImage.width(); x++) {
        for (int y = 0; y < qImage.height(); y++) {
            putKernelForDilation(newQImage, Point(x, y), kernelSize);
        }
    }
    return *newQImage;
}

RGB MorphologyOperationsCanvas::getPointColor(Point point)
{
    int r, g, b;
    QColor qColor = qImage.pixel(point.getX(), point.getY());
    qColor.getRgb(&r, &g, &b);
    return RGB(r, g, b);
}

RGB MorphologyOperationsCanvas::getPointColor(QImage *qImage, Point point)
{
    int r, g, b;
    QColor qColor = qImage->pixel(point.getX(), point.getY());
    qColor.getRgb(&r, &g, &b);
    return RGB(r, g, b);
}

void MorphologyOperationsCanvas::clearCanvas()
{
    repaintFromOneQImageToSecond(&painting, &qImage);
    update();
}

void MorphologyOperationsCanvas::putKernelForDilation(QImage *newQImage, Point point, int kernelSize)
{
    for (int x = point.getX() - kernelSize; x <= point.getX() + kernelSize; x++) {
        for (int y = point.getY() - kernelSize; y <= point.getY() + kernelSize; y++) {
            if (x < 0 || y < 0 || x >= newQImage->width() || y >= newQImage->height()) {
                continue;
            }
            RGB otherRGB = getPointColor(Point(x, y));
            if (otherRGB != RGB(255, 255, 255)) {
                putPixel(newQImage, point, RGB(0, 0, 0));
                return;
            }
        }
    }
    putPixel(newQImage, point, RGB(255, 255, 255));
}

QImage MorphologyOperationsCanvas::erosion(int kernelSize)
{
    QImage *newQImage = new QImage(qImage.width(), qImage.height(), QImage::Format_RGB32);
    for (int x = 0; x < qImage.width(); x++) {
        for (int y = 0; y < qImage.height(); y++) {
            if (putKernelForErosion(newQImage, Point(x, y), kernelSize) == true) {
                putPixel(newQImage, Point(x, y), RGB(0, 0, 0));
            } else {
                putPixel(newQImage, Point(x, y), RGB(255, 255, 255));
            }
        }
    }
    return *newQImage;
}

bool MorphologyOperationsCanvas::putKernelForErosion(QImage *newQImage, Point point, int kernelSize)
{
    for (int x = point.getX() - kernelSize; x <= point.getX() + kernelSize; x++) {
        for (int y = point.getY() - kernelSize; y <= point.getY() + kernelSize; y++) {
            if (x < 0 || y < 0 || x >= newQImage->width() || y >= newQImage->height()) {
                return false;
            }
            RGB otherRGB = getPointColor(Point(x, y));
            if (otherRGB != RGB(0, 0, 0)) {
                return false;
            }
        }
    }
    return true;
}




