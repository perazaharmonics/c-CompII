#pragma once
class Matrix {
private:
	double** matrix;
	int rows;
	int cols;
public:
	Matrix();
	Matrix(int aRows, int aCols);
	Matrix(const Matrix& obj);
	~Matrix();
	double** createMatrix();
	void setAllValues();
	void setValue(double value, int i, int j);
	void setRows(int aRows);
	void setCols(int aCols);
	int getRows() const;
	int getCols() const;
	double getValue(int i, int j) const;
	void add(Matrix aMatrix);
	void display();
};