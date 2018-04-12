#include "scanelinecanvas.h"

ScaneLineCanvas::ScaneLineCanvas(QWidget *parent) : QWidget(parent)
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
    wasDrawing = false;
}

void ScaneLineCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    // Drawing qImage on canvas using qPainter
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::black);
    qPainter.drawImage(0, 0, qImage);
}

void ScaneLineCanvas::mouseMoveEvent(QMouseEvent *event)
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
            clearCanvas();
            drawPolygonUsingScaneLine(pointsVector, brushRGB);
            drawAllPoints(pointsVector, RGB(255, 0, 0), pointSize);
        }
        break;
    default:
         break;
    }
}

void ScaneLineCanvas::mousePressEvent(QMouseEvent *event)
{
    Point mousePressPoint = Point(event->x(), event->y());

    switch (bezierCurveOption) {
    case ADD_POINT:
        pointsVector.push_back(mousePressPoint);
        clearCanvas();
        drawAllPoints(pointsVector, RGB(255,0,0), pointSize);
        if (wasDrawing) draw();
        break;
    case REMOVE_POINT:
        // Removing nearest point to press point
        if (pointsVector.size() > 0) {
            removePointIndex = findNearestPointIndex(mousePressPoint);
            pointsVector.erase(pointsVector.begin() + removePointIndex);
            pointsVector.size() <= 2 ? wasDrawing = false : 0;
            clearCanvas();
            drawAllPoints(pointsVector, RGB(255, 0, 0), pointSize);
            draw();
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

void ScaneLineCanvas::mouseReleaseEvent(QMouseEvent *event)
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
            drawPolygonUsingScaneLine(pointsVector, brushRGB);
            drawAllPoints(pointsVector, RGB(255, 0, 0), pointSize);
        }
        break;
    default:
        break;
    }
}

// Method changing which option is active
void ScaneLineCanvas::changeOption()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonName = buttonSender->objectName();
    qDebug("%s was clicked", qUtf8Printable(buttonName));
    if(buttonName == "addPointButton") {
        bezierCurveOption = ADD_POINT;
        qDebug("Option changed to %i - ADD_POINT", bezierCurveOption);
    } else if(buttonName == "removePointButton") {
        bezierCurveOption = REMOVE_POINT;
        qDebug("Option changed to %i - REMOVE_POINT", bezierCurveOption);
        drawAllPoints(pointsVector, RGB(255, 0, 0), pointSize);
    } else if(buttonName == "slidePointButton") {
        bezierCurveOption = SLIDE_POINT;
        qDebug("Option changed to %i - SLIDE_POINT", bezierCurveOption);
        drawAllPoints(pointsVector, RGB(255, 0 ,0), pointSize);
    } else {
        qDebug("WRONG BUTTTON!");
    }
}

// Method clear canvas
void ScaneLineCanvas::clearCanvas()
{
    qImage.fill(Qt::white);
    update();
}

// Method clear canvas and remove all points in pointsVector
void ScaneLineCanvas::clearCanvasAndPoints()
{
    qImage.fill(Qt::white);
    update();
    pointsVector.clear();
}

// Method changing pointSize value depend on spin box value
void ScaneLineCanvas::changePointSize(int pointSize)
{
    this->pointSize = pointSize;
    clearCanvas();
    drawAllPoints(pointsVector, RGB(255, 0, 0), pointSize);
    if (wasDrawing) draw();
}

// Method draw polygon using scan line algorithm
void ScaneLineCanvas::draw()
{
    if (pointsVector.size() >= 3) {
        drawPolygonUsingScaneLine(pointsVector, brushRGB);
        wasDrawing = true;
    }
    else
        qDebug("Za mało punktow!");
}

// Method drawing single pixel
void ScaneLineCanvas::putPixel(Point point, RGB rgb)
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
void ScaneLineCanvas::drawHorizontalLine(Point start, Point end, RGB rgb)
{
    if (end.getX() >= qImage.width()) {
        end.setX(qImage.width());
    }
    for(int i = start.getX(); i < end.getX(); i++) {
        putPixel(Point(i, start.getY()), rgb);
        update();
    }
}

// Method find nearest point and return index of this point in pointsVector
int ScaneLineCanvas::findNearestPointIndex(Point point)
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

// Method draw all points from pointsVector with specific size
void ScaneLineCanvas::drawAllPoints(std::vector<Point> points, RGB rgb, int size)
{
    foreach (Point singlePoint, points) {
        putPixel(singlePoint, rgb);
        if (size > 1) {
            for (int i = -size + 1; i <= size - 1; i++) {
                drawHorizontalLine(Point(singlePoint.getX() - size + 1, singlePoint.getY() + i), Point(singlePoint.getX() + size, singlePoint.getY() + i), rgb);
            }
        }
    }
}

// Sort points vector by x value
bool ScaneLineCanvas::sortPointsByXValue(Point p1, Point p2)
{
    return p1.getX() < p2.getX();
}

// Draw polygon using scan line algorithm
void ScaneLineCanvas::drawPolygonUsingScaneLine(std::vector<Point> polygon, RGB rgb)
{
    int size = polygon.size();
    int yMin = polygon.at(0).getY();
    int yMax = polygon.at(0).getY();
    for (int i = 1; i < size; i++) {
        int y = polygon.at(i).getY();
        (y > yMax) ? yMax = y : 0;
        (y < yMin) ? yMin = y : 0;
    }

    for (int y = yMin; y <= yMax; y++) {
        std::vector<Point> intersectionPoints;
        for (int i = 0; i < size; i++) {
            Point p1 = polygon.at(i), p2 = polygon.at((i + 1) % size);
            if (p1.getY() < p2.getY()) {
                Point temp = p1;
                p1 = p2;
                p2 = temp;
            }
            if ((p1.getY() >= y && p2.getY() > y) || (p1.getY() <= y && p2.getY() < y)) continue;
            int x = (float)p1.getX() + ((float)(y - p1.getY()) / (float)(p2.getY() - p1.getY())) * (p2.getX() - p1.getX());
            intersectionPoints.push_back(Point(x, y));
        }
        intersectionPoints = removeBadPointsFromVector(intersectionPoints);
        std::sort(intersectionPoints.begin(), intersectionPoints.end(), sortPointsByXValue);
        for (int i = 0; i < intersectionPoints.size(); i++) {
            qDebug("(%d, %d)", intersectionPoints.at(i).getX(), intersectionPoints.at(i).getY());
        }
        qDebug("%d", intersectionPoints.size());
        if (intersectionPoints.size() > 1) {
            for (int i = 0; i < intersectionPoints.size() - 1; i += 2) {
                qDebug("here");
                drawHorizontalLine(intersectionPoints.at(i), intersectionPoints.at(i + 1), rgb);
            }
        }
    }
}

// Remove incorrect points from vector
std::vector<Point> ScaneLineCanvas::removeBadPointsFromVector(std::vector<Point> points)
{
    int i = 0;
    while (i < points.size()) {
        if(points.at(i).getX() < 0 || points.at(i).getY() < 0) {
            points.erase(points.begin() + i);
        } else {
            i++;
        }
    }
    return points;
}


