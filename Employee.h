#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <iostream>
#include<string>
using namespace::std;
class Employee {
private:
	string name;
	int idNumber;
	int numEmployees;
	string department;
	string position;
	
	
public:
	Employee(string aName = "", int anIdNumber = 0, string aDepartment = "", string aPosition = "");
	~Employee();
	void setEmployee(string aName, int anIdNumber, string aDepartment, string aPosition);
	void setName(string aName);
	void setIdNumber(int idNumber);
	void setDepartment(string aDepartment);
	void setPosition(string aPosition);
	void setNumEmployee(int anumEmployees);
	string getName() const;
	int getIdNumber() const;
	string getDepartment() const;
	string getPosition() const;
	int getNumEmployee() const;
	int searchList(const Employee list[], int anumEmployees, int anIdNumber);
	bool removeEmployee(Employee list[],  int& anumEmployees, int anIdNumber);
	bool addEmployee(Employee list[], int anumEmployees, string aName, int anIdNumber, string aDepartment, string aPosition);
	void display() const;
};
#endif