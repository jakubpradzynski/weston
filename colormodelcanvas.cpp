#include "colormodelcanvas.h"

ColorModelCanvas::ColorModelCanvas(QWidget *parent) : QWidget(parent)
{
    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::black);
    this->valuesChanged(globalHSV, globalRGB);
}

void ColorModelCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    // Drawing qImage on canvas using qPainter
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::black);
    qPainter.drawImage(0, 0, qImage);
}

void ColorModelCanvas::mouseMoveEvent(QMouseEvent *event)
{

}

void ColorModelCanvas::mousePressEvent(QMouseEvent *event)
{

}

void ColorModelCanvas::mouseReleaseEvent(QMouseEvent *event)
{

}

void ColorModelCanvas::changeRValue(int r)
{
    globalRGB.setR(r);
    globalHSV = convertRGBtoHSV(globalRGB);
    this->valuesChanged(globalHSV, globalRGB);
    qImage.fill(qRgb(globalRGB.getR(), globalRGB.getG(), globalRGB.getB()));
    update();
}

void ColorModelCanvas::changeGValue(int g)
{
    globalRGB.setG(g);
    globalHSV = convertRGBtoHSV(globalRGB);
    this->valuesChanged(globalHSV, globalRGB);
    qImage.fill(qRgb(globalRGB.getR(), globalRGB.getG(), globalRGB.getB()));
    update();
}

void ColorModelCanvas::changeBValue(int b)
{
    globalRGB.setB(b);
    globalHSV = convertRGBtoHSV(globalRGB);
    this->valuesChanged(globalHSV, globalRGB);
    qImage.fill(qRgb(globalRGB.getR(), globalRGB.getG(), globalRGB.getB()));
    update();
}

void ColorModelCanvas::changeHValue(int h)
{
    globalHSV.setH(h);
    globalRGB = convertHSVtoRGB(globalHSV);
    this->valuesChanged(globalHSV, globalRGB);
    qImage.fill(qRgb(globalRGB.getR(), globalRGB.getG(), globalRGB.getB()));
    update();
}

void ColorModelCanvas::changeSValue(int s)
{
    globalHSV.setS((float)s);
    globalRGB = convertHSVtoRGB(globalHSV);
    this->valuesChanged(globalHSV, globalRGB);
    qImage.fill(qRgb(globalRGB.getR(), globalRGB.getG(), globalRGB.getB()));
    update();
}

void ColorModelCanvas::changeVValue(int v)
{
    globalHSV.setV((float)v);
    globalRGB = convertHSVtoRGB(globalHSV);
    this->valuesChanged(globalHSV, globalRGB);
    qImage.fill(qRgb(globalRGB.getR(), globalRGB.getG(), globalRGB.getB()));
    update();
}

HSV ColorModelCanvas::convertRGBtoHSV(RGB rgb)
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

RGB ColorModelCanvas::convertHSVtoRGB(HSV hsv)
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

float ColorModelCanvas::findMinOf3Numbers(float a, float b, float c)
{
    return std::min(a, std::min(b, c));
}

float ColorModelCanvas::findMaxOf3Numbers(float a, float b, float c)
{
    return std::max(a, std::max(b, c));
}

int ColorModelCanvas::findMinOf3Numbers(int a, int b, int c)
{
    return std::min(a, std::min(b, c));
}

int ColorModelCanvas::findMaxOf3Numbers(int a, int b, int c)
{
    return std::max(a, std::max(b, c));
}

