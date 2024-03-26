#pragma once
#include<iostream>
using namespace::std;
class Food {
private:
	char* name;
	int calories;
	double sugar;
	double fat;
	double carbohydrate;
	double fiber;
	double protein;
	int potassium;
	int magnesium;

public:
	Food();
	Food(char* aName, int aCalories, double aSugar, double aFat, double aCarbohydrate, double aFiber, double aProtein, int  aPotassium, int  aMagnesium);
	Food(const Food& obj);
	~Food();
	void set(char* aName, int aCalories, double aSugar, double aFat, double aCarbohydrate, double aFiber, double aProtein, int  aPotassium, int  aMagnesium);
	void setName(char* aName);
	void setCalories(int aCalories);
	void setSugar(double aSugar);
	void setFat(double aFat);
	void setCarbohydrate(double aCarbohydrate);
	void setFiber(double aFiber);
	void setProtein(double aProtein);
	void setPotassium(int aPotassium);
	void setMagnesium(int aMagnesium);
	char* getName() const;
	int getCalories() const;
	double getSugar() const;
	double getFat() const;
	double getCarbohydrate() const;
	double getFiber() const;
	double getProtein() const;
	int getPotassium() const;
	int getMagnesium() const;
	void display() const;
};