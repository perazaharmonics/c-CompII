#include<iostream>
#include<string>
#include<cmath>
using namespace std;
#include "BMI.h"

int main() {
    float* height = nullptr, * weight = nullptr, * bmi = nullptr;
    string* name = nullptr;
    BMI* myBMI = new BMI();

    name = myBMI->getName();
    height = myBMI->getHeight();
    weight = myBMI->getWeight();
    bmi = myBMI->getBMI(height, weight);
    myBMI->display(name, height, weight, bmi);
    myBMI->displayMessage(bmi);
    delete name;
    delete height;
    delete weight;
    delete bmi;
    delete myBMI;
    name = 0;
    height = 0;
    weight = 0;
    bmi = 0;
    system("pause");
    return 0;
}