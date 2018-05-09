#include "imagecolormodelcanvas.h"

ImageColorModelCanvas::ImageColorModelCanvas(QWidget *parent) : QWidget(parent)
{
    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::white);
    repaintFromOneQImageToSecond(&painting, &qImage);
    qImage.convertToFormat(QImage::Format_RGB32);
    this->valuesChanged(H, S, V);
}

void ImageColorModelCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    // Drawing qImage on canvas using qPainter
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::white);
    qPainter.drawImage(0, 0, qImage);
}

void ImageColorModelCanvas::mouseMoveEvent(QMouseEvent *event)
{

}

void ImageColorModelCanvas::mousePressEvent(QMouseEvent *event)
{

}

void ImageColorModelCanvas::mouseReleaseEvent(QMouseEvent *event)
{

}

void ImageColorModelCanvas::changeHValue(int h)
{
    H = h;
    repaintImageWithHSV(&painting, &qImage, H, S, V);
    this->valuesChanged(H, S, V);
    update();
}

void ImageColorModelCanvas::changeSValue(int s)
{
    S = s;
    repaintImageWithHSV(&painting, &qImage, H, S, V);
    this->valuesChanged(H, S, V);
    update();
}

void ImageColorModelCanvas::changeVValue(int v)
{
    V = v;
    repaintImageWithHSV(&painting, &qImage, H, S, V);
    this->valuesChanged(H, S, V);
    update();
}

void ImageColorModelCanvas::repaintFromOneQImageToSecond(QImage *first, QImage *second)
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

HSV ImageColorModelCanvas::convertRGBtoHSV(RGB rgb)
{
    float red = (float)rgb.getR() / 255.;
    float grn = (float)rgb.getG() / 255.;
    float blu = (float)rgb.getB() / 255.;
    float x = std::min(std::min(red, grn), blu);
    float val = std::max(std::max(red, grn), blu);
    float f; int i;
    if (x == val) return HSV(0, 0, val * 100);
    else {
        if (red == x) f = grn - blu;
        else if (grn == x) f = blu - red;
        else f = red - grn;
        if (red == x) i = 3;
        else if (grn == x) i = 5;
        else i = 1;
        return HSV((int)((i-f/(val-x))*60)%360, ((val-x)/val) * 100, val * 100);
    }
}

RGB ImageColorModelCanvas::convertHSVtoRGB(HSV hsv)
{
    float hue = hsv.getH();
    float sat = hsv.getS() / 100.;
    float val = hsv.getV() / 100.;
    if (val == 0.) return RGB(0, 0, 0);
    else {
        hue /= 60;
        int i = std::floor(hue);
        float f = hue - i;
        float p = val * (1 - sat);
        float q = val * (1 - (sat * f));
        float t = val * (1 - (sat * (1 - f)));
        p *= 255;
        q *= 255;
        t *= 255;
        val *= 255;
        if (i == 0) return RGB(val, t, p);
        if (i == 1) return RGB(q, val, p);
        if (i == 2) return RGB(p, val, t);
        if (i == 3) return RGB(p, q, val);
        if (i == 4) return RGB(t, p, val);
        if (i == 5) return RGB(val, p, q);
    }
}

float ImageColorModelCanvas::findMinOf3Numbers(float a, float b, float c)
{
    return std::min(a, std::min(b, c));
}

float ImageColorModelCanvas::findMaxOf3Numbers(float a, float b, float c)
{
    return std::max(a, std::max(b, c));
}

int ImageColorModelCanvas::findMinOf3Numbers(int a, int b, int c)
{
    return std::min(a, std::min(b, c));
}

int ImageColorModelCanvas::findMaxOf3Numbers(int a, int b, int c)
{
    return std::max(a, std::max(b, c));
}

void ImageColorModelCanvas::repaintImageWithHSV(QImage *first, QImage *second, int h, int s, int v)
{
    for(int x = 0; x < first->width(); x++) {
        for(int y = 0; y < first->height(); y++) {
            RGB rgb = getPointColor(first, Point(x, y));
            HSV hsv = convertRGBtoHSV(getPointColor(first, Point(x, y)));
            hsv = addValuesToHSV(hsv, h, s, v);
            putPixel(second, Point(x, y), convertHSVtoRGB(hsv));
        }
    }
}

HSV ImageColorModelCanvas::addValuesToHSV(HSV hsv, int h, int s, int v)
{
    HSV newHsv = HSV();
    newHsv.setH(abs((int)(hsv.getH() + h) % 360));
    newHsv.setS(hsv.getS() + s);
    newHsv.setV(hsv.getV() + v);
    if (newHsv.getS() > 100) newHsv.setS(100);
    if (newHsv.getS() < 0) newHsv.setS(0);
    if (newHsv.getV() > 100) newHsv.setV(100);
    if (newHsv.getV() < 0) newHsv.setV(0);
    return newHsv;
}


void ImageColorModelCanvas::putPixel(Point point, RGB rgb)
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

void ImageColorModelCanvas::putPixel(QImage *qImage, Point point, RGB rgb)
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

RGB ImageColorModelCanvas::getPointColor(Point point)
{
    int r, g, b;
    QColor qColor = qImage.pixel(point.getX(), point.getY());
    qColor.getRgb(&r, &g, &b);
    return RGB(r, g, b);
}

RGB ImageColorModelCanvas::getPointColor(QImage *qImage, Point point)
{
    int r, g, b;
    QColor qColor = qImage->pixel(point.getX(), point.getY());
    qColor.getRgb(&r, &g, &b);
    return RGB(r, g, b);
}
