#ifndef MATRIX_H
#define MATRIX_H

#include "vector"
#include <QWidget>
#include "point3.h"

class Matrix
{
protected:
    int n, m;
    std::vector<std::vector<double>> matrix;

public:
    Matrix();
    Matrix(int n);
    Matrix(int n, int m);

    std::vector<std::vector<double>> getMatrix();
    int getN();
    int getM();

    void set(int i, int j, double value);

    void fillZero();
    Matrix multiply(Matrix m);
    Point3 multiplyVector(Point3 p);
    void print();

    ~Matrix();
};

#endif // MATRIX_H
