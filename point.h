#ifndef POINT_H
#define POINT_H

/* Class representing point in two-dimensional plane */
class Point
{
protected:
    // x and y values
    int x, y;

public:
    // Constructors
    Point();
    Point(int x, int y);
    // Setters
    void setX(int x);
    void setY(int y);
    // Getters
    int getX();
    int getY();
    // Operator overload
    void operator =(Point point);
    bool operator ==(Point point);
    bool operator !=(Point point);

    // Destructor
    ~Point();
};

#endif // POINT_H
