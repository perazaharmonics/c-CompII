#include "windows.h" // Include the Windows header file for Windows API functions
#include "Rect.h" // Include the header file for the Rect class

Rect::Rect() { // Constructor for the Rect class
    base = height = 100; // Initialize base and height to 100
    x0 = y0 = 100; // Initialize x0 and y0 to 100
    color = RGB(255, 255, 100); // Initialize color to RGB(255, 255, 100)
}

Rect::Rect(double b, double h, double x, double y, COLORREF c) { // Constructor for the Rect class with parameters
    base = b; // Set base to the provided value
    height = h; // Set height to the provided value
    x0 = x; // Set x0 to the provided value
    y0 = y; // Set y0 to the provided value
    color = c; // Set color to the provided value
}

Rect::~Rect() {
    // Destructor for the Rect class
}

void Rect::setBase(double b) { // Set the base of the rectangle
    base = b; // Update the value of base
}

void Rect::setHeight(double h) { // Set the height of the rectangle
    height = h; // Update the value of height
}

void Rect::setCoords(double x, double y) { // Set the coordinates of the rectangle
    x0 = x; // Update the value of x0
    y0 = y; // Update the value of y0
}

void Rect::setColor(COLORREF c) { // Set the color of the rectangle
    color = c; // Update the value of color
}

void Rect::mooveCoords(double dx, double dy) { // Move the coordinates of the rectangle
    x0 += dx; // Update the value of x0 by adding dx
    y0 += dy; // Update the value of y0 by adding dy
}

double Rect::getBase() const { // Get the base of the rectangle
    return base; // Return the value of base
}

double Rect::getHeight() const { // Get the height of the rectangle
    return height; // Return the value of height
}

double Rect::getX0() const { // Get the x-coordinate of the rectangle
    return x0; // Return the value of x0
}

double Rect::getY0() const { // Get the y-coordinate of the rectangle
    return y0; // Return the value of y0
}

void Rect::fplot(HDC myDC) { // Plot the rectangle on the device context
    HWND myConsole = GetConsoleWindow(); // Get the handle to the console window
    SetWindowPos(myConsole, 0, 0, 500, 600, 500, SWP_NOMOVE | SWP_NOZORDER); // Set the position and size of the console window
    myDC = GetDC(myConsole); // Get the device context of the console window

    for (int yCoord = y0; yCoord < (y0 + ((int)height)); yCoord++) { // Loop through the y-coordinates of the rectangle
        for (int xCoord = x0; xCoord < (x0 + ((int)base)); xCoord++) { // Loop through the x-coordinates of the rectangle
            SetPixel(myDC, xCoord, yCoord, color); // Set the pixel at (xCoord, yCoord) to the specified color
        }
    }

    ReleaseDC(myConsole, myDC); // Release the device context of the console window
}

void Rect::ferase(HDC myDC) { // Erase the rectangle from the device context
    HWND myConsole = GetConsoleWindow(); // Get the handle to the console window
    myDC = GetDC(myConsole); // Get the device context of the console window

    for (int yCoord = y0; yCoord < (y0 + ((int)height)); yCoord++) { // Loop through the y-coordinates of the rectangle
        for (int xCoord = x0; xCoord < (x0 + ((int)base)); xCoord++) { // Loop through the x-coordinates of the rectangle
            SetPixel(myDC, xCoord, yCoord, RGB(0, 0, 0)); // Set the pixel at (xCoord, yCoord) to black color
        }
    }

    ReleaseDC(myConsole, myDC); // Release the device context of the console window
}
