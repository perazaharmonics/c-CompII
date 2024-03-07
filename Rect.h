#ifndef RECT_H_
#define RECT_H_
#include "windows.h"

class Rect {
    private:
        double base, height, x0, y0;
        COLORREF color;
    public:
        Rect(); // default constructor
        Rect(double b, double h, double x, double y, COLORREF); // constructor
        ~Rect(); // destructor
        void setBase(double b); // set base
        void setHeight(double h); // set height
        double getBase() const; // get base
        double getHeight() const; // get height
        void setColor(COLORREF); // set color
        void setCoords(double x, double y); // set coordinates
        void mooveCoords(double dx, double dy); // moove coordinates
        void fplot(); // plot rectangle
        void ferase(); // erase rectangle
};
#endif
