#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Matrix
{
private:
	double** matrix;				// Vector of row (m) and column (n) vectors mxn, m-dimensional
	int rows;						// Number of rows (m) in the matrix
	int cols;						// Number of columns (n) in the matrix
public:
	Matrix();						// Default constructor
	Matrix(int aRows, int aCols);	// Constructor with parameters
	Matrix(const Matrix& obj);		// Copy constructor
	~Matrix();			// Destructor
	double** createMatrix();		// Create a matrix
	void setAllValue(); 			// Set all values in the matrix
	void setValue(double element, int i, int j); // Set a value in the matrix
	void setRows(int aRows);		// Set the number of rows
	void setCols(int aCols);		// Set the number of columns
	int getRows() const; 			// Get the number of rows
	int getCols() const; 			// Get the number of columns
	double getValue(int i, int j) const; // Get a value in the matrix
	void add(Matrix aMatrix);		// Add two matrices
	void subtract(Matrix aMatrix);  // Subtract two matrices
	void Hadamard(Matrix aMatrix); // Multiply two matrices
	void display();					// Display the matrix
};

