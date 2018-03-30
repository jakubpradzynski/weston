#include "bsplinecurvecanvas.h"

BSplineCurveCanvas::BSplineCurveCanvas(QWidget *parent) : QWidget(parent)
{
    // Setting brush color to black
    brushRGB = RGB(0, 0, 0);
    // Settin qImage color and size (place where can draw other elements)
    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::white);

    // First initialize private variable
    slidePointIndex = 0;
    removePointIndex = 0;
    pointSize = 1;
}

void BSplineCurveCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    // Drawing qImage on canvas using qPainter
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::black);
    qPainter.drawImage(0, 0, qImage);
}

void BSplineCurveCanvas::mouseMoveEvent(QMouseEvent *event)
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
            redrawBSplineCurveForEveryPoints(brushRGB);
            drawAllPoints(RGB(255, 0, 0), pointSize);
        }
        break;
    default:
         break;
    }
}

void BSplineCurveCanvas::mousePressEvent(QMouseEvent *event)
{
    Point mousePressPoint = Point(event->x(), event->y());

    switch (bezierCurveOption) {
    case ADD_POINT:
        // Adding new point with check if should draw next curve
        pointsVector.push_back(mousePressPoint);
        if (pointsVector.size() == 4) {
            drawBSplineCurveForFourPoints(0, brushRGB);
        } else if (pointsVector.size() > 4) {
            drawBSplineCurveForFourPoints(pointsVector.size() - 4, brushRGB);
        }
        break;
    case REMOVE_POINT:
        // Removing nearest point to press point
        if (pointsVector.size() > 0) {
            removePointIndex = findNearestPointIndex(mousePressPoint);
            pointsVector.erase(pointsVector.begin() + removePointIndex);
            redrawBSplineCurveForEveryPoints(brushRGB);
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

void BSplineCurveCanvas::mouseReleaseEvent(QMouseEvent *event)
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
            redrawBSplineCurveForEveryPoints(brushRGB);
            drawAllPoints(RGB(255, 0, 0), pointSize);
        }
        break;
    default:
        break;
    }
}

// Method changing which option is active
void BSplineCurveCanvas::changeOption()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonName = buttonSender->objectName();
    qDebug("%s was clicked", qUtf8Printable(buttonName));
    if(buttonName == "addPointButton") {
        bezierCurveOption = ADD_POINT;
        qDebug("Option changed to %i - ADD_POINT", bezierCurveOption);
        redrawBSplineCurveForEveryPoints(brushRGB);
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
void BSplineCurveCanvas::clearCanvas()
{
    qImage.fill(Qt::white);
    update();
}

// Method clear canvas and remove all points in pointsVector
void BSplineCurveCanvas::clearCanvasAndPoints()
{
    qImage.fill(Qt::white);
    update();
    pointsVector.clear();
}

// Method changing pointSize value depend on spin box value
void BSplineCurveCanvas::changePointSize(int pointSize)
{
    this->pointSize = pointSize;
    if (bezierCurveOption == SLIDE_POINT || bezierCurveOption == REMOVE_POINT) {
        redrawBSplineCurveForEveryPoints(brushRGB);
        drawAllPoints(RGB(255, 0, 0), pointSize);
    }
}

// Method drawing single pixel
void BSplineCurveCanvas::putPixel(Point point, RGB rgb)
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
void BSplineCurveCanvas::drawHorizontalLine(Point start, Point end, RGB rgb)
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
void BSplineCurveCanvas::drawLineUsingNaiveAlgorithm(Point start, Point end, RGB rgb)
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

// Method draw B-spline curve for four points
void BSplineCurveCanvas::drawBSplineCurveForFourPoints(int firstPointIndex, RGB rgb)
{
    int xArray[4] = {pointsVector.at(firstPointIndex).getX(), pointsVector.at(firstPointIndex + 1).getX(), pointsVector.at(firstPointIndex + 2).getX(), pointsVector.at(firstPointIndex + 3).getX()};
    int yArray[4] = {pointsVector.at(firstPointIndex).getY(), pointsVector.at(firstPointIndex + 1).getY(), pointsVector.at(firstPointIndex + 2).getY(), pointsVector.at(firstPointIndex + 3).getY()};
    int N = 64;
    float t = 0;
    int x = ((float)1/6 * (-pow(t,3) + 3 * pow(t,2) - 3 * t + 1) * xArray[0]) + ((float)1/6 * (3 * pow(t,3) - 6 * pow(t,2) + 4) * xArray[1]) + ((float)1/6 * (-3 * pow(t,3) + 3 * pow(t,2) + 3 * t + 1) * xArray[2]) + ((float)1/6 * pow(t,3) * xArray[3]);
    int y = ((float)1/6 * (-pow(t,3) + 3 * pow(t,2) - 3 * t + 1) * yArray[0]) + ((float)1/6 * (3 * pow(t,3) - 6 * pow(t,2) + 4) * yArray[1]) + ((float)1/6 * (-3 * pow(t,3) + 3 * pow(t,2) + 3 * t + 1) * yArray[2]) + ((float)1/6 * pow(t,3) * yArray[3]);
    Point p1 = Point(x, y), p2(0, 0);
    for (int i = 1; i <= N; i++) {
        t = (float)i / N;
        int x = ((float)1/6 * (-pow(t,3) + 3 * pow(t,2) - 3 * t + 1) * xArray[0]) + ((float)1/6 * (3 * pow(t,3) - 6 * pow(t,2) + 4) * xArray[1]) + ((float)1/6 * (-3 * pow(t,3) + 3 * pow(t,2) + 3 * t + 1) * xArray[2]) + ((float)1/6 * pow(t,3) * xArray[3]);
        int y = ((float)1/6 * (-pow(t,3) + 3 * pow(t,2) - 3 * t + 1) * yArray[0]) + ((float)1/6 * (3 * pow(t,3) - 6 * pow(t,2) + 4) * yArray[1]) + ((float)1/6 * (-3 * pow(t,3) + 3 * pow(t,2) + 3 * t + 1) * yArray[2]) + ((float)1/6 * pow(t,3) * yArray[3]);
        p2 = Point(x, y);
        drawLineUsingNaiveAlgorithm(p1, p2, rgb);
        p1 = p2;
    }
}

// Method find nearest point and return index of this point in pointsVector
int BSplineCurveCanvas::findNearestPointIndex(Point point)
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

// Method draw all B-spline curve which can be draw from pointsVector
void BSplineCurveCanvas::redrawBSplineCurveForEveryPoints(RGB rgb)
{
    clearCanvas();
    int size = pointsVector.size();
    if (size >= 4) {
        drawBSplineCurveForFourPoints(0, rgb);
    }
    for (int i = 1; i < size - 3; i++) {
        drawBSplineCurveForFourPoints(i, rgb);
    }
}

// Method draw all points from pointsVector with specific size
void BSplineCurveCanvas::drawAllPoints(RGB rgb, int size)
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
