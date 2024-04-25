
#include <iostream>
using namespace ::std;
void getNumber(int*& numberPtr);
int* getSum(int* number1Ptr, int* number2Ptr);
void display(int* number1Ptr, int* number2Ptr, int* totalPtr);

int main() {

	int* number1Ptr = nullptr;
	int* number2Ptr = nullptr;
	int* totalPtr = nullptr;

	number1Ptr = new int;
	number2Ptr = new int;
	getNumber(number1Ptr);
	getNumber(number2Ptr);
	totalPtr = getSum(number1Ptr, number2Ptr);
	display(number1Ptr, number2Ptr, totalPtr);
	delete totalPtr;
	delete number1Ptr;
	delete number2Ptr;
	number1Ptr = 0;
	number2Ptr = 0;
	totalPtr = 0;
	system("pause");
	return 0;
}
void getNumber(int*& numberPtr) {
	cout << "Enter an integer number:";
	cin >> *numberPtr;
}

int* getSum(int* number1Ptr, int* number2Ptr) {
	int* totalPtr = nullptr;
	totalPtr = new int;
	*totalPtr = *number1Ptr + *number2Ptr;
	return totalPtr;
}

void display(int* number1Ptr, int* number2Ptr, int* totalPtr) {
	cout << *number1Ptr << " + " << *number2Ptr << " = " << *totalPtr << endl;