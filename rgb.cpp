#include "rgb.h"

/* Class representing RGB color values */
// Constructors
RGB::RGB()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

RGB::RGB(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

// Setters
void RGB::setR(int r)
{
    this->r = r;
}

void RGB::setG(int g)
{
    this->g = g;
}

void RGB::setB(int b)
{
    this->b = b;
}

// Getters
int RGB::getR()
{
    return this->r;
}

int RGB::getG()
{
    return this->g;
}

int RGB::getB()
{
    return this->b;
}

// Operator overload
void RGB::operator =(RGB rgb)
{
    this->r = rgb.getR();
    this->g = rgb.getG();
    this->b = rgb.getB();
}

bool RGB::operator ==(RGB rgb)
{
    if (this->getR() != rgb.getR() || this->getG() != rgb.getG() || this->getB() != rgb.getB()) return false;
    return true;
}

bool RGB::operator !=(RGB rgb)
{
    if (this->getR() != rgb.getR() || this->getG() != rgb.getG() || this->getB() != rgb.getB()) return true;
    return false;
}

// Destructors
RGB::~RGB()
{
    return;
}
