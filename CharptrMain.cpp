#include<iostream>
#include<cctype>
using namespace::std;
#include "Charptr.h"

int main() {

    int* lengthPtr = nullptr;
    char* namePtr = nullptr;
    Charptr* aCharptr = new Charptr();
    

    namePtr = aCharptr->getName();
    lengthPtr = aCharptr->getLength(namePtr);
    cout<< "Your name is: " << namePtr;
    cout << " and has " << *lengthPtr << " characters." << endl;
    delete[] namePtr;
    delete lengthPtr;
    delete aCharptr;
    namePtr = 0;
    lengthPtr = 0;
    aCharptr = 0;
    system("pause");
    return 0;
}