
#include <iostream>
#include<iomanip>
using namespace::std;
#include"TestScores.h"

int main() {
	const int MAX_CAPACITY = 80;
	int* myGrades = nullptr;
	char* aStdName = nullptr;
	char* aStdId = nullptr;

	myGrades = new int(3);
	*(myGrades + 0) = 34;
	*(myGrades + 1) = 67;
	*(myGrades + 2) = 12;

	aStdName = new char[strlen("Bryan Garcia") + 1];
	strcpy_s(aStdName, strlen("Bryan Garcia") + 1, "Bryan Garcia");
	aStdId = new char[strlen("09087") + 1];
	strcpy_s(aStdId, strlen("09087") + 1, "09087");


	TestScores student1;
	TestScores student2(2);
	TestScores student3(aStdName, aStdId, myGrades, 3);


	int score;

	student1.display();
	cout << "Enter the student name:";
	cin.getline(aStdName, MAX_CAPACITY);
	student2.setStudentName(aStdName);
	cin.ignore();
	cout << "Enter the studentId:";
	cin.getline(aStdId, MAX_CAPACITY);
	student2.setStudentId(aStdId);
	cout << "Enter " << student2.getScoresCount()
		<< " test scores of " << student2.getStudentName()
		<< ":" << endl;
	for (int index = 0; index < student2.getScoresCount(); index++) {
		cout << "Enter score  # " << index + 1 << ":";
		cin >> score;
		while (score < 0 || score >100) {
			cout << "Score invalid! , enter the integerscore within the range[0, 100]" << endl;
			cout << "Enter score for student # " << index + 1 << ":";
			cin >> score;
		}//end while
		student2.setScore(index, score);
	}//end for
	student2.display();
	student3.display();

	TestScores student4(student2);
	student4.display();
	return 0;
}//end main