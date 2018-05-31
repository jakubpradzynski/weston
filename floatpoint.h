#ifndef FLOATPOINT_H
#define FLOATPOINT_H


class FloatPoint
{
protected:
    float x, y;

public:
    FloatPoint();
    FloatPoint(float x, float y);
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
    void operator =(FloatPoint point);
    bool operator ==(FloatPoint point);
    bool operator !=(FloatPoint point);
    ~FloatPoint();
};

#endif // FLOATPOINT_H
