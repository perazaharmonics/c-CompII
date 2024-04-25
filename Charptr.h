#ifndef _CHARPTR_H
#define _CHARPTR_H

#include<iostream>
#include<cctype>
#include <cstring>
using namespace::std;

class Charptr{
    private:
        char* namePtr;
        int* lengthPtr;

    public:
        Charptr();
        Charptr(const char* aName);
        ~Charptr();
        char* getName();
        int* getLength(char* aNamePtr);

};
#endif