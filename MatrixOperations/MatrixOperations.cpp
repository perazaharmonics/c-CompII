#include<iostream>
using namespace::std;
#include"Matrix.h"

int main() {
	int rows, cols;

	cout << "Enter the matrix dimension:";
	cin >> rows >> cols;
	Matrix A(rows, cols), B(rows, cols);
	A.setAllValues();
	B.setAllValues();
	cout << "Matrix A " << endl;
	A.display();
	cout << "Matrix B " << endl;
	B.display();
	A.add(B);

	Matrix D = A;
	cout << "Matrix D " << endl;
	D.display();
	system("pause");
	return 0;
}//end main