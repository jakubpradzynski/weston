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
    alphaBlending(alpha);
}

void BlendModesCanvas::applyAlphaBlendingForThreeLayers(int alpha)
{
    alphaBlendingForThreeLayers(alpha);
}

void BlendModesCanvas::applyMultiplyMode()
{
    multiplyMode();
}

void BlendModesCanvas::applyScreenMode()
{
    screenMode();
}

void BlendModesCanvas::applyOverlayMode()
{
    overlayMode();
}

void BlendModesCanvas::applyDarkenMode()
{
    darkenMode();
}

void BlendModesCanvas::applyLightenMode()
{
    lightenMode();
}

void BlendModesCanvas::applyDifferenceMode()
{
    differenceMode();
}

void BlendModesCanvas::applyAdditiveMode()
{
    additiveMode();
}

void BlendModesCanvas::applySubtractiveMode()
{
    subtractiveMode();
}

void BlendModesCanvas::applyMultiplyModeForThreeLayers()
{
    multiplyModeForThreeLayers();
}

void BlendModesCanvas::applyScreenModeForThreeLayers()
{
    screenModeForThreeLayers();
}

void BlendModesCanvas::applyOverlayModeForThreeLayers()
{
    overlayModeForThreeLayers();
}

void BlendModesCanvas::applyDarkenModeForThreeLayers()
{
    darkenModeForThreeLayers();
}

void BlendModesCanvas::applyLightenModeForThreeLayers()
{
    lightenModeForThreeLayers();
}

void BlendModesCanvas::applyDifferenceModeForThreeLayers()
{
    differenceModeForThreeLayers();
}

void BlendModesCanvas::applyAdditiveModeForThreeLayers()
{
    additiveModeForThreeLayers();
}

void BlendModesCanvas::applySubtractiveModeForThreeLayers()
{
    subtractiveModeForThreeLayers();
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

void BlendModesCanvas::alphaBlending(int alpha)
{
    float a = (float) alpha / 100;
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        a * layerTwoRgb.getR() + (1 - a) * layerOneRgb.getR(),
                        a * layerTwoRgb.getG() + (1 - a) * layerOneRgb.getG(),
                        a * layerTwoRgb.getB() + (1 - a) * layerOneRgb.getB()
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::alphaBlendingForThreeLayers(int alpha)
{
    float a = (float) alpha / 100;
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        a * layerTwoRgb.getR() + (1 - a) * layerOneRgb.getR(),
                        a * layerTwoRgb.getG() + (1 - a) * layerOneRgb.getG(),
                        a * layerTwoRgb.getB() + (1 - a) * layerOneRgb.getB()
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB qImageRgb = getPointColor(&qImage, Point(x, y));
            RGB layerThreeRgb = getPointColor(&layerThree, Point(x, y));
            RGB newRgb = RGB(
                        a * layerThreeRgb.getR() + (1 - a) * qImageRgb.getR(),
                        a * layerThreeRgb.getG() + (1 - a) * qImageRgb.getG(),
                        a * layerThreeRgb.getB() + (1 - a) * qImageRgb.getB()
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::multiplyMode()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        (layerOneRgb.getR() * layerTwoRgb.getR()) >> 8,
                        (layerOneRgb.getG() * layerTwoRgb.getG()) >> 8,
                        (layerOneRgb.getB() * layerTwoRgb.getB()) >> 8
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::screenMode()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        255 - ((255 - layerOneRgb.getR()) * (255 - layerTwoRgb.getR()) >> 8),
                        255 - ((255 - layerOneRgb.getG()) * (255 - layerTwoRgb.getG()) >> 8),
                        255 - ((255 - layerOneRgb.getB()) * (255 - layerTwoRgb.getB()) >> 8)
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::overlayMode()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        (layerOneRgb.getR() < 128) ? ((layerOneRgb.getR() * layerTwoRgb.getR()) >> 7) : (255 - ((255 - layerOneRgb.getR()) * (255 - layerTwoRgb.getR()) >> 7)),
                        (layerOneRgb.getG() < 128) ? ((layerOneRgb.getG() * layerTwoRgb.getG()) >> 7) : (255 - ((255 - layerOneRgb.getG()) * (255 - layerTwoRgb.getG()) >> 7)),
                        (layerOneRgb.getB() < 128) ? ((layerOneRgb.getB() * layerTwoRgb.getB()) >> 7) : (255 - ((255 - layerOneRgb.getB()) * (255 - layerTwoRgb.getB()) >> 7))
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::darkenMode()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        (layerOneRgb.getR() > layerTwoRgb.getR()) ? layerOneRgb.getR() : layerTwoRgb.getR(),
                        (layerOneRgb.getG() > layerTwoRgb.getG()) ? layerOneRgb.getG() : layerTwoRgb.getG(),
                        (layerOneRgb.getB() > layerTwoRgb.getB()) ? layerOneRgb.getB() : layerTwoRgb.getB()
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::lightenMode()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        (layerOneRgb.getR() < layerTwoRgb.getR()) ? layerOneRgb.getR() : layerTwoRgb.getR(),
                        (layerOneRgb.getG() < layerTwoRgb.getG()) ? layerOneRgb.getG() : layerTwoRgb.getG(),
                        (layerOneRgb.getB() < layerTwoRgb.getB()) ? layerOneRgb.getB() : layerTwoRgb.getB()
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::differenceMode()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        abs(layerOneRgb.getR() - layerTwoRgb.getR()),
                        abs(layerOneRgb.getG() - layerTwoRgb.getG()),
                        abs(layerOneRgb.getB() - layerTwoRgb.getB())
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::additiveMode()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        std::min(layerOneRgb.getR() + layerTwoRgb.getR(), 255),
                        std::min(layerOneRgb.getG() + layerTwoRgb.getG(), 255),
                        std::min(layerOneRgb.getB() + layerTwoRgb.getB(), 255)
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::subtractiveMode()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        std::max(layerOneRgb.getR() + layerTwoRgb.getR() - 255, 0),
                        std::max(layerOneRgb.getG() + layerTwoRgb.getG() - 255, 0),
                        std::max(layerOneRgb.getB() + layerTwoRgb.getB() - 255, 0)
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::multiplyModeForThreeLayers()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        (layerOneRgb.getR() * layerTwoRgb.getR()) >> 8,
                        (layerOneRgb.getG() * layerTwoRgb.getG()) >> 8,
                        (layerOneRgb.getB() * layerTwoRgb.getB()) >> 8
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB qImageRgb = getPointColor(&qImage, Point(x, y));
            RGB layerThreeRgb = getPointColor(&layerThree, Point(x, y));
            RGB newRgb = RGB(
                        (qImageRgb.getR() * layerThreeRgb.getR()) >> 8,
                        (qImageRgb.getG() * layerThreeRgb.getG()) >> 8,
                        (qImageRgb.getB() * layerThreeRgb.getB()) >> 8
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::screenModeForThreeLayers()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        255 - ((255 - layerOneRgb.getR()) * (255 - layerTwoRgb.getR()) >> 8),
                        255 - ((255 - layerOneRgb.getG()) * (255 - layerTwoRgb.getG()) >> 8),
                        255 - ((255 - layerOneRgb.getB()) * (255 - layerTwoRgb.getB()) >> 8)
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB qImageRgb = getPointColor(&qImage, Point(x, y));
            RGB layerThreeRgb = getPointColor(&layerThree, Point(x, y));
            RGB newRgb = RGB(
                        255 - ((255 - qImageRgb.getR()) * (255 - layerThreeRgb.getR()) >> 8),
                        255 - ((255 - qImageRgb.getG()) * (255 - layerThreeRgb.getG()) >> 8),
                        255 - ((255 - qImageRgb.getB()) * (255 - layerThreeRgb.getB()) >> 8)
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::overlayModeForThreeLayers()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        (layerOneRgb.getR() < 128) ? ((layerOneRgb.getR() * layerTwoRgb.getR()) >> 7) : (255 - ((255 - layerOneRgb.getR()) * (255 - layerTwoRgb.getR()) >> 7)),
                        (layerOneRgb.getG() < 128) ? ((layerOneRgb.getG() * layerTwoRgb.getG()) >> 7) : (255 - ((255 - layerOneRgb.getG()) * (255 - layerTwoRgb.getG()) >> 7)),
                        (layerOneRgb.getB() < 128) ? ((layerOneRgb.getB() * layerTwoRgb.getB()) >> 7) : (255 - ((255 - layerOneRgb.getB()) * (255 - layerTwoRgb.getB()) >> 7))
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB qImageRgb = getPointColor(&qImage, Point(x, y));
            RGB layerThreeRgb = getPointColor(&layerThree, Point(x, y));
            RGB newRgb = RGB(
                        (qImageRgb.getR() < 128) ? ((qImageRgb.getR() * layerThreeRgb.getR()) >> 7) : (255 - ((255 - qImageRgb.getR()) * (255 - layerThreeRgb.getR()) >> 7)),
                        (qImageRgb.getG() < 128) ? ((qImageRgb.getG() * layerThreeRgb.getG()) >> 7) : (255 - ((255 - qImageRgb.getG()) * (255 - layerThreeRgb.getG()) >> 7)),
                        (qImageRgb.getB() < 128) ? ((qImageRgb.getB() * layerThreeRgb.getB()) >> 7) : (255 - ((255 - qImageRgb.getB()) * (255 - layerThreeRgb.getB()) >> 7))
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::darkenModeForThreeLayers()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        (layerOneRgb.getR() > layerTwoRgb.getR()) ? layerOneRgb.getR() : layerTwoRgb.getR(),
                        (layerOneRgb.getG() > layerTwoRgb.getG()) ? layerOneRgb.getG() : layerTwoRgb.getG(),
                        (layerOneRgb.getB() > layerTwoRgb.getB()) ? layerOneRgb.getB() : layerTwoRgb.getB()
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB qImageRgb = getPointColor(&qImage, Point(x, y));
            RGB layerThreeRgb = getPointColor(&layerThree, Point(x, y));
            RGB newRgb = RGB(
                        (qImageRgb.getR() > layerThreeRgb.getR()) ? qImageRgb.getR() : layerThreeRgb.getR(),
                        (qImageRgb.getG() > layerThreeRgb.getG()) ? qImageRgb.getG() : layerThreeRgb.getG(),
                        (qImageRgb.getB() > layerThreeRgb.getB()) ? qImageRgb.getB() : layerThreeRgb.getB()
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::lightenModeForThreeLayers()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        (layerOneRgb.getR() < layerTwoRgb.getR()) ? layerOneRgb.getR() : layerTwoRgb.getR(),
                        (layerOneRgb.getG() < layerTwoRgb.getG()) ? layerOneRgb.getG() : layerTwoRgb.getG(),
                        (layerOneRgb.getB() < layerTwoRgb.getB()) ? layerOneRgb.getB() : layerTwoRgb.getB()
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB qImageRgb = getPointColor(&qImage, Point(x, y));
            RGB layerThreeRgb = getPointColor(&layerThree, Point(x, y));
            RGB newRgb = RGB(
                        (qImageRgb.getR() < layerThreeRgb.getR()) ? qImageRgb.getR() : layerThreeRgb.getR(),
                        (qImageRgb.getG() < layerThreeRgb.getG()) ? qImageRgb.getG() : layerThreeRgb.getG(),
                        (qImageRgb.getB() < layerThreeRgb.getB()) ? qImageRgb.getB() : layerThreeRgb.getB()
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::differenceModeForThreeLayers()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        abs(layerOneRgb.getR() - layerTwoRgb.getR()),
                        abs(layerOneRgb.getG() - layerTwoRgb.getG()),
                        abs(layerOneRgb.getB() - layerTwoRgb.getB())
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB qImageRgb = getPointColor(&qImage, Point(x, y));
            RGB layerThreeRgb = getPointColor(&layerThree, Point(x, y));
            RGB newRgb = RGB(
                        abs(qImageRgb.getR() - layerThreeRgb.getR()),
                        abs(qImageRgb.getG() - layerThreeRgb.getG()),
                        abs(qImageRgb.getB() - layerThreeRgb.getB())
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::additiveModeForThreeLayers()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        std::min(layerOneRgb.getR() + layerTwoRgb.getR(), 255),
                        std::min(layerOneRgb.getG() + layerTwoRgb.getG(), 255),
                        std::min(layerOneRgb.getB() + layerTwoRgb.getB(), 255)
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB qImageRgb = getPointColor(&qImage, Point(x, y));
            RGB layerThreeRgb = getPointColor(&layerThree, Point(x, y));
            RGB newRgb = RGB(
                        std::min(qImageRgb.getR() + layerThreeRgb.getR(), 255),
                        std::min(qImageRgb.getG() + layerThreeRgb.getG(), 255),
                        std::min(qImageRgb.getB() + layerThreeRgb.getB(), 255)
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}

void BlendModesCanvas::subtractiveModeForThreeLayers()
{
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB layerOneRgb = getPointColor(&layerOne, Point(x, y));
            RGB layerTwoRgb = getPointColor(&layerTwo, Point(x, y));
            RGB newRgb = RGB(
                        std::max(layerOneRgb.getR() + layerTwoRgb.getR() - 255, 0),
                        std::max(layerOneRgb.getG() + layerTwoRgb.getG() - 255, 0),
                        std::max(layerOneRgb.getB() + layerTwoRgb.getB() - 255, 0)
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
    for(int x = 0; x < layerSize.width(); x++) {
        for(int y = 0; y < layerSize.height(); y++) {
            RGB qImageRgb = getPointColor(&qImage, Point(x, y));
            RGB layerThreeRgb = getPointColor(&layerThree, Point(x, y));
            RGB newRgb = RGB(
                        std::max(qImageRgb.getR() + layerThreeRgb.getR() - 255, 0),
                        std::max(qImageRgb.getG() + layerThreeRgb.getG() - 255, 0),
                        std::max(qImageRgb.getB() + layerThreeRgb.getB() - 255, 0)
                        );
            putPixel(Point(x, y), newRgb);
        }
    }
}
