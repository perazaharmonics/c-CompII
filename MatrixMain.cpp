#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#include"Matrix.h"

int main() {
	int rows, cols, choice;
	cout<<"*************************************************"<<endl;
	cout << "Enter the matrix dimension: "<<endl;
	cin >> rows;
	cols = rows;
	Matrix A(rows, cols), B(rows, cols);
	A.setAllValue();
	B.setAllValue();
	cout << "Matrix A " << endl;
	A.display();
	cout << "Matrix B " << endl;
	B.display();
	cout<<"Enter the operation you want to perform: "<<endl;

	cout<<"1. for addition, 2. for substraction, 3. for Hadamard multiplication "<<endl;
	cin>>choice;
	cout<<endl;
	switch(choice)
	{
		case 1:
			cout << "The sum of matrices A and B is: " << endl;
			A.add(B);
			A.display();

		case 2:
			cout << "The difference of the matrices A and B is: " << endl;
			A.subtract(B);
			A.display();
		case 3:
			cout << "The Hadamard product of matrices A and B is: " << endl;
			A.Hadamard(B);
			A.display();
	}	
	Matrix D = A;
	cout << "Matrix D " << endl;
	D.display();
	system("pause");
	return 0;
}//end main