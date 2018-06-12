#include "transformations3dcanvas.h"

Transformations3DCanvas::Transformations3DCanvas(QWidget *parent) : QWidget(parent)
{
    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::white);
    update();
    putPixel(&qImage, centralPoint, RGB(0, 0, 255));
    translationX = translationY = translationZ = rotationX = rotationY = rotationZ = 0;
    scalingX = scalingY = scalingZ = 10;
    setCubePoints();
//    Matrix M = getTranslationMatrix(0, 0, 45);
//    Point3 p = M.multiplyVector(Point3(-1,1,1));
//    qDebug("%d, %d, %d", p.getX(), p.getY(), p.getZ());
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::white);
    qPainter.drawImage(0, 0, qImage);
}

void Transformations3DCanvas::translationXChanged(int x)
{
    translationX = x;
    qImage.fill(Qt::white);
    update();
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::translationYChanged(int y)
{
    translationY = y;
    qImage.fill(Qt::white);
    update();
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::translationZChanged(int z)
{
    translationZ = z;
    qImage.fill(Qt::white);
    update();
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::scalingXChanged(int x)
{
    if(x != 0) scalingX = x;
    else scalingX = 1;
    qImage.fill(Qt::white);
    update();
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::scalingYChanged(int y)
{
    if(y != 0) scalingY = y;
    else scalingY = 1;
    qImage.fill(Qt::white);
    update();
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::scalingZChanged(int z)
{
    if(z != 0) scalingZ = z;
    else scalingZ = 1;
    qImage.fill(Qt::white);
    update();
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::rotationXChanged(int x)
{
    rotationX = x;
    qImage.fill(Qt::white);
    update();
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::rotationYChanged(int y)
{
    rotationY = y;
    qImage.fill(Qt::white);
    update();
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::rotationZChanged(int z)
{
    rotationZ = z;
    qImage.fill(Qt::white);
    update();
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::perspectiveChanged(int f)
{
    this->perspective = f;
    qImage.fill(Qt::white);
    update();
    draw3DCube(&qImage, cubePoints);
}

void Transformations3DCanvas::putPixel(QImage *qImage, Point point, RGB rgb)
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

RGB Transformations3DCanvas::getPointColor(QImage *qImage, Point point)
{
    int r, g, b;
    QColor qColor = qImage->pixel(point.getX(), point.getY());
    qColor.getRgb(&r, &g, &b);
    return RGB(r, g, b);
}

void Transformations3DCanvas::drawHorizontalLine(QImage *qImage, Point start, Point end, RGB rgb)
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

void Transformations3DCanvas::drawLine(QImage *qImage, Point start, Point end, RGB rgb)
{
    if(start.getX() < 0 || start.getY() < 0 || end.getX() < 0 || end.getY() < 0 || start.getX() > canvasSize.width() || start.getY() > canvasSize.height() || end.getX() > canvasSize.width() || end.getY() > canvasSize.height()) return;

    if(start == end) {
        putPixel(qImage, start, rgb);
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
            putPixel(qImage, Point(x, y), rgb);
        }
    } else {
        if(start.getY() > end.getY()) {
            Point tmp = start;
            start = end;
            end = tmp;
        }
        for (int y = start.getY(); y <= end.getY(); y++) {
            float x = (float) start.getX() + dx * (y - start.getY()) / dy;
            putPixel(qImage, Point(x, y), rgb);
        }
    }
}

void Transformations3DCanvas::setCubePoints()
{
    cubePoints.push_back(Point3(-1, 1, 1));
    cubePoints.push_back(Point3(1, 1, 1));
    cubePoints.push_back(Point3(1, 1, -1));
    cubePoints.push_back(Point3(-1, 1, -1));
    cubePoints.push_back(Point3(-1, -1, 1));
    cubePoints.push_back(Point3(1, -1, 1));
    cubePoints.push_back(Point3(1, -1, -1));
    cubePoints.push_back(Point3(-1, -1, -1));
}

Matrix Transformations3DCanvas::getTranslationMatrix(int x, int y, int z)
{
    Matrix A = Matrix(4, 4);
    A.set(0, 0, 1);
    A.set(1, 1, 1);
    A.set(2, 2, 1);
    A.set(3, 3, 1);
    A.set(0, 3, x);
    A.set(1, 3, y);
    A.set(2, 3, z);
    return A;
}

Matrix Transformations3DCanvas::getScalingMatrix(int x, int y, int z)
{
    Matrix A = Matrix(4, 4);
    A.set(0, 0, x);
    A.set(1, 1, y);
    A.set(2, 2, z);
    A.set(3, 3, 1);
    return A;
}

Matrix Transformations3DCanvas::getXRotationMatrix(int xAlpha)
{
    Matrix A = Matrix(4, 4);
    A.set(0, 0, 1);
    A.set(1, 1, cos((double)xAlpha * M_PI / 180.0));
    A.set(2, 1, sin((double)xAlpha * M_PI / 180.0));
    A.set(1, 2, -sin((double)xAlpha * M_PI / 180.0));
    A.set(2, 2, cos((double)xAlpha * M_PI / 180.0));
    A.set(3, 3, 1);
    return A;
}

Matrix Transformations3DCanvas::getYRotationMatrix(int yAlpha)
{
    Matrix A = Matrix(4, 4);
    A.set(0, 0, cos((double)yAlpha * M_PI / 180.0));
    A.set(1, 1, 1);
    A.set(2, 0, -sin((double)yAlpha * M_PI / 180.0));
    A.set(0, 2, sin((double)yAlpha * M_PI / 180.0));
    A.set(2, 2, cos((double)yAlpha * M_PI / 180.0));
    A.set(3, 3, 1);
    return A;
}

Matrix Transformations3DCanvas::getZRotationMatrix(int zAlpha)
{
    Matrix A = Matrix(4, 4);
    A.set(0, 0, cos((double)zAlpha * M_PI / 180.0));
    A.set(1, 0, sin((double)zAlpha * M_PI / 180.0));
    A.set(0, 1, -sin((double)zAlpha * M_PI / 180.0));
    A.set(1, 1, cos((double)zAlpha * M_PI / 180.0));
    A.set(2, 2, 1);
    A.set(3, 3, 1);
    return A;
}

Matrix Transformations3DCanvas::getTransformationMatrix()
{
    Matrix translationMatrix = getTranslationMatrix(translationX, translationY, translationZ);
    Matrix scalingMatrix = getScalingMatrix(scalingX, scalingY, scalingZ);
    Matrix xRotationMatrix = getXRotationMatrix(rotationX);
    Matrix yRotationMatrix = getYRotationMatrix(rotationY);
    Matrix zRotationMatrix = getZRotationMatrix(rotationZ);
    Matrix transformationMatrix = translationMatrix.multiply(scalingMatrix);
    Matrix transformationMatrix1 = transformationMatrix.multiply(xRotationMatrix);
    Matrix transformationMatrix2 = transformationMatrix1.multiply(yRotationMatrix);
    Matrix transformationMatrix3 = transformationMatrix2.multiply(zRotationMatrix);
    return transformationMatrix3;
}

void Transformations3DCanvas::draw3DCube(QImage *qImage, std::vector<Point3> cubePoints)
{
    Matrix transformationMatrix = getTransformationMatrix();
    std::vector<Point3> transformedPoints;
    std::vector<Point> projectionPoints;
    for (int i = 0; i < cubePoints.size(); i++) {
        transformedPoints.push_back(transformationMatrix.multiplyVector(cubePoints.at(i)));
        transformedPoints.at(i).setZ(transformedPoints.at(i).getZ() + 20);
        projectionPoints.push_back(calculateProjection(transformedPoints.at(i), centralPoint, (double)perspective));
    }
    drawCubeEdges(qImage, cubePoints, projectionPoints);
}

Point Transformations3DCanvas::calculateProjection(Point3 point3, Point centralPoint, double perspective)
{
    double x = (double)point3.getX() / (double)point3.getZ() * perspective + (double)centralPoint.getX();
    double y = (double)point3.getY() / (double)point3.getZ() * perspective + (double)centralPoint.getY();
    return Point(x, y);
}

void Transformations3DCanvas::drawCubeEdges(QImage *qImage, std::vector<Point3> cubePoints, std::vector<Point> projectionPoints)
{
    for (int i = 0; i < cubePoints.size(); i++) {
        for (int j = 0; j < cubePoints.size(); j++) {
            int k = 0;
            if (cubePoints.at(i).getX() == cubePoints.at(j).getX()) k++;
            if (cubePoints.at(i).getY() == cubePoints.at(j).getY()) k++;
            if (cubePoints.at(i).getZ() == cubePoints.at(j).getZ()) k++;
            if (k == 2) drawLine(qImage, projectionPoints.at(i), projectionPoints.at(j), cubeColor);
        }
    }
}

