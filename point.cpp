#include "point.h"

/* Class representing point in two-dimensional plane */
// Constructors
Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

// Setters
void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

// Getters
int Point::getX()
{
    return this->x;
}

int Point::getY()
{
    return this->y;
}

// Operator overload
void Point::operator =(Point point)
{
    this->x = point.getX();
    this->y = point.getY();
}

bool Point::operator ==(Point point)
{
    if(this->x == point.getX() && this->y == point.getY()) {
        return true;
    }
    return false;
}

bool Point::operator !=(Point point)
{
    if(this->x == point.getX() && this->y == point.getY()) {
        return false;
    }
    return true;
}

// Destructor
Point::~Point()
{
    return;
}


