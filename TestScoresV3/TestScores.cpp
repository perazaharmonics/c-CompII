include<iostream>
#include<iomanip>
#include<string>
using namespace::std;
#include"TestScores.h"


TestScores::TestScores() {
	const int MAX_CAPACITY = 10;
	cout << "\nWelcome to the default constructor" << endl;
	setStudentName("");
	setStudentId("");
	int* aScores;
	aScores = new int[MAX_CAPACITY];
	memset(aScores, 0, sizeof(int) * MAX_CAPACITY);
	setAllScores(aScores, MAX_CAPACITY);
}


TestScores::TestScores(int aScoresCount) {
	cout << "\nWelcome to the constructor" << endl;
	setStudentName("");
	setStudentId("");
	int* aScores;
	aScores = new int[aScoresCount];
	memset(aScores, 0, sizeof(int) * aScoresCount);
	setAllScores(aScores, aScoresCount);
}


TestScores::TestScores(char* aStdName, char* aStdId, int* aScores, int aScoresCount) {
	cout << "\nWelcome to the constructor" << endl;
	setStudentName(aStdName);
	setStudentId(aStdId);
	setAllScores(aScores, aScoresCount);

}

TestScores::TestScores(const TestScores& obj) {
	cout << "\nWelcome to the copy constructor" << endl;
	setStudentName(obj.getStudentName());
	setStudentId(obj.getStudentId());
	setAllScores(obj.getAllScores(), obj.getScoresCount());

}

TestScores::~TestScores() {
	delete[] studentName;
	delete[] studentId;
	delete[] scores;
	studentName = 0;
	studentId = 0;
	scores = 0;

	cout << "\nDestructor is running!\n";
	system("pause");

}
void TestScores::setStudentName(char* aStdName) {
	int length;
	length = strlen(aStdName) + 1;
	studentName = new char[length];
	strcpy_s(studentName, length, aStdName);
}
void TestScores::setStudentId(char* aStdId) {
	int length;
	length = strlen(aStdId) + 1;
	studentId = new char[length];
	strcpy_s(studentId, length, aStdId);
}

void TestScores::setAllScores(int* aScores, int aScoresCount) {

	scores = new int[aScoresCount];
	scoresCount = aScoresCount;
	for (int index = 0; index < getScoresCount(); index++) {
		setScore(index, *(aScores + index));
	}//end for
}

void TestScores::setScore(int index, int score) {
	if (index >= 0 && index < scoresCount) {
		*(scores + index) = score;
	}
	else {
		cout << "Error, index out of range\n";
	}
}

void TestScores::setScoresCount(int aScoreCount) {
	scoresCount = aScoreCount;
}

int TestScores::getScoresCount() const {
	return scoresCount;
}

int TestScores::getScore(int index) const {

	if (index >= 0 && index < getScoresCount()) {
		return *(scores + index);
	}
	else {
		cout << "Error, index out of range\n";
		return -1;
	}
}


char* TestScores::getStudentName() const {
	return studentName;
}

char* TestScores::getStudentId() const {
	return studentId;
}

int* TestScores::getAllScores() const {
	return scores;
}

double TestScores::getAverage() const {

	double sum, average;
	sum = 0.0;
	for (int i = 0; i < getScoresCount(); i++)
	{
		sum += getScore(i);
	}//end for
	average = (double)sum / getScoresCount();
	return average;
}


char TestScores::getLetterGrade() const {
	// Constants for grade thresholds
	const int A_SCORE = 88,
		B_SCORE = 76,
		C_SCORE = 63,
		D_SCORE = 50;

	double average;
	char letterGrade;
	average = getAverage();

	if (average >= A_SCORE)
	{
		letterGrade = 'A';
	}//end if
	else
	{
		if (average >= B_SCORE)
		{
			letterGrade = 'B';
		}//end if
		else
		{
			if (average >= C_SCORE)
			{
				letterGrade = 'C';
			}//end if
			else
			{
				if (average >= D_SCORE)
				{
					letterGrade = 'D';
				}//end if
				else
				{
					letterGrade = 'F';
				}//end else
			}//end else
		}//end else
	}//end else

	return letterGrade;
}

void TestScores::display() const {
	cout << fixed << showpoint << setprecision(2);
	cout << "\nStudent Name:" << getStudentName() << endl;
	cout << "Student Id: " << getStudentId() << endl;
	cout << "The student grades are: ";
	for (int index = 0; index < getScoresCount(); index++) {
		cout << *(scores + index) << ",";
	}//end for
	cout << "\nThe final grade: " << getAverage() << " " << getLetterGrade() << endl;
}