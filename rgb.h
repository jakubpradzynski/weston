#ifndef RGB_H
#define RGB_H

/* Class representing RGB color values */
class RGB
{
private:
    // r, g, b values
    int r, g, b;

public:
    // Constructors
    RGB();
    RGB(int r, int g, int b);
    // Setters
    void setR(int r);
    void setG(int g);
    void setB(int b);
    // Getters
    int getR();
    int getG();
    int getB();
    // Operator overload
    void operator =(RGB rgb);
    bool operator ==(RGB rgb);
    bool operator !=(RGB rgb);
    // Destructor
    ~RGB();
};

#endif // RGB_H
