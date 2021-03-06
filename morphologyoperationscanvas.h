#ifndef MORPHOLOGYOPERATIONSCANVAS_H
#define MORPHOLOGYOPERATIONSCANVAS_H

#include <QWidget>
#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>
#include "point.h"
#include "rgb.h"

class MorphologyOperationsCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit MorphologyOperationsCanvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void putDilation();
    void putErosion();
    void clearCanvas();

private:
    QSize canvasSize = QSize(650, 500);
    QImage qImage;
    QImage painting = QImage("sth.png");
    int kernelSize = 1;
    void repaintFromOneQImageToSecond(QImage *first, QImage *second);
    void putPixel(Point point, RGB rgb);
    void putPixel(QImage *qImage, Point point, RGB rgb);
    RGB getPointColor(Point point);
    RGB getPointColor(QImage *qImage, Point point);
    QImage dilation(int kernelSize);
    void putKernelForDilation(QImage *newQImage, Point point, int kernelSize);
    QImage erosion(int kernelSize);
    bool putKernelForErosion(QImage *newQImage, Point point, int kernelSize);
};

#endif // MORPHOLOGYOPERATIONSCANVAS_H
