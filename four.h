#ifndef FOUR_H
#define FOUR_H

#include "point.h"

class Four : public Point
{
protected:
    float u, v;

public:
    Four();
    Four(int x, int y, float u, float v);
    void setU(float u);
    float getU();
    void setV(float v);
    float getV();
    void operator =(Four f);
    void operator =(Point p);
    bool operator ==(Four f);
    bool operator !=(Four f);
    ~Four();
};

#endif // FOUR_H
