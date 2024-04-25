#include<iostream>
#include<string>
#include<cmath>
using namespace std;
#include "BMI.h"

BMI::BMI()
{
    height = 0;
    weight = 0;
    bmi = 0;
    name = new string;
}

BMI::BMI(float* aHeight, float* aWeight)
{
    height = aHeight;
    weight = aWeight;
    bmi = 0;
    name = new string;
}

BMI::~BMI()
{
    delete height;
    delete weight;
    delete bmi;
    delete name;
}

string* BMI::getName() 
{   string* name = nullptr;
    name = new string;
    cout << "Enter your name: ";
    getline(cin, *name);
    return name;
}

float* BMI::getHeight() 
{   
    float* feet = new float;
    float* inches = new float;
    float* height = new float;

    cout << "Enter your height (feet part):"<<endl;
    cin >> *feet;
    if(cin.fail()) {
        cout << "Invalid input. Please enter a number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        delete feet;
        delete inches;
        delete height;
        return nullptr;
    }

    cout << "Enter your height (inches part):"<<endl;
    cin >> *inches;
    if(cin.fail()) {
        cout << "Invalid input. Please enter a number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        delete feet;
        delete inches;
        delete height;
        return nullptr;
    }

    *height = (*feet * 12) + *inches;

    delete feet;
    delete inches;

    return height;
}

float* BMI::getWeight() 
{   
    float* weight = new float;

    cout << "Enter your weight in pounds:"<<endl;
    cin >> *weight;

    return weight;
}

float* BMI::getBMI(float* height, float* weight) 
{   
    if (height == nullptr || weight == nullptr) {
        cout << "Error: height or weight was not provided." << endl;
        return nullptr;
    }

    float* bmi = new float;
    *bmi = *weight * (703 / pow(*height, 2.0));
    return bmi;
}

void BMI::setName(string* aName)
{
    name = aName;
}

void BMI::setHeight(float* aHeight)
{
    height = aHeight;
}

void BMI::setWeight(float* aWeight)
{
    weight = aWeight;
}

void BMI::setBMI(float* aBMI)
{
    bmi = aBMI;
}

void BMI::displayMessage(float* aBMI) const  {
    if (*aBMI > 25) {
        cout << "You are overweight \n";

    }// end if
    else {
        if (*aBMI >= 18.5 && *aBMI <=25) {
            cout << "You are at optimal weight\n";
        }// end if
        else {
            cout << "You are underweight\n";
        }// end else
    } //end else
    
}

void BMI::display(string* aName, float* aHeight, float* aWeight, float* aBMI) const {
    if (aName == nullptr || aHeight == nullptr || aWeight == nullptr || aBMI == nullptr) {
        cout << "Error: One or more required parameters were not provided." << endl;
        return;
    }

    cout << *aName << " for a height of: "<< *aHeight << "inches and \n a weight of: " << *aWeight << " pounds.\nYour Body Mass Index is " << *aBMI << endl;
}

