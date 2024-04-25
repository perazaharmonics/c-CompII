// RectGlide.cpp : 
//

#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
#include "RectGlide.h"

// RectGlideMain.cpp

int main()
{
    double base = 500;  // example base
    double height = 200;  // example height
    double x0 = 100;
    double y0 = 100;
    COLORREF color = RGB(255, 0, 0); 

    RectGlide r(base, height, x0, y0, color);

    for (int i = 0; i < 10; i++)
    {
        r.fGlide();
        Sleep(1000); // sleep for 1 second (1000 milliseconds)
    }
    // Remember to release the HDC after you are done
    ReleaseDC(GetConsoleWindow(), r.getHDC());

    return 0;
}


