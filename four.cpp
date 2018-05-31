#include "four.h"

Four::Four() : Point()
{
    this->setU(0);
    this->setV(0);
}

Four::Four(int x, int y, float u, float v) : Point(x, y)
{
    this->setU(u);
    this->setV(v);
}

void Four::setU(float u)
{
    this->u = u;
}

float Four::getU()
{
    return this->u;
}

void Four::setV(float v)
{
    this->v = v;
}

float Four::getV()
{
    return this->v;
}

void Four::operator =(Four f)
{
    this->setX(f.getX());
    this->setY(f.getY());
    this->setU(f.getU());
    this->setV(f.getV());
}

void Four::operator =(Point p)
{
    this->setX(p.getX());
    this->setY(p.getY());
}

bool Four::operator ==(Four f)
{
    if(this->x == f.getX() && this->y == f.getY() && this->getU() == f.getU() && this->getV() == f.getV()) {
        return true;
    }
    return false;
}

bool Four::operator !=(Four f)
{
    if(this->x == f.getX() && this->y == f.getY() && this->getU() == f.getU() && this->getV() == f.getV()) {
        return false;
    }
    return true;
}

Four::~Four()
{
    return;
}
