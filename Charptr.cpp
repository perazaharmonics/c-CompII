#include<iostream>
#include<cctype>
#include <cstring>
using namespace::std;
#include "Charptr.h"

Charptr::Charptr(){
    namePtr = new char[1];
    namePtr[0] = '\0';
    lengthPtr = new int;
    *lengthPtr = 0;
}



Charptr::Charptr(const char* aName){
    namePtr = new char[strlen(aName) + 1];
    strcpy(namePtr, aName);
    lengthPtr = new int;
    *lengthPtr = strlen(aName);
}

Charptr::~Charptr(){
    delete [] namePtr;
    delete lengthPtr;
}

char* Charptr::getName() {
    char* namePtr = nullptr;
    const int MAX_LINE = 81;
    namePtr = new char[MAX_LINE];
    cout<< "Enter a name: ";
    cin.getline(namePtr, MAX_LINE);
    return namePtr;
};

int* Charptr::getLength(char* aNamePtr){
    int* lengthPtr = nullptr;
    int index = 0;
    lengthPtr = new int;
    *lengthPtr = 0;
    while(aNamePtr[index] != '\0') {
        if (!isspace(aNamePtr[index])) {
            *lengthPtr = *lengthPtr + 1;
        }//end if
        index++;
    } // end while
    return lengthPtr;
};