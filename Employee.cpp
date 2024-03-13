#include <iostream>
#include <iomanip>
using namespace::std;
#include "Employee.h"

Employee::Employee(string aName, int anIdNumber, string aDepartment, string aPosition) { // initialize object with parametric constructor
    setName(aName);
    setIdNumber(anIdNumber);
    setDepartment(aDepartment);
    setPosition(aPosition);
}
Employee::~Employee() {
    cout << "Employee object " << name << " destroyed" << endl;
}
void Employee::setName(string aName) {
    name = aName;
}
void Employee::setIdNumber(int anIdNumber)
{
    idNumber = anIdNumber;
}
void Employee::setDepartment(string aDepartment) {
    department = aDepartment;
}
void Employee::setPosition(string aPosition) {
    position = aPosition;
}
void Employee::setNumEmployee(int anumEmployees) {
    numEmployees = anumEmployees;
}
void Employee::setEmployee(string name, int idNumber, string department, string position) { // set employee object with parameters, update object when needed
    setName(name);
    setIdNumber(idNumber);
    setDepartment(department);
    setPosition(position);
}
string Employee::getName() const {
    return name;
}
int Employee::getIdNumber() const {
    return idNumber;
}
string Employee::getDepartment() const {
    return department;
}
string Employee::getPosition() const {
    return position;
}

int Employee::getNumEmployee() const {
    return numEmployees;
}


int Employee::searchList(const Employee list[], int numEmployees, int employeeId)
{
    int index = 0; // Used as a subscript to search array
    int position = -1; // To record position of search value
    bool found = false; // Flag to indicate if the value was found
    while (index < numEmployees && !found)
    {
        if (list[index].getIdNumber() == employeeId) // If the value is found
        {
            found = true; // Set the flag
            position = index; // Record the value's subscript
        }
        index++; // Go to the next element
    }
    return position; // Return the position, or -1
}

bool Employee::removeEmployee(Employee list[], int& aNumofEmployees, int anIdNumber)
{
    int index = searchList(list, aNumofEmployees, anIdNumber);
    if (index == -1) 
    {
        cout << "The employee was not found in the list" << endl;
        return false;
    }
    else
    {
        for (int i = index; i < aNumofEmployees - 1; i++)
        {
            list[i] = list[i + 1];
        }
        aNumofEmployees--;
        return true;
    }
}

bool Employee::addEmployee(Employee myArrayOfEmployee[], int anumEmployees, std::string aName, int anIdNumber, std::string aDepartment, std::string aPosition) {
    if (anumEmployees < getNumEmployee()) {
        myArrayOfEmployee[anumEmployees].setEmployee(aName, anIdNumber, aDepartment, aPosition);
        anumEmployees++;
        return true;
    }
    cout << "The list is full" << endl;
    return false;
}

void Employee::display() const {
    cout << left << setw(15) << getName() << " " << setw(8) << getIdNumber() << " " << setw(15) << getDepartment() << " " << setw(15) << getPosition() << endl;
    
}