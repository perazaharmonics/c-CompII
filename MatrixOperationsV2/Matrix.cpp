#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#include "Matrix.h"

Matrix::Matrix()                       // Default constructor
{
    setRows(2);                       // Set the number of rows to 2 using mutator method setRows()
    setCols(2);		                  // Set the number of columns to 2 using mutator method setCols()
    matrix = createMatrix();         // Create a matrix using the createMatrix() method
}
Matrix::Matrix(int aRows, int aCols) // Constructor with parameters
{
    setRows(aRows);	                 // Set the number of rows to aRows using mutator method setRows()
    setCols(aCols);	                 // Set the number of columns to aCols using mutator method setCols()
    matrix = createMatrix();		 // Create a matrix using the createMatrix() method
}
Matrix::Matrix(const Matrix& obj)
{
    cout << "\nCalled copy-constructor" << endl;
    setRows(obj.getRows());          // Set the number of rows to the number of rows in obj using mutator method setRows()
    setCols(obj.getCols());          // Set the number of columns to the number of columns in obj using mutator method setCols()
    matrix = createMatrix();         // Create a matrix using the createMatrix() method
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            matrix[i][j] = obj.matrix[i][j];
        }//end for
    }//end for
}
Matrix::~Matrix()					 // Destructor
{
    cout << "\n Destructor is in action!" << endl; // Display a message
    if (matrix != nullptr)			 // If the matrix is not a null pointer
    {
        for (int i = 0; i < getRows(); i++) // Loop through the row elements and delete the allocated memory
        {
            delete[] matrix[i]; 		// Delete the memory allocated for the columns
        }//end for
        delete[] matrix;				// Delete the memory allocated for the rows
        matrix = nullptr;				// Set the matrix to a null pointer
    }//end if
    system("pause");					// Pause the system
}
void Matrix::setRows(int aRows)		 // Set the number of rows
{
	rows = aRows;					 // Set the number of rows to aRows
}
void Matrix::setCols(int aCols)		 // Set the number of columns
{
	cols = aCols;					 // Set the number of columns to aCols
}
int Matrix::getRows() const			 // Get the number of rows
{
	return rows;					 // Return the number of rows
}
int Matrix::getCols() const			 // Get the number of columns
{
	return cols;					 // Return the number of columns
}
void Matrix::add(Matrix aMatrix)
{
    Matrix resultingMatrix(getRows(), getCols()); // Create a matrix object resultingMatrix with the same number of rows and columns as the current matrix
    for (int i = 0; i < getRows(); i++)
    { for (int j = 0; j < getCols(); j++)
        {
            resultingMatrix.setValue(getValue(i, j) + aMatrix.getValue(i, j), i, j); // Set the value of the resulting matrix to the sum of the values of the current matrix and aMatrix
        }//end for
    }//end for
    cout << "\nMatrix C = A + B" << endl; // Display a message
    resultingMatrix.display(); // Display the resulting matrix
}
void Matrix::setValue(double value, int i, int j)
{
    matrix[i][j] = value; // Set the value of the matrix at row i and column j to value
}
double Matrix::getValue(int i, int j) const
{
    return matrix[i][j]; // Return the value of the matrix at row i and column j
}
double** Matrix::createMatrix()
{
    double** aMatrix = nullptr; // Declare a pointer to a pointer to a double and set it to a null pointer
    int i, j; // Declare variables i and j
    aMatrix = new double* [getRows()]; // Allocate memory for the rows
    for (; i < getRows(); i++)
    {
        aMatrix[i] = new double[getCols()]; // Allocate memory for the columns
	}//end for
    for (i=0; i < getRows(); i++)
    {
        for (j=0; j < getCols(); j++)
        {
            aMatrix[i][j] = 0.0; // Initialize the matrix elements to 0.0
        }//end for
    }//end for
    return aMatrix; // Return the matrix
}
void Matrix::setAllValue()
{
    double value; // Declare a variable value
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            cout << "Matrix element[" << i << "][" << j << "]: "; // Display matrix positional element
			cin >> value; // Read the value from the user
			setValue(value, i, j); // Set the value of the matrix at row i and column j to value
		}//end for
	}//end for
}
void Matrix::display()
{
    cout << fixed << showpoint << setprecision(2); // Set the output format
    cout<<"\nMatrix elements are: " << endl; // Display a message
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            cout << setw(5) << getValue(i, j)<<" "; // Display the value of the matrix at row i and column j
        }//end for
        cout<< endl; // Move to the next matrix row
    }
}