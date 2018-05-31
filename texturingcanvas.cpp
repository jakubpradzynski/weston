#include "texturingcanvas.h"

TexturingCanvas::TexturingCanvas(QWidget *parent) : QWidget(parent)
{
    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::white);
    drawTextureOnCanvas(&qImage, &texture);
    update();
}

void TexturingCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::white);
    qPainter.drawImage(0, 0, qImage);
}

void TexturingCanvas::mouseMoveEvent(QMouseEvent *event)
{
    Point mouseMovePoint = Point(event->x(), event->y());
    if (isDraw) {
        qImage.fill(Qt::white);
        drawTextureOnCanvas(&qImage, &texture);
        update();
        if (nearestPoint != -1) {
            pointsVector.at(nearestPoint).setX(mouseMovePoint.getX());
            pointsVector.at(nearestPoint).setY(mouseMovePoint.getY());
            drawAllPoints(&qImage, pointsVector, RGB(0, 255, 0), 3);
            drawAllPoints(&qImage, pointsOnTextureVector, RGB(0, 255, 0), 3);
            drawTexturedTriangle(&qImage, pointsVector, pointsOnTextureVector);
        }
        if (nearestTexturePoint != -1) {
            pointsOnTextureVector.at(nearestTexturePoint).setX(mouseMovePoint.getX());
            pointsOnTextureVector.at(nearestTexturePoint).setY(mouseMovePoint.getY());
            drawAllPoints(&qImage, pointsOnTextureVector, RGB(0, 255, 0), 3);
            drawAllPoints(&qImage, pointsVector, RGB(0, 255, 0), 3);
            drawTexturedTriangle(&qImage, pointsVector, pointsOnTextureVector);
        }
    }
}

void TexturingCanvas::mousePressEvent(QMouseEvent *event)
{
    Point mousePressPoint = Point(event->x(), event->y());
    if (mousePressPoint.getX() < qImage.width() / 2) {
        if (pointsVector.size() < 3) {
            pointsVector.push_back(mousePressPoint);
            drawAllPoints(&qImage, pointsVector, RGB(0, 255, 0), 3);
        }
        if (isDraw) {
            nearestPoint = findNearestPointIndex(mousePressPoint, pointsVector);
            nearestTexturePoint = -1;
        } else {
            if (pointsVector.size() == 3 && pointsOnTextureVector.size() == 3) {
                drawTexturedTriangle(&qImage, pointsVector, pointsOnTextureVector);
                update();
                isDraw = true;
            }
        }
    } else {
        if (pointsOnTextureVector.size() < 3) {
            pointsOnTextureVector.push_back(mousePressPoint);
            drawAllPoints(&qImage, pointsOnTextureVector, RGB(0, 255, 0), 3);
        }
        if (isDraw) {
            nearestTexturePoint = findNearestPointIndex(mousePressPoint, pointsOnTextureVector);
            nearestPoint = -1;
        } else {
            if (pointsOnTextureVector.size() == 3 && pointsVector.size() == 3) {
                drawTexturedTriangle(&qImage, pointsVector, pointsOnTextureVector);
                update();
                isDraw = true;
            }
        }
    }
}

void TexturingCanvas::mouseReleaseEvent(QMouseEvent *event)
{

}

void TexturingCanvas::putPixel(QImage *qImage, Point point, RGB rgb)
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

RGB TexturingCanvas::getPointColor(QImage *qImage, Point point)
{
    int r, g, b;
    QColor qColor = qImage->pixel(point.getX(), point.getY());
    qColor.getRgb(&r, &g, &b);
    return RGB(r, g, b);
}

void TexturingCanvas::drawHorizontalLine(QImage *qImage, Point start, Point end, RGB rgb)
{
    if (end.getX() >= qImage->width()) {
        end.setX(qImage->width());
    }
    if(start.getX() > end.getX()) {
        Point temp = start;
        start = end;
        end = temp;
    }
    for(int i = start.getX(); i < end.getX(); i++) {
        putPixel(qImage, Point(i, start.getY()), rgb);
        update();
    }
}

void TexturingCanvas::drawTriangleUsingScanLine(QImage *qImage, std::vector<Point> points, RGB rgb)
{
    std::vector<Point> sortedPoints = sortPointsByY(points);
    Point A = sortedPoints.at(0);
    Point B = sortedPoints.at(1);
    Point C = sortedPoints.at(2);

    for (int y = A.getY(); y <= B.getY(); y++) {
        float x1, x2;
        x1 = calculateLinearInterpolation(A, B, y);
        x2 = calculateLinearInterpolation(A, C, y);
        drawHorizontalLine(qImage, Point(x1, y), Point(x2, y), rgb);
    }
    for (int y = B.getY(); y <= C.getY(); y++) {
        float x1, x2;
        x1 = calculateLinearInterpolation(B, C, y);
        x2 = calculateLinearInterpolation(A, C, y);
        drawHorizontalLine(qImage, Point(x1, y), Point(x2, y), rgb);
    }
}

std::vector<Point> TexturingCanvas::sortPointsByY(std::vector<Point> points)
{
    std::vector<Point> sortedPoints;
    while (points.size() > 0) {
        int temp = 0;
        for (int j = 0; j < points.size(); j++) {
            if (points.at(j).getY() < points.at(temp).getY()) {
                temp = j;
            }
        }
        sortedPoints.push_back(points.at(temp));
        points.erase(points.begin() + temp);
    }
    return sortedPoints;
}

std::vector<Point> TexturingCanvas::sortPointsByX(std::vector<Point> points)
{
    std::vector<Point> sortedPoints;
    while (points.size() > 0) {
        int temp = 0;
        for (int j = 0; j < points.size(); j++) {
            if (points.at(j).getX() < points.at(temp).getX()) {
                temp = j;
            }
        }
        sortedPoints.push_back(points.at(temp));
        points.erase(points.begin() + temp);
    }
    return sortedPoints;
}

float TexturingCanvas::calculateLinearInterpolation(Point A, Point B, int y)
{
    float alpha = (float) (y - A.getY()) / (B.getY() - A.getY());
    float x = (float) A.getX() + alpha * (B.getX() - A.getX());
    return x;
}

void TexturingCanvas::drawTextureOnCanvas(QImage *qImage, QImage *texture)
{
    for (int y = 0; y < qImage->height(); y++) {
        putPixel(qImage, Point(qImage->width() / 2, y), RGB(0, 0, 0));
    }
    for (int x = 0; x < texture->width(); x++) {
        for (int y = 0; y < texture->height(); y++) {
            putPixel(qImage, Point((qImage->width() / 2) + textureShift.width() + x, textureShift.height() + y), getPointColor(texture, Point(x, y)));
        }
    }
}

void TexturingCanvas::drawTexturedTriangle(QImage *qImage, std::vector<Point> trianglePoints, std::vector<Point> texturePoint)
{
    std::vector<Point> sortedPoints = sortPointsByY(trianglePoints);
//    texturePoint = sortPointsByY(texturePoint);
    Four X1 = Four(sortedPoints.at(0).getX(), sortedPoints.at(0).getY(), (float) (texturePoint.at(0).getX() - (qImage->width() / 2)) / 1000, (float) texturePoint.at(0).getY() / 1000);
    Four X2 = Four(sortedPoints.at(1).getX(), sortedPoints.at(1).getY(), (float) (texturePoint.at(1).getX() - (qImage->width() / 2)) / 1000, (float) texturePoint.at(1).getY() / 1000);
    Four X3 = Four(sortedPoints.at(2).getX(), sortedPoints.at(2).getY(), (float) (texturePoint.at(2).getX() - (qImage->width() / 2)) / 1000, (float) texturePoint.at(2).getY() / 1000);
    for (int y = X1.getY(); y <= X2.getY(); y++) {
        float alphaLeft = (float) (y - X1.getY()) / (X2.getY() - X1.getY());
        float alphaRight = (float) (y - X1.getY()) / (X3.getY() - X1.getY());
        float x1, x2, u1, u2, v1, v2;
        x1 = linearInterpolation(alphaLeft, X1.getX(), X2.getX());
        u1 = linearInterpolation(alphaLeft, X1.getU(), X2.getU());
        v1 = linearInterpolation(alphaLeft, X1.getV(), X2.getV());
        x2 = linearInterpolation(alphaRight, X1.getX(), X3.getX());
        u2 = linearInterpolation(alphaRight, X1.getU(), X3.getU());
        v2 = linearInterpolation(alphaRight, X1.getV(), X3.getV());
        drawHorizontalTexturedLine(qImage, Four(x1, y, u1, v1), Four(x2, y, u2, v2));
    }
    for (int y = X2.getY(); y <= X3.getY(); y++) {
        float alphaLeft = (float) (y - X2.getY()) / (X3.getY() - X2.getY());
        float alphaRight = (float) (y - X1.getY()) / (X3.getY() - X1.getY());
        float x1, x2, u1, u2, v1, v2;
        x1 = linearInterpolation(alphaLeft, X2.getX(), X3.getX());
        u1 = linearInterpolation(alphaLeft, X2.getU(), X3.getU());
        v1 = linearInterpolation(alphaLeft, X2.getV(), X3.getV());
        x2 = linearInterpolation(alphaRight, X1.getX(), X3.getX());
        u2 = linearInterpolation(alphaRight, X1.getU(), X3.getU());
        v2 = linearInterpolation(alphaRight, X1.getV(), X3.getV());
        drawHorizontalTexturedLine(qImage, Four(x1, y, u1, v1), Four(x2, y, u2, v2));
    }
}

void TexturingCanvas::drawHorizontalTexturedLine(QImage *qImage, Four X1, Four X2)
{
    if (X2.getX() < X1.getX()) {
        Four temp = X1;
        X1 = X2;
        X2 = temp;
    }
    if (X1.getX() == X2.getX()) return;
    for (int x = X1.getX(); x < X2.getX(); x++) {
        float alpha = ((((float) x) - X1.getX()) / (X2.getX() - X1.getX()));
        float u = (X1.getU() + alpha * (X2.getU() - X1.getU()));
        float v = (X1.getV() + alpha * (X2.getV() - X1.getV()));
        RGB color = getTextureColor(qImage, u * 1000 + (qImage->width() / 2), v * 1000);
        putPixel(qImage, Point((int) x, (int) X1.getY()), color);
    }
}

float TexturingCanvas::linearInterpolation(float alpha, float x1, float x2)
{
    return x1 + alpha * (x2 - x1);
}

int TexturingCanvas::findNearestPointIndex(Point point, std::vector<Point> points)
{
    int index = 0;
    Point nearestPoint = points.at(index);
    double nearestDistance = abs(sqrt(pow(point.getX() - nearestPoint.getX(), 2) + pow(point.getY() - nearestPoint.getY(), 2)));
    for (int i = 1; i < points.size(); i++) {
        double distance = abs(sqrt(pow(point.getX() - points.at(i).getX(), 2) + pow(point.getY() - points.at(i).getY(), 2)));
        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearestPoint = points.at(i);
            index = i;
        }
    }
    return index;
}

void TexturingCanvas::drawAllPoints(QImage *qImage, std::vector<Point> points, RGB rgb, int size)
{
    foreach (Point singlePoint, points) {
        putPixel(qImage, singlePoint, rgb);
        if (size > 1) {
            for (int i = -size + 1; i <= size - 1; i++) {
                drawHorizontalLine(qImage, Point(singlePoint.getX() - size + 1, singlePoint.getY() + i), Point(singlePoint.getX() + size, singlePoint.getY() + i), rgb);
            }
        }
    }
}

void TexturingCanvas::clearHalfOfCanvas(QImage *qImage)
{
    for (int i = 0; i < qImage->width() / 2; i++) {
        for (int j = 0; j < qImage->height(); j++) {
            putPixel(qImage, Point(i, j), RGB(255, 255, 255));
        }
    }
}

RGB TexturingCanvas::getTextureColor(QImage *qImage, float x, float y)
{
    float r, g, b;
    float a, c;
    Point P1 = Point(x, y + 1);
    Point P2 = Point(x + 1, y + 1);
    Point P3 = Point(x + 1, y);
    Point P4 = Point(x, y);
    RGB p1RGB = getPointColor(qImage, P1);
    RGB p2RGB = getPointColor(qImage, P2);
    RGB p3RGB = getPointColor(qImage, P3);
    RGB p4RGB = getPointColor(qImage, P4);
    a = x - (float) P1.getX();
    c = y - (float) P4.getY();
    r = (float) c * ((1 - a) * p1RGB.getR() + a * p2RGB.getR()) + (1 - c) * ((1 - a) * p4RGB.getR() + a * p3RGB.getR());
    g = (float) c * ((1 - a) * p1RGB.getG() + a * p2RGB.getG()) + (1 - c) * ((1 - a) * p4RGB.getG() + a * p3RGB.getG());
    b = (float) c * ((1 - a) * p1RGB.getB() + a * p2RGB.getB()) + (1 - c) * ((1 - a) * p4RGB.getB() + a * p3RGB.getB());
    return RGB(r, g, b);
}

float TexturingCanvas::round(float x)
{
    return floor(x + 0.5);
}




