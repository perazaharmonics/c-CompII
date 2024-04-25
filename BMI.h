#ifndef _BMI_H
#define _BMI_H
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class BMI
{
    private:
        float* height;
        float* weight;
        float* bmi;
        string* name;
    public:
        BMI();
        BMI(float* aHeight, float* aWeigth);
        ~BMI();
        string* getName() ;
        float* getHeight() ;
        float* getWeight() ;
        float* getBMI(float* height, float* weight) ;
        void setName(string* aName);
        void setHeight(float* aHeight);
        void setWeight(float* aWeight);
        void setBMI(float* aBMI);
        void displayMessage(float* aBMI) const;
        void display(string* aName, float* aHeight, float* aWeight, float* aBMI) const;

};
#endif