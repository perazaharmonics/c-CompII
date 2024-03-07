#include "windows.h"
using namespace::std;
#include "Rect.h"

Rect::Rect() {
    base = height = 100;
    x0 = y0 = 100;
    color = RGB(255, 255, 100);

} // default constructor

void Rect::fplot() {
    HWND myConsole = GetConsoleWindow();
    SetWindowPos(myConsole, 0, 0, 500, 600, 500, SWP_NOMOVE | SWP_NOZORDER); // move console window
    HDC myDC = GetDC(myConsole); // get editable context of console window

    for (int yCoord = y0; yCoord < (y0 + ((int)height)); yCoord++) { // vertical plotting loop
        for (int xCoord = x0; xCoord < (x0 + ((int)base)); xCoord++) { // horizontal plotting loop
            SetPixel(myDC, xCoord, yCoord, color); // plot pixel
        } // end horizontal plotting loop
    } // end vertical plotting loop

    ReleaseDC(myConsole, myDC); // release editable Device Context (DC) of console window
}
