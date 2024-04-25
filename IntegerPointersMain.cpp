#include<iostream>
using namespace::std;


int main() {
	int* xPtr = nullptr;
	xPtr = new int;

	cout << "Enter a integer number:";
	cin >> *xPtr;

	cout << "The number entered is:" << *xPtr << endl;
	cout << "The address of variable is: " << xPtr << endl;
	delete xPtr;
	xPtr = 0;
	system("pause");
	return 0;
}//end main