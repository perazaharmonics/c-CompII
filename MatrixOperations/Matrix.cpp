#include<iostream>
#include<iomanip>
using namespace::std;
#include"Matrix.h"

Matrix::Matrix() {
	setRows(2);
	setCols(2);
	matrix = createMatrix();
}
Matrix::Matrix(int aRows, int aCols) {
	setRows(aRows);
	setCols(aCols);
	matrix = createMatrix();
}

Matrix::Matrix(const Matrix& obj)
{
	cout << "Called copy-constructor" << endl;
	setRows(obj.getRows());
	setCols(obj.getCols());
	matrix = createMatrix();
	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			matrix[i][j] = obj.matrix[i][j];
		}//end for
	}//end for
}


Matrix::~Matrix() {
	cout << "Destructor\n";
	if (matrix != nullptr) {
		for (int i = 0; i < getRows(); i++) {
			delete[] matrix[i];
		}//end for
		delete[] matrix;
		matrix = nullptr;
	} //end if
	system("pause");
}

void Matrix::setRows(int aRows) {
	rows = aRows;
}
void Matrix::setCols(int aCols) {
	cols = aCols;
}
int Matrix::getRows() const {
	return rows;
}
int Matrix::getCols() const {
	return cols;
}
void Matrix::add(Matrix aMatrix) {
	Matrix resultingMatrix(getRows(), getCols());
	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			resultingMatrix.setValue(getValue(i, j) + aMatrix.getValue(i, j), i, j);
		}//end for
	}//end for
	cout << "Matrix C" << endl;
	resultingMatrix.display();
}

void Matrix::setValue(double value, int i, int j) {
	matrix[i][j] = value;
}

double Matrix::getValue(int i, int j) const {
	return matrix[i][j];
}

double** Matrix::createMatrix() {
	double** aMatrix = nullptr;
	int i, j;
	aMatrix = new double* [getRows()];
	for (i = 0; i < getRows(); i++) {
		aMatrix[i] = new double[getCols()];
	}//end for
	for (i = 0; i < getRows(); i++) {
		for (j = 0; j < getCols(); j++) {
			aMatrix[i][j] = 0.0;
		}//end for
	}//end for
	return aMatrix;
}

void Matrix::setAllValues() {
	double value;
	cout << "Enter the Matrix values\n";
	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			cout << "Matrx[" << i << "][" << j << "]:";
			cin >> value;
			setValue(value, i, j);
		}//end for
	}//end for
}

void Matrix::display() {
	cout << fixed << showpoint << setprecision(2);
	cout << "\nMatrix Data" << endl;
	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			cout << setw(5) << getValue(i, j) << " ";
		}//end for
		cout << endl;
	}//end for
}