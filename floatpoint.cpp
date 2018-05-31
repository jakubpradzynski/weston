#include "floatpoint.h"

FloatPoint::FloatPoint()
{
    this->x = 0;
    this->y = 0;
}

FloatPoint::FloatPoint(float x, float y)
{
    this->x = x;
    this->y = y;
}

void FloatPoint::setX(float x)
{
    this->x = x;
}

void FloatPoint::setY(float y)
{
    this->y = y;
}

float FloatPoint::getX()
{
    return this->x;
}

float FloatPoint::getY()
{
    return this->y;
}

void FloatPoint::operator =(FloatPoint point)
{
    this->x = point.getX();
    this->y = point.getY();
}

bool FloatPoint::operator ==(FloatPoint point)
{
    if(this->x == point.getX() && this->y == point.getY()) {
        return true;
    }
    return false;
}

bool FloatPoint::operator !=(FloatPoint point)
{
    if(this->x == point.getX() && this->y == point.getY()) {
        return false;
    }
    return true;
}

FloatPoint::~FloatPoint()
{
    return;
}
