#include "hsv.h"

HSV::HSV()
{
    this->h = 0;
    this->s = 0;
    this->v = 0;
}

HSV::HSV(float h, float s, float v)
{
    this->h = h;
    this->s = s;
    this->v = v;
}

void HSV::setH(float h)
{
    this->h = h;
}

void HSV::setS(float s)
{
    this->s = s;
}

void HSV::setV(float v)
{
    this->v = v;
}

float HSV::getH()
{
   return this->h;
}

float HSV::getS()
{
    return this->s;
}

float HSV::getV()
{
    return this->v;
}

void HSV::operator =(HSV hsv)
{
    this->h = hsv.getH();
    this->s = hsv.getS();
    this->v = hsv.getV();
}

bool HSV::operator ==(HSV hsv)
{
    if (this->getH() != hsv.getH() || this->getS() != hsv.getS() || this->getV() != hsv.getV()) return false;
    return true;
}

bool HSV::operator !=(HSV hsv)
{
    if (this->getH() != hsv.getH() || this->getS() != hsv.getS() || this->getV() != hsv.getV()) return true;
    return false;
}

HSV::~HSV()
{
    return;
}
