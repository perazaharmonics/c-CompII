#pragma once
#include<iostream>
#include <string>
using namespace::std;


class TestScores {

private:
	char* studentName;
	char* studentId;
	int* scores;
	int scoresCount;

public:
	TestScores();
	TestScores(int aScoresCount);
	TestScores(char* aStdName, char* aStdId, int* aScores, int aScoresCount);
	TestScores(const TestScores& obj);
	~TestScores();
	void setScore(int index, int score);
	void setStudentId(char* aStdName);
	void setStudentName(char* aStdId);

	void setAllScores(int* aScores, int aScoresCount);
	void setScoresCount(int aScoresCount);
	int getScoresCount() const;
	char* getStudentName() const;
	char* getStudentId() const;
	int* getAllScores() const;
	int getScore(int index) const;
	double getAverage() const;
	char getLetterGrade() const;
	void display() const;
};