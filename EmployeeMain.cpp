#include <iostream> // Include the input/output stream library
#include <string> // Include the string library
#include "Employee.h" // Include the Employee header file
using namespace::std; // Use the standard namespace

void displayEmployee(Employee myArrayOfEmployee[], int n); // Function prototype for displaying employee information

int main (){

    const int SIZE = 5; // Constant variable for the size of the array
    int numEmployees = SIZE; // Variable for the number of employees
    string name, sIdNumber, department, position; // Variables for employee information
    int idNumber; // Variable for employee ID number
    int index; // Variable for storing index
    int choice; // Variable for user choice
    Employee emp; // Employee object
    Employee myArrayOfEmployee[SIZE] = { // Array of Employee objects
        Employee("Enrique", 89423, "STaCS", "DSP Engineer"), // Employee 1
        Employee("Robert", 89426, "SWFO", "Lead RF Engineer"), // Employee 2
        Employee("Rose", 146007, "Software Engineering", "Entry-Level Software Engineer"), // Employee 3
        Employee("Jesus", 89427, "Mechanical Design", "Lead Mechanical Engineer"), // Employee 4
        Employee("Paola", 69426, "Process Engineering", "Senior Chemical Engineer") // Employee 5
    };

    cout << "Welcome to the Employee Management System" << endl; // Display welcome message
    cout<< "The current employees are: " << endl; // Display current employees
    displayEmployee(myArrayOfEmployee, SIZE); // Display employee information
    cout << "\nEnter your desired action: " << "\n" << "1. Add Employee" << "\n" << "2. Remove Employee" << "\n" << "3. Search Employee" << "\n" << "0. Exit" << endl; // Display menu options
    cin >> choice; // Read user choice
    cin.ignore(); // Ignore the newline character

    switch (choice) // Switch statement based on user choice
    {
        case 1: // If choice is 1
        {
            int SIZE2; // Variable for the number of employees to add
            cout << "Enter the number of employees you want to add: "; // Prompt for number of employees
            cin >> SIZE2; // Read number of employees
            cin.ignore();  // Consume the newline character

            // Allocate a new dynamic array
            Employee* dynamicEmployees = new Employee[SIZE + SIZE2];

            // Copy the existing employees to the new array
            for (int i = 0; i < SIZE; ++i) {
                dynamicEmployees[i] = myArrayOfEmployee[i];
            }

            // Add the new employees
            for (int i = 0; i < SIZE2; ++i) {
                cout << "Enter the name of the employee: ";
                getline(cin, name);
                cout << "Enter the id number of the employee: ";
                cin >> idNumber;
                cin.ignore();  // Consume the newline character
                cout << "Enter the department of the employee: ";
                getline(cin, department);
                cout << "Enter the position of the employee: ";
                getline(cin, position);

                dynamicEmployees[SIZE + i].setEmployee(name, idNumber, department, position);
            }

            // Display the new dynamic array
            displayEmployee(dynamicEmployees, SIZE + SIZE2);

            // Delete the new dynamic array to free the memory
            delete[] dynamicEmployees;

            break;
        }
        case 2: { // If choice is 2
            
            cout << "Enter the id number of the employee you want to remove: ";
            cin >> idNumber; // Assuming ID number will be a number not string
            cin.ignore();
            bool removed = emp.removeEmployee(myArrayOfEmployee, numEmployees, idNumber);
            if (removed) {
                cout << "Employee removed successfully." << endl;
            }
            // If you want to display all employees after removal
            displayEmployee(myArrayOfEmployee, numEmployees);
            break;
        }
        case 3: // If choice is 3
        {
            cout << "Enter the id number of the employee you want to search: ";
            getline(cin, sIdNumber);            
            idNumber = stoi(sIdNumber); // Convert string to integer
            index = emp.searchList(myArrayOfEmployee, numEmployees, idNumber);

            if (index == -1)
                cout << "The employee was not found" << endl;
            else
                myArrayOfEmployee[index].display();
            break;
        }
        case 0: // If choice is 0
            cout << "Goodbye" << endl; // Display goodbye message
            break;
    }
}

void displayEmployee(Employee myArrayOfEmployee[], int n) { // Function definition for displaying employee information
    cout << "Name" << "ID Number" << "Department" << "Position" << endl; // Display column headers
    for (int employee = 0; employee < n; employee++) { // Loop through the array of employees
        myArrayOfEmployee[employee].display(); // Display employee information
    } // end for
} // end displayDataEmployee()