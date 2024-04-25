#include "windows.h" // include the Windows header file
using namespace::std; // use the standard namespace
#include "Rect.h" // include the Rect header file

int main() {
    // declare variables and initialize objects
    double tmpBase = 100; // declare and initialize tmpBase variable with value 100
    double tmpHeight = tmpBase; // declare and initialize tmpHeight variable with value of tmpBase
    double tmpX0, tmpY0; // declare tmpX0 and tmpY0 variables

    COLORREF tmpColor = RGB(255, 255, 100); // declare and initialize tmpColor variable with RGB color value

    Rect myRect; // create an instance of Rect class

    // Get console handle
    HWND consoleWindow = GetConsoleWindow(); // get the handle of the console window
    HDC tmpConsole = GetDC(consoleWindow); // get the device context of the console window

    // Get console buffer info
    CONSOLE_SCREEN_BUFFER_INFO csbi; // create a CONSOLE_SCREEN_BUFFER_INFO structure
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); // get the console screen buffer info

    // Calculate window width and height
    int windowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1; // calculate the width of the console window
    int windowHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // calculate the height of the console window

    // Calculate center position
    tmpX0 = (windowWidth - tmpBase) / 2; // calculate the x-coordinate of the center position
    tmpY0 = (windowHeight - tmpHeight) / 2; // calculate the y-coordinate of the center position


    // parametrize object
    myRect.setBase(tmpBase); // set the base of the rectangle object
    myRect.setHeight(tmpHeight); // set the height of the rectangle object
    myRect.setCoords(tmpX0, tmpY0); // set the coordinates of the rectangle object
    myRect.setColor(tmpColor); // set the color of the rectangle object

    // plot object
    myRect.fplot(tmpConsole); // plot the rectangle object on the console
    Sleep(10000); // pause the program for 10 seconds
    myRect.ferase(tmpConsole); // erase the rectangle object from the console

    // release DC
    ReleaseDC(consoleWindow, tmpConsole); // release the device context of the console window

    return 0; // return 0 to indicate successful execution
}