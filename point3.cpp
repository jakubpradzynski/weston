#include "point3.h"

Point3::Point3() : Point()
{
    this->setZ(0);
}

Point3::Point3(int x, int y, int z) : Point(x, y)
{
    this->setZ(z);
}

void Point3::setZ(int z)
{
    this->z = z;
}

int Point3::getZ()
{
    return this->z;
}

void Point3::operator =(Point3 p)
{
    this->setX(p.getX());
    this->setY(p.getY());
    this->setZ(p.getZ());
}

bool Point3::operator ==(Point3 p)
{
    if(this->x == p.getX() && this->y == p.getY() && this->z == p.getZ()) {
        return true;
    }
    return false;
}

bool Point3::operator !=(Point3 p)
{
    if(this->x == p.getX() && this->y == p.getY() && this->z == p.getZ()) {
        return false;
    }
    return true;
}

Point3::~Point3()
{
    return;
}
