#include<iostream>
#include<string>
using namespace::std;
#include"Food.h"
int menu();
void getValues(Food& fruit);
Food* createArray(int size);
void add(Food*& fruitPtr, int& size, Food& fruit);
void print(Food* fruitPtr, int size);
void EqualOperator(Food* fruitPtr1, Food* fruitPtr2, int size);
void EqualOperator(Food* fruitPtr1, Food* fruitPtr2, int index1, int index2);
void EqualOperator(Food* fruitPtr, Food& fruit, int size);
void EqualOperator(Food& fruit, Food* fruitPtr, int index);
void sortArray(Food*& fruitPtr, int size);
int main() {
	const int ADD_CHOICE = 1,
		SORT_CHOICE = 2,
		DISPLAY_CHOICE = 3,
		QUIT_CHOICE = 4;
	int choice;
	Food* fruitPtr = nullptr;
	Food fruit;
	int size, index = 0;
	size = 0;
	do {
		choice = menu();
		switch (choice)
		{
		case ADD_CHOICE:
			getValues(fruit);
			add(fruitPtr, size, fruit);
			break;
		case SORT_CHOICE:
			sortArray(fruitPtr, size);
			break;
		case DISPLAY_CHOICE:
			cout << "Fruit Name          Calories Sugar   Fat  Carbohydrate Fiber Protein Potassium Magnesium" << endl;
			cout << "(per 100 gm servng)   (gm)    (gm)   (gm)      (gm)    (gm)    (gm)      (gm)     (gm) " << endl;
			print(fruitPtr, size);
			break;
		case QUIT_CHOICE:
			cout << "Program ending.\n";
			break;
		default:
			cout << "The valid choices are 1 through 4. Run the\n"
				<< "program again and select one of those.\n";
		}//edn switch

	} while (choice != QUIT_CHOICE);

	delete[] fruitPtr;
	fruitPtr = nullptr;
	system("pause");
	return 0;
}//end main

Food* createArray(int size) {
	Food* tmp = nullptr;
	tmp = new Food[size];
	return tmp;
}

void add(Food*& fruitPtr, int& size, Food& fruit) {

	Food* fruittmpPtr = nullptr;
	fruittmpPtr = createArray(size + 1);

	if (fruitPtr != nullptr) {
		EqualOperator(fruittmpPtr, fruitPtr, size);
	}
	EqualOperator(fruittmpPtr, fruit, size);
	size++;
	if (fruitPtr != nullptr) {
		delete[] fruitPtr;
		fruitPtr = nullptr;
	}//end if
	fruitPtr = createArray(size);
	EqualOperator(fruitPtr, fruittmpPtr, size);
	delete[] fruittmpPtr;
	fruittmpPtr = nullptr;
}



void print(Food* fruit, int size) {
	for (int index = 0; index < size; index++) {
		fruit[index].display();
	}//end for
}

void EqualOperator(Food* fruitPtr1, Food* fruitPtr2, int size) {
	for (int index = 0; index < size; index++) {
		fruitPtr1[index].setName(fruitPtr2[index].getName());
		fruitPtr1[index].setCalories(fruitPtr2[index].getCalories());
		fruitPtr1[index].setSugar(fruitPtr2[index].getSugar());
		fruitPtr1[index].setFat(fruitPtr2[index].getFat());
		fruitPtr1[index].setCarbohydrate(fruitPtr2[index].getCarbohydrate());
		fruitPtr1[index].setFiber(fruitPtr2[index].getFiber());
		fruitPtr1[index].setProtein(fruitPtr2[index].getProtein());
		fruitPtr1[index].setPotassium(fruitPtr2[index].getPotassium());
		fruitPtr1[index].setMagnesium(fruitPtr2[index].getMagnesium());
	}//end for
}

void EqualOperator(Food* fruitPtr1, Food* fruitPtr2, int index1, int index2) {

	fruitPtr1[index1].setName(fruitPtr2[index2].getName());
	fruitPtr1[index1].setCalories(fruitPtr2[index2].getCalories());
	fruitPtr1[index1].setSugar(fruitPtr2[index2].getSugar());
	fruitPtr1[index1].setFat(fruitPtr2[index2].getFat());
	fruitPtr1[index1].setCarbohydrate(fruitPtr2[index2].getCarbohydrate());
	fruitPtr1[index1].setFiber(fruitPtr2[index2].getFiber());
	fruitPtr1[index1].setProtein(fruitPtr2[index2].getProtein());
	fruitPtr1[index1].setPotassium(fruitPtr2[index2].getPotassium());
	fruitPtr1[index1].setMagnesium(fruitPtr2[index2].getMagnesium());

}
void EqualOperator(Food* fruitPtr, Food& fruit, int index) {
	fruitPtr[index].setName(fruit.getName());
	fruitPtr[index].setCalories(fruit.getCalories());
	fruitPtr[index].setSugar(fruit.getSugar());
	fruitPtr[index].setFat(fruit.getFat());
	fruitPtr[index].setCarbohydrate(fruit.getCarbohydrate());
	fruitPtr[index].setFiber(fruit.getFiber());
	fruitPtr[index].setProtein(fruit.getProtein());
	fruitPtr[index].setPotassium(fruit.getPotassium());
	fruitPtr[index].setMagnesium(fruit.getMagnesium());
}

void EqualOperator(Food& fruit, Food* fruitPtr, int index) {
	fruit.setName(fruitPtr[index].getName());
	fruit.setCalories(fruitPtr[index].getCalories());
	fruit.setSugar(fruitPtr[index].getSugar());
	fruit.setFat(fruitPtr[index].getFat());
	fruit.setCarbohydrate(fruitPtr[index].getCarbohydrate());
	fruit.setFiber(fruitPtr[index].getFiber());
	fruit.setProtein(fruitPtr[index].getProtein());
	fruit.setPotassium(fruitPtr[index].getPotassium());
	fruit.setMagnesium(fruitPtr[index].getMagnesium());
}

void sortArray(Food*& fruitPtr, int size)
{
	bool swap;
	Food temp;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (strcmp(fruitPtr[count].getName(), fruitPtr[count + 1].getName()) > 0)
			{
				EqualOperator(temp, fruitPtr, count);
				EqualOperator(fruitPtr, fruitPtr, count, count + 1);
				EqualOperator(fruitPtr, temp, count + 1);
				swap = true;
			}
		}
	} while (swap);
}



int menu() {
	int choice;
	// Display the menu and get a choice.
	cout << "\n\t\tMenu\n\n"
		<< "1. Add a fruit to the list\n"
		<< "2. Sort by fruit name the list\n"
		<< "3. Print the list\n"
		<< "4. Quit the Program\n\n"
		<< "Enter your choice: ";
	cin >> choice;
	return choice;
}
void getValues(Food& fruit) {
	const int MAX_CAPACITY = 15;
	char name[MAX_CAPACITY];
	int calories, potassium, magnesium;
	double sugar, fat, carbohydrate, fiber, protein;

	cin.ignore();
	cout << "Enter the Fruit name(per 100 gm serving): ";
	cin.getline(name, MAX_CAPACITY);
	fruit.setName(name);

	cout << " Enter the Calories(gm): ";
	cin >> calories;
	fruit.setCalories(calories);
	cout << " Enter the Sugar(gm): ";
	cin >> sugar;
	fruit.setSugar(sugar);
	cout << " Enter the Fat(gm): ";
	cin >> fat;
	fruit.setFat(fat);
	cout << " Enter the Carbohydrate(gm): ";
	cin >> carbohydrate;
	fruit.setCarbohydrate(carbohydrate);
	cout << " Enter the Fiber(gm): ";
	cin >> fiber;
	fruit.setFiber(fiber);
	cout << " Enter the Protein(gm): ";
	cin >> protein;
	fruit.setProtein(protein);
	cout << " Enter the Potassium(gm): ";
	cin >> potassium;
	fruit.setPotassium(potassium);
	cout << " Enter the Magnesium(gm): ";
	cin >> magnesium;
	fruit.setMagnesium(magnesium);
}