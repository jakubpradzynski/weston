#include "beziercurvecanvas.h"

BezierCurveCanvas::BezierCurveCanvas(QWidget *parent) : QWidget(parent)
{
    // Setting brush color to black
    brushRGB = RGB(0, 0, 0);
    // Settin qImage color and size (place where can draw other elements)
    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::white);

    // First initialize private variable
    pointsCounter = 0;
    slidePointIndex = 0;
    removePointIndex = 0;
    pointSize = 1;
}

void BezierCurveCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    // Drawing qImage on canvas using qPainter
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::black);
    qPainter.drawImage(0, 0, qImage);
}

void BezierCurveCanvas::mouseMoveEvent(QMouseEvent *event)
{
    Point mouseReleasePoint = Point(event->x(), event->y());

    switch (bezierCurveOption) {
    case ADD_POINT:
        break;
    case REMOVE_POINT:
        break;
    case SLIDE_POINT:
        // Dynamic slide point with real time view
        if (pointsVector.size() > 0) {
            pointsVector.at(slidePointIndex).setX(mouseReleasePoint.getX());
            pointsVector.at(slidePointIndex).setY(mouseReleasePoint.getY());
            redrawBezierCurveForEveryPoints(brushRGB);
            drawAllPoints(RGB(255, 0, 0), pointSize);
        }
        break;
    default:
         break;
    }
}

void BezierCurveCanvas::mousePressEvent(QMouseEvent *event)
{
    Point mousePressPoint = Point(event->x(), event->y());

    switch (bezierCurveOption) {
    case ADD_POINT:
        // Adding new point with check if should draw next curve
        pointsVector.push_back(mousePressPoint);
        if (pointsVector.size() == 4) {
            drawBezierCurveForFourPoints(0, brushRGB);
            pointsCounter = 4;
        } else if (pointsVector.size() > 3 && pointsVector.size() - pointsCounter == 3) {
            drawBezierCurveForFourPoints(pointsCounter - 1, brushRGB);
            pointsCounter += 3;
        }
        break;
    case REMOVE_POINT:
        // Removing nearest point to press point
        if (pointsVector.size() > 0) {
            removePointIndex = findNearestPointIndex(mousePressPoint);
            pointsVector.erase(pointsVector.begin() + removePointIndex);
            if (pointsVector.size() < pointsCounter) {
                pointsCounter -= 3;
                if (pointsCounter < 4) pointsCounter = 0;
            }
            redrawBezierCurveForEveryPoints(brushRGB);
            drawAllPoints(RGB(255, 0, 0), pointSize);
        } else {
            qDebug("No points on the canvas!");
        }
        break;
    case SLIDE_POINT:
        // Finding nearest point to press point which should be slide
        if (pointsVector.size() > 0) {
            slidePointIndex = findNearestPointIndex(mousePressPoint);
        } else {
            qDebug("No points on the canvas!");
        }
        break;
    default:
        break;
    }
}

void BezierCurveCanvas::mouseReleaseEvent(QMouseEvent *event)
{
//    qDebug("Release point: (%d, %d)", event->x(), event->y());
    Point mouseReleasePoint = Point(event->x(), event->y());

    switch (bezierCurveOption) {
    case ADD_POINT:
        break;
    case REMOVE_POINT:
        break;
    case SLIDE_POINT:
        // End sliding point in this mouse release point
        if (pointsVector.size() > 0) {
            pointsVector.at(slidePointIndex).setX(mouseReleasePoint.getX());
            pointsVector.at(slidePointIndex).setY(mouseReleasePoint.getY());
            redrawBezierCurveForEveryPoints(brushRGB);
            drawAllPoints(RGB(255, 0, 0), pointSize);
        }
        break;
    default:
        break;
    }
}

// Method changing which option is active
void BezierCurveCanvas::changeOption()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonName = buttonSender->objectName();
    qDebug("%s was clicked", qUtf8Printable(buttonName));
    if(buttonName == "addPointButton") {
        bezierCurveOption = ADD_POINT;
        qDebug("Option changed to %i - ADD_POINT", bezierCurveOption);
        redrawBezierCurveForEveryPoints(brushRGB);
    } else if(buttonName == "removePointButton") {
        bezierCurveOption = REMOVE_POINT;
        qDebug("Option changed to %i - REMOVE_POINT", bezierCurveOption);
        drawAllPoints(RGB(255, 0, 0), pointSize);
    } else if(buttonName == "slidePointButton") {
        bezierCurveOption = SLIDE_POINT;
        qDebug("Option changed to %i - SLIDE_POINT", bezierCurveOption);
        drawAllPoints(RGB(255, 0 ,0), pointSize);
    } else {
        qDebug("WRONG BUTTTON!");
    }
}

// Method clear canvas
void BezierCurveCanvas::clearCanvas()
{
    qImage.fill(Qt::white);
    update();
}

// Method clear canvas and remove all points in pointsVector
void BezierCurveCanvas::clearCanvasAndPoints()
{
    qImage.fill(Qt::white);
    update();
    pointsCounter = 0;
    pointsVector.clear();
}

// Method changing pointSize value depend on spin box value
void BezierCurveCanvas::changePointSize(int pointSize)
{
    this->pointSize = pointSize;
    if (bezierCurveOption == SLIDE_POINT || bezierCurveOption == REMOVE_POINT) {
        redrawBezierCurveForEveryPoints(brushRGB);
        drawAllPoints(RGB(255, 0, 0), pointSize);
    }
}

// Method drawing single pixel
void BezierCurveCanvas::putPixel(Point point, RGB rgb)
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

// Method drawing horizontal line
void BezierCurveCanvas::drawHorizontalLine(Point start, Point end, RGB rgb)
{
    if (end.getX() >= qImage.width()) {
        end.setX(qImage.width());
    }
    for(int i = start.getX(); i < end.getX(); i++) {
        putPixel(Point(i, start.getY()), rgb);
        update();
    }
}

// Method drawing line using naive algorithm
void BezierCurveCanvas::drawLineUsingNaiveAlgorithm(Point start, Point end, RGB rgb)
{
    if(start == end) {
        putPixel(start, rgb);
        return;
    }
    float dx = (float) end.getX() - start.getX();
    float dy = (float) end.getY() - start.getY();

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

// Method draw Bezier's curve for four points
void BezierCurveCanvas::drawBezierCurveForFourPoints(int firstPointIndex, RGB rgb)
{
    int xArray[4] = {pointsVector.at(firstPointIndex).getX(), pointsVector.at(firstPointIndex + 1).getX(), pointsVector.at(firstPointIndex + 2).getX(), pointsVector.at(firstPointIndex + 3).getX()};
    int yArray[4] = {pointsVector.at(firstPointIndex).getY(), pointsVector.at(firstPointIndex + 1).getY(), pointsVector.at(firstPointIndex + 2).getY(), pointsVector.at(firstPointIndex + 3).getY()};
    int N = 64;
    float t = 0;
    Point p1 = pointsVector.at(firstPointIndex), p2(0, 0);
    for (int i = 0; i <= N; i++) {
        t = (float)i / N;
        int x = pow((1 - t), 3) * xArray[0] + 3 * pow((1 - t), 2) * t * xArray[1] + 3 * (1 - t) * pow(t, 2) * xArray[2] + pow(t, 3) * xArray[3];
        int y = pow((1 - t), 3) * yArray[0] + 3 * pow((1 - t), 2) * t * yArray[1] + 3 * (1 - t) * pow(t, 2) * yArray[2] + pow(t, 3) * yArray[3];
        p2 = Point(x, y);
        drawLineUsingNaiveAlgorithm(p1, p2, rgb);
        p1 = p2;
    }
}

// Method find nearest point and return index of this point in pointsVector
int BezierCurveCanvas::findNearestPointIndex(Point point)
{
    int index = 0;
    Point nearestPoint = pointsVector.at(index);
    double nearestDistance = abs(sqrt(pow(point.getX() - nearestPoint.getX(), 2) + pow(point.getY() - nearestPoint.getY(), 2)));
    for (int i = 1; i < pointsVector.size(); i++) {
        double distance = abs(sqrt(pow(point.getX() - pointsVector.at(i).getX(), 2) + pow(point.getY() - pointsVector.at(i).getY(), 2)));
        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearestPoint = pointsVector.at(i);
            index = i;
        }
    }
    return index;
}

// Method draw all Bezier's curve which can be draw from pointsVector
void BezierCurveCanvas::redrawBezierCurveForEveryPoints(RGB rgb)
{
    clearCanvas();
    int size = pointsVector.size();
    if (size >= 4) {
        drawBezierCurveForFourPoints(0, rgb);
    }
    for (int i = 3; i < size; i += 3) {
        if (size - i >= 4) {
            drawBezierCurveForFourPoints(i, rgb);
        }
    }
}

// Method draw all points from pointsVector with specific size
void BezierCurveCanvas::drawAllPoints(RGB rgb, int size)
{
    foreach (Point singlePoint, pointsVector) {
        putPixel(singlePoint, rgb);
        if (size > 1) {
            for (int i = -size + 1; i <= size - 1; i++) {
                drawHorizontalLine(Point(singlePoint.getX() - size + 1, singlePoint.getY() + i), Point(singlePoint.getX() + size, singlePoint.getY() + i), rgb);
            }
        }
    }
}
