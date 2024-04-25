#ifndef RECT_H_
#define RECT_H_
using namespace std;
#include "windows.h"
#include <iostream>

class RectGlide {
private:
    double base, height, x0, y0;
    COLORREF color;
    HDC hdc = GetDC(GetConsoleWindow());
public:
    RectGlide(); // default constructor
    RectGlide(double b, double h, double x, double y, COLORREF); // constructor
    ~RectGlide(); // destructor
    HDC getHDC() const; // Getter for HDC
    void setBase(double b); // set base
    void setHeight(double h); // set height
    void setX0(double x); // set x0
    void setY0(double y); // set y0
    double getBase() const; // get base
    double getHeight() const; // get height
    double getX0() const; // get x0
    double getY0() const; // get y0
    void setColor(COLORREF); // set color
    void setCoords(double x, double y); // set coordinates
    void moveCoords(double dx, double dy); // move coordinates
    void fplot(); // plot rectangle
    void fGlide(); // glide rectangle
    void moveUp(); // move up
    void moveDown(); // move down
    void moveLeft(); // move left
    void moveRight(); // move right
    void moveDiagonalPosRight(); // move diagonal positive right
    void moveDiagonalPosLeft(); // move diagonal positive left
    void fErase(); // erase rectangle
};
#endif