// RectGlide.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <windows.h>
#include "RectGlide.h"
using namespace std;

RectGlide::RectGlide()
{
    this->base = 0;
    this->height = 0;
    this->x0 = 0;
    this->y0 = 0;
    this->color = RGB(225, 225, 100);
    hdc = GetDC(GetConsoleWindow());

}

RectGlide::RectGlide(double b, double h, double x, double y, COLORREF c)
{
    this->base = b;
    this->height = h;
    this->x0 = x;
    this->y0 = y;
    this->color = c;
}

RectGlide::~RectGlide()
{
    cout << " Destructor called " << endl;
    this->base = 0;
    this->height = 0;
    this->x0 = 0;
    this->y0 = 0;
    this->color = RGB(0, 0, 0);
    ReleaseDC(GetConsoleWindow(), hdc);

}

void RectGlide::setBase(double b)
{
    this->base = b;

}

void RectGlide::setHeight(double h)
{
    this->height = h;
}

double RectGlide::getBase() const
{
    return this->base;

}

double RectGlide::getHeight() const
{
    return this->height;
}

void RectGlide::setX0(double x)
{
    this->x0 = x;
}

void RectGlide::setY0(double y)
{
    this->y0 = y;
}

double RectGlide::getX0() const
{
    return this->x0;
}

double RectGlide::getY0() const
{
    return this->y0;
}

HDC RectGlide::getHDC() const
{
    return this->hdc;
}

void RectGlide::setColor(COLORREF c)
{
    this->color = c;
}

void RectGlide::setCoords(double x, double y)
{
    this->x0 = x;
    this->y0 = y;
}

void RectGlide::moveCoords(double dx, double dy)
{
    this->x0 += dx;
    this->y0 += dy;

}

void RectGlide::fplot()
{
    HWND myConsole = GetConsoleWindow();
    SetWindowPos(myConsole, 0, 0, 500, 600, 500, SWP_NOMOVE | SWP_NOZORDER);
    HDC myDC = GetDC(myConsole);
    for(int yCoord = static_cast<int>(y0); yCoord < (y0 + static_cast<int>(height)); yCoord++)
    {
        for (int xCoord = static_cast<int>(x0); xCoord < (x0 + static_cast<int>(base)); xCoord++)
        {
            SetPixel(myDC, xCoord, yCoord, color);
        }
    }
    ReleaseDC(myConsole, myDC);
}

// define fErase() function
void RectGlide::fErase()
{
    HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hbrush);
    Rectangle(hdc, static_cast<int>(this->x0), static_cast<int>(this->y0), static_cast<int>(this->x0 + this->base), static_cast<int>(this->y0 + this->height));
    DeleteObject(hbrush);
}

void RectGlide::fGlide()
{
    this->moveDown();
    this->moveDiagonalPosRight();
    this->moveLeft();
    this->moveDown();
    this->moveRight();
    this->moveDiagonalPosLeft();

} // function for gliding the object

void RectGlide::moveUp()
{

    while ((x0 == 0 && y0 <= 500) || (x0 <= 600 && y0 >= 500))
    {
        this->fErase();
        this->moveCoords(0, -10);
        this->fplot();

        if ((x0 == 0 && y0 <= 0) || (x0 == 0 && y0 <= 500))
        {
            break;
        }
    }
}

void RectGlide::moveDown()
{
    while ((x0 == 0 && y0 == 0) || (x0 >= 0 && y0 <= 500))
    {
        this->fErase();
        this->moveCoords(0, 10);
        this->fplot();

        if ((x0 == 0 && y0 == 500) || (x0 == 600 && y0 <= 500))
        {
            break;
        }
    }
}

void RectGlide::moveLeft()
{
    while ((x0 == 600 && y0 <= 500) || (x0 >= 0 && y0 <= 500) || (x0<= 600 && y0 == 0))
    {
        this->fErase();
        this->moveCoords(-10, 0);
        this->fplot();

        if ((x0 == 0 && y0 <= 0) || (x0 == 0 && y0 == 500))
        {
            break;
        }
    }
}

void RectGlide::moveRight()
{

    while ((x0 == 0 && y0 == 0) || (x0 < 600 && y0 <= 500)) {
        {
            this->fErase();
            this->moveCoords(10, 0);
            this->fplot();

            if ((x0 == 600 && y0 == 0) || (x0 == 600 && y0 == 500))
            {
                break;
            }
        }

    }

}

void RectGlide::moveDiagonalPosRight()
{
    while ((x0 == 0 && y0 == 500) || (x0 < 600 && y0 < 500))
    {
        
        this->fErase();
        this->moveCoords(6, -5);
        this->fplot();

        if (x0 == 600 && y0 == 0)
        {
            break;
        }
    }
}

void RectGlide::moveDiagonalPosLeft()
{


    while ((x0 == 600 && y0 == 500) || (x0 < 600 && y0 <= 500))
    {
        this->fErase(); // Fix: Add the missing argument 'hdc' to the function call
        this->moveCoords(-6, -5);
        this->fplot();
        if (x0 == 0 && y0 == 0)
        {
            break;
        }
    }
}
