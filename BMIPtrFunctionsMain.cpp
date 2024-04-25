#include<iostream>
#include<string>
#include<cmath>
using namespace::std;
string* getName();
float* getHeight();
float* getWeight();
float* getBMI(float* height, float* weight);
void displayMessage(float* BMI);
void display(string* name, float* height, float* weight, float* BMI);


int main() {
	float* height = nullptr, * weight = nullptr, * BMI = nullptr;
	string* name = nullptr;

	name = getName();
	height = getHeight();
	weight = getWeight();
	BMI = getBMI(height, weight);
	display(name, height, weight, BMI);
	delete name;
	delete  height;
	delete weight;
	delete BMI;
	name = 0;
	height = 0;
	weight = 0;
	BMI = 0;
	system("pause");
	return 0;
}//end main


string* getName() {
	string* name = nullptr;
	name = new string;
	cout << "Enter your name:";
	getline(cin, *name);
	return name;
}
float* getHeight() {
	float* feet = nullptr, * inches = nullptr, * height = nullptr;
	height = new float;
	feet = new float;
	inches = new float;
	cout << "Enter your height (feet, inches):";
	cin >> *feet >> *inches;
	*height = *feet * 12 + *inches;
	delete feet;
	delete inches;
	feet = 0;
	inches = 0;
	return height;
}

float* getWeight() {
	float* weight = nullptr;
	weight = new float;
	cout << "Enter you weigth (pounds):";
	cin >> *weight;
	return weight;
}

float* getBMI(float* height, float* weight) {
	float* BMI = nullptr;
	BMI = new float;
	*BMI = *weight * (703 / pow(*height, 2.0));
	return BMI;
}

void displayMessage(float* BMI) {

	if (*BMI > 25) {
		cout << "You are overweight \n";
	}
	else {
		if (*BMI >= 18.5 && *BMI <= 25) {
			cout << "You are optimal weight\n";
		}//end if
		else {
			cout << "You are underweight\n";
		}//end else
	}//end else
}
//Funcion que imprime el BMI
void display(string* name, float* height, float* weight, float* BMI) {

	cout << *name << " for a height of " << *height << " inches and \n a weight " << *weight << " pounds.\nYour Body Mass Index is " << *BMI << endl;
	displayMessage(BMI);
}
