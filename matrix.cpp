#include "matrix.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>

Matrix::Matrix()
{
    this->n = 1;
    this->m = 1;
    for (int i = 0; i < n; i++) {
        std::vector<double> vector(m);
        matrix.push_back(vector);
    }
}

Matrix::Matrix(int n)
{
    this->n = n;
    this->m = n;
    for (int i = 0; i < n; i++) {
        std::vector<double> vector(m);
        matrix.push_back(vector);
    }
}

Matrix::Matrix(int n, int m)
{
    this->n = n;
    this->m = m;
    for (int i = 0; i < n; i++) {
        std::vector<double> vector(m);
        matrix.push_back(vector);
    }
}

std::vector<std::vector<double> > Matrix::getMatrix()
{
    return this->matrix;
}

int Matrix::getN()
{
    return this->n;
}

int Matrix::getM()
{
    return this->m;
}

void Matrix::set(int i, int j, double value)
{
    this->matrix.at(i).at(j) = value;
}

void Matrix::fillZero()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matrix.at(i).at(j) = 0.0;
        }
    }
}

Matrix Matrix::multiply(Matrix m)
{
    if (this->getM() != m.getN()) throw "Not correct matrixs for multiply";
    Matrix C = Matrix(this->getN(), m.getM());
    for(int i = 0; i < this->getN(); i++)
    {
        for(int j = 0; j < m.getM(); j++)
        {
            double s = 0.0;

            for(int k = 0; k < this->getM(); k++) {
                s += this->getMatrix()[i][k] * m.getMatrix()[k][j];
            }
            C.set(i, j, s);
        }
    }
    return C;
}

Point3 Matrix::multiplyVector(Point3 p)
{
    Point3 point = Point3();
    Matrix vector = Matrix(4, 1);
    vector.set(0, 0, (double)p.getX());
    vector.set(1, 0, (double)p.getY());
    vector.set(2, 0, (double)p.getZ());
    vector.set(3, 0, (double)1);
    vector = this->multiply(vector);
    point.setX((int)vector.getMatrix()[0][0]);
    point.setY((int)vector.getMatrix()[1][0]);
    point.setZ((int)vector.getMatrix()[2][0]);
    return point;
}

void Matrix::print()
{
    for(int i = 0; i < this->getN(); i++)
    {
        for(int j = 0; j < this->getM(); j++) std::cout << std::setw(6) << this->matrix[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix::~Matrix()
{

}
