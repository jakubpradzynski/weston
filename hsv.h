#ifndef HSV_H
#define HSV_H

class HSV
{    
private:
    float h, s, v;

public:
    HSV();
    HSV(float h, float s, float v);
    void setH(float h);
    void setS(float s);
    void setV(float v);
    float getH();
    float getS();
    float getV();
    void operator =(HSV hsv);
    bool operator ==(HSV hsv);
    bool operator !=(HSV hsv);
    ~HSV();
};

#endif // HSV_H
