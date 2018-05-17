#ifndef POINT3_H
#define POINT3_H

#include "point.h"

class Point3 : public Point
{
protected:
    int z;

public:
    Point3();
    Point3(int x, int y, int z);

    void setZ(int z);
    int getZ();

    void operator =(Point3 p);
    bool operator ==(Point3 p);
    bool operator !=(Point3 p);

    ~Point3();
};

#endif // POINT3_H
