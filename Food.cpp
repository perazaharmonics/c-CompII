#include<iostream>
#include<iomanip>
#include<cstring>
using namespace::std;
#include "Food.h"

Food::Food() : name(nullptr), calories(0), sugar(0.0), fat(0.0), carbohydrate(0.0), fiber(0.0), protein(0.0), potassium(0), magnesium(0) {
	cout << "\nWelcome to the default constructor" << endl;
	setName("fruit");
	setCalories(0);
	setSugar(0.0);
	setFat(0.0);
	setCarbohydrate(0.0);
	setFiber(0.0);
	setProtein(0.0);
	setPotassium(0);
	setMagnesium(0);

}
Food::Food(char* aName, int aCalories, double aSugar, double aFat, double aCarbohydrate, double aFiber, double aProtein, int  aPotassium, int  aMagnesium) {
	cout << "\nWelcome to the  constructor" << endl;
	setName(aName);
	setCalories(aCalories);
	setSugar(aSugar);
	setFat(aFat);
	setCarbohydrate(aCarbohydrate);
	setFiber(aFiber);
	setProtein(aProtein);
	setPotassium(aPotassium);
	setMagnesium(aMagnesium);

}

Food::Food(const Food& obj) {
	cout << "\nWelcome to the copy constructor" << endl;
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	setCalories(obj.getCalories());
	setSugar(obj.getSugar());
	setFat(obj.getFat());
	setCarbohydrate(obj.getCarbohydrate());
	setFiber(obj.getFiber());
	setProtein(obj.getProtein());
	setPotassium(obj.getPotassium());
	setMagnesium(obj.getMagnesium());

}
Food::~Food() {
	cout << "\nDestructor is running!\n";
	delete[] name;
	name = nullptr;
	system("pause");

}
Food& Food::operator=(const Food& obj)
{
	if (this != &obj)
	{
		delete[] name;
		name=new char[strlen(obj.name) + 1];
		strcpy_s(name, strlen(obj.name) + 1, obj.name);
		setCalories(obj.getCalories());
		setSugar(obj.getSugar());
		setFat(obj.getFat());
		setCarbohydrate(obj.getCarbohydrate());
		setFiber(obj.getFiber());
		setProtein(obj.getProtein());
		setPotassium(obj.getPotassium());
		setMagnesium(obj.getMagnesium());
	}
	return *this;
}
void Food::set(char* aName, int aCalories, double aSugar, double aFat, double aCarbohydrate, double aFiber, double aProtein, int  aPotassium, int  aMagnesium) {
	setName(aName);
	setCalories(aCalories);
	setSugar(aSugar);
	setFat(aFat);
	setCarbohydrate(aCarbohydrate);
	setFiber(aFiber);
	setProtein(aProtein);
	setPotassium(aPotassium);
	setMagnesium(aMagnesium);
}


void Food::setName(const char* aName) {
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
	name = new char[strlen(aName) + 1];
	strcpy_s(name, strlen(aName) + 1, aName);
}
void  Food::setCalories(int aCalories) {
	calories = aCalories;
}
void Food::setFat(double aFat) {
	fat = aFat;
}
void Food::setSugar(double aSugar) {
	sugar = aSugar;
}
void Food::setCarbohydrate(double aCarbohydrate) {
	carbohydrate = aCarbohydrate;
}
void Food::setFiber(double aFiber) {
	fiber = aFiber;
}
void Food::setProtein(double aProtein) {
	protein = aProtein;
}
void Food::setPotassium(int aPotassium) {
	potassium = aPotassium;
}
void Food::setMagnesium(int aMagnesium) {
	magnesium = aMagnesium;
}
char* Food::getName() const {
	return name;
}
int Food::getCalories() const {
	return calories;
}
double Food::getFat() const {
	return fat;
}
double Food::getSugar() const {
	return sugar;
}
double Food::getCarbohydrate() const {
	return carbohydrate;
}
double Food::getFiber() const {
	return fiber;
}
double Food::getProtein() const {
	return protein;
}
int Food::getPotassium() const {
	return potassium;
}
int Food::getMagnesium() const {
	return magnesium;
}
// searchList: searches the list for a specific item
int Food::searchList(Food* fruit, const char* name, int size) {
	for (int i = 0; i < size; i++) {
		if (strcmp(fruit[i].getName(), name) == 0) {
			return i;
		}
	}
	return -1;
}
// removeItem: removes an item from the list
bool Food::removeItem(Food*& fruit, const char* name, int& size) {
	int index = searchList(fruit, name, size);
	if (index == -1) 
	{
		return false;
	}
	else 
	{
		Food* newFruitArray = new Food[size - 1];
		for (int i = 0, j = 0; i < size; i++) 
		{
			if (i != index) { // Copy all but the removed item
				newFruitArray[j] = fruit[i];
				j++;
			}
		}
		delete[] fruit; // Delete old array
		fruit = newFruitArray; // Point to new array
		size--;
		return true;
	}
}

void Food::display() const {
	cout << showpoint << fixed << setprecision(2);
	cout << left << setw(20) << getName();
	cout << setw(8) << getCalories();
	cout << setw(8) << getSugar();
	cout << setw(8) << getFat();
	cout << setw(12) << getCarbohydrate();
	cout << setw(8) << getFiber();
	cout << setw(8) << getProtein();
	cout << setw(8) << getPotassium();
	cout << setw(8) << getMagnesium() << endl;
}