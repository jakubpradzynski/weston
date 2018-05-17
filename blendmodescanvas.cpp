#include "blendmodescanvas.h"

BlendModesCanvas::BlendModesCanvas(QWidget *parent) : QWidget(parent)
{
    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::white);
//    repaintFromOneQImageToSecond(&painting, &qImage);
    qImage.convertToFormat(QImage::Format_RGB32);
}

void BlendModesCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::white);
    qPainter.drawImage(0, 0, qImage);
}

void BlendModesCanvas::showLayerOne()
{
    repaintFromOneQImageToSecond(&layerOne, &qImage);
}

void BlendModesCanvas::showLayerTwo()
{
    repaintFromOneQImageToSecond(&layerTwo, &qImage);
}

void BlendModesCanvas::showLayerThree()
{
    repaintFromOneQImageToSecond(&layerThree, &qImage);
}

void BlendModesCanvas::clearCanvas()
{
    qImage.fill(Qt::white);
    update();
}

void BlendModesCanvas::applyAlphaBlending(int alpha)
{
    alphaForTwoLayers = alpha;
//    alphaBlending(alpha);
}

void BlendModesCanvas::applyAlphaBlendingForThreeLayers(int alpha)
{
    alphaForThreeLayers = alpha;
//    alphaBlendingForThreeLayers(alpha);
}

void BlendModesCanvas::applyMultiplyMode()
{
    QImage imagesArray[] = {layerOne, layerTwo};
    QImage newImage = blendMode(imagesArray, 2, BlendModesCanvas::multiplyMode, alphaForTwoLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyScreenMode()
{
    QImage imagesArray[] = {layerOne, layerTwo};
    QImage newImage = blendMode(imagesArray, 2, BlendModesCanvas::screenMode, alphaForTwoLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyOverlayMode()
{
    QImage imagesArray[] = {layerOne, layerTwo};
    QImage newImage = blendMode(imagesArray, 2, BlendModesCanvas::overlayMode, alphaForTwoLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyDarkenMode()
{
    QImage imagesArray[] = {layerOne, layerTwo};
    QImage newImage = blendMode(imagesArray, 2, BlendModesCanvas::darkenMode, alphaForTwoLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyLightenMode()
{
    QImage imagesArray[] = {layerOne, layerTwo};
    QImage newImage = blendMode(imagesArray, 2, BlendModesCanvas::lightenMode, alphaForTwoLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyDifferenceMode()
{
    QImage imagesArray[] = {layerOne, layerTwo};
    QImage newImage = blendMode(imagesArray, 2, BlendModesCanvas::differenceMode, alphaForTwoLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyAdditiveMode()
{
    QImage imagesArray[] = {layerOne, layerTwo};
    QImage newImage = blendMode(imagesArray, 2, BlendModesCanvas::additiveMode, alphaForTwoLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applySubtractiveMode()
{
    QImage imagesArray[] = {layerOne, layerTwo};
    QImage newImage = blendMode(imagesArray, 2, BlendModesCanvas::subtractiveMode, alphaForTwoLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyMultiplyModeForThreeLayers()
{
    QImage imagesArray[] = {layerOne, layerTwo, layerThree};
    QImage newImage = blendMode(imagesArray, 3, BlendModesCanvas::multiplyMode, alphaForThreeLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyScreenModeForThreeLayers()
{
    QImage imagesArray[] = {layerOne, layerTwo, layerThree};
    QImage newImage = blendMode(imagesArray, 3, BlendModesCanvas::screenMode, alphaForThreeLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyOverlayModeForThreeLayers()
{
    QImage imagesArray[] = {layerOne, layerTwo, layerThree};
    QImage newImage = blendMode(imagesArray, 3, BlendModesCanvas::overlayMode, alphaForThreeLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyDarkenModeForThreeLayers()
{
    QImage imagesArray[] = {layerOne, layerTwo, layerThree};
    QImage newImage = blendMode(imagesArray, 3, BlendModesCanvas::darkenMode, alphaForThreeLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyLightenModeForThreeLayers()
{
    QImage imagesArray[] = {layerOne, layerTwo, layerThree};
    QImage newImage = blendMode(imagesArray, 3, BlendModesCanvas::lightenMode, alphaForThreeLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyDifferenceModeForThreeLayers()
{
    QImage imagesArray[] = {layerOne, layerTwo, layerThree};
    QImage newImage = blendMode(imagesArray, 3, BlendModesCanvas::differenceMode, alphaForThreeLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applyAdditiveModeForThreeLayers()
{
    QImage imagesArray[] = {layerOne, layerTwo, layerThree};
    QImage newImage = blendMode(imagesArray, 3, BlendModesCanvas::additiveMode, alphaForThreeLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::applySubtractiveModeForThreeLayers()
{
    QImage imagesArray[] = {layerOne, layerTwo, layerThree};
    QImage newImage = blendMode(imagesArray, 3, BlendModesCanvas::subtractiveMode, alphaForThreeLayers);
    repaintFromOneQImageToSecond(&newImage, &qImage);
    update();
}

void BlendModesCanvas::repaintFromOneQImageToSecond(QImage *first, QImage *second)
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

void BlendModesCanvas::putPixel(Point point, RGB rgb)
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

void BlendModesCanvas::putPixel(QImage *qImage, Point point, RGB rgb)
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

RGB BlendModesCanvas::getPointColor(Point point)
{
    int r, g, b;
    QColor qColor = qImage.pixel(point.getX(), point.getY());
    qColor.getRgb(&r, &g, &b);
    return RGB(r, g, b);
}

RGB BlendModesCanvas::getPointColor(QImage *qImage, Point point)
{
    int r, g, b;
    QColor qColor = qImage->pixel(point.getX(), point.getY());
    qColor.getRgb(&r, &g, &b);
    return RGB(r, g, b);
}

RGB BlendModesCanvas::alphaBlending(RGB layerOneRgb, RGB layerTwoRgb, int alpha)
{
    float a = (float) alpha / 100;
    return RGB(
                a * layerTwoRgb.getR() + (1 - a) * layerOneRgb.getR(),
                a * layerTwoRgb.getG() + (1 - a) * layerOneRgb.getG(),
                a * layerTwoRgb.getB() + (1 - a) * layerOneRgb.getB()
                );
}

QImage BlendModesCanvas::alphaBlending(QImage images[], int size, int alpha)
{
    int i = 0;
    QImage newImage = images[i];
    float a = (float) alpha / 100;
    for (; i < size - 1; i++) {
        for(int x = 0; x < newImage.width(); x++) {
            for(int y = 0; y < newImage.height(); y++) {
                RGB layerOneRgb = getPointColor(&newImage, Point(x, y));
                RGB layerTwoRgb = getPointColor(&images[i + 1], Point(x, y));
                RGB newRgb = RGB(
                            a * layerTwoRgb.getR() + (1 - a) * layerOneRgb.getR(),
                            a * layerTwoRgb.getG() + (1 - a) * layerOneRgb.getG(),
                            a * layerTwoRgb.getB() + (1 - a) * layerOneRgb.getB()
                            );
                putPixel(&newImage, Point(x, y), newRgb);
            }
        }
    }
    return newImage;
}

QImage BlendModesCanvas::blendMode(QImage images[], int size, RGB (BlendModesCanvas::*modeFunction)(RGB, RGB), int alpha)
{
    int i = 0;
    QImage newImage = QImage(images[0].width(), images[0].height(), QImage::Format_RGB32);
    repaintFromOneQImageToSecond(&images[0], &newImage);
    for (; i < size - 1; i++) {
        for(int x = 0; x < newImage.width(); x++) {
            for(int y = 0; y < newImage.height(); y++) {
                RGB layerOneRgb = getPointColor(&newImage, Point(x, y));
                RGB layerTwoRgb = getPointColor(&images[i + 1], Point(x, y));
                RGB newRgb = (this->*modeFunction)(layerOneRgb, layerTwoRgb);
                newRgb = alphaBlending(layerOneRgb, newRgb, alpha);
                putPixel(&newImage, Point(x, y), newRgb);
            }
        }
    }
    return newImage;
}

RGB BlendModesCanvas::multiplyMode(RGB layerOneRgb, RGB layerTwoRgb)
{
    return RGB((layerOneRgb.getR() * layerTwoRgb.getR()) >> 8,
               (layerOneRgb.getG() * layerTwoRgb.getG()) >> 8,
               (layerOneRgb.getB() * layerTwoRgb.getB()) >> 8
               );
}

RGB BlendModesCanvas::screenMode(RGB layerOneRgb, RGB layerTwoRgb)
{
    return RGB(255 - ((255 - layerOneRgb.getR()) * (255 - layerTwoRgb.getR()) >> 8),
               255 - ((255 - layerOneRgb.getG()) * (255 - layerTwoRgb.getG()) >> 8),
               255 - ((255 - layerOneRgb.getB()) * (255 - layerTwoRgb.getB()) >> 8)
               );
}

RGB BlendModesCanvas::overlayMode(RGB layerOneRgb, RGB layerTwoRgb)
{
    return RGB((layerOneRgb.getR() < 128) ? ((layerOneRgb.getR() * layerTwoRgb.getR()) >> 7) : (255 - ((255 - layerOneRgb.getR()) * (255 - layerTwoRgb.getR()) >> 7)),
               (layerOneRgb.getG() < 128) ? ((layerOneRgb.getG() * layerTwoRgb.getG()) >> 7) : (255 - ((255 - layerOneRgb.getG()) * (255 - layerTwoRgb.getG()) >> 7)),
               (layerOneRgb.getB() < 128) ? ((layerOneRgb.getB() * layerTwoRgb.getB()) >> 7) : (255 - ((255 - layerOneRgb.getB()) * (255 - layerTwoRgb.getB()) >> 7))
               );
}

RGB BlendModesCanvas::darkenMode(RGB layerOneRgb, RGB layerTwoRgb)
{
    return RGB((layerOneRgb.getR() > layerTwoRgb.getR()) ? layerOneRgb.getR() : layerTwoRgb.getR(),
               (layerOneRgb.getG() > layerTwoRgb.getG()) ? layerOneRgb.getG() : layerTwoRgb.getG(),
               (layerOneRgb.getB() > layerTwoRgb.getB()) ? layerOneRgb.getB() : layerTwoRgb.getB()
               );
}

RGB BlendModesCanvas::lightenMode(RGB layerOneRgb, RGB layerTwoRgb)
{
    return RGB((layerOneRgb.getR() < layerTwoRgb.getR()) ? layerOneRgb.getR() : layerTwoRgb.getR(),
               (layerOneRgb.getG() < layerTwoRgb.getG()) ? layerOneRgb.getG() : layerTwoRgb.getG(),
               (layerOneRgb.getB() < layerTwoRgb.getB()) ? layerOneRgb.getB() : layerTwoRgb.getB()
               );
}

RGB BlendModesCanvas::differenceMode(RGB layerOneRgb, RGB layerTwoRgb)
{
    return RGB(abs(layerOneRgb.getR() - layerTwoRgb.getR()),
               abs(layerOneRgb.getG() - layerTwoRgb.getG()),
               abs(layerOneRgb.getB() - layerTwoRgb.getB())
               );
}

RGB BlendModesCanvas::additiveMode(RGB layerOneRgb, RGB layerTwoRgb)
{
    return RGB(std::min(layerOneRgb.getR() + layerTwoRgb.getR(), 255),
               std::min(layerOneRgb.getG() + layerTwoRgb.getG(), 255),
               std::min(layerOneRgb.getB() + layerTwoRgb.getB(), 255)
               );
}

RGB BlendModesCanvas::subtractiveMode(RGB layerOneRgb, RGB layerTwoRgb)
{
    return RGB(std::max(layerOneRgb.getR() + layerTwoRgb.getR() - 255, 0),
               std::max(layerOneRgb.getG() + layerTwoRgb.getG() - 255, 0),
               std::max(layerOneRgb.getB() + layerTwoRgb.getB() - 255, 0)
               );
}
