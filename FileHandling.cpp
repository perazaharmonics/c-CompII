// FileHandling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char name[100];
    char name1[100];
    cout << "Enter your name and age: ";
    cin.getline(name, 100); // we use getline(name, 100) so the file does not close after the space that goes following the name
    //myfile.open("example.txt"); // open a file

    ofstream myfile("example.txt",ios::out|ios::app); // create a file ofstream is the data type, the name of the file acts as a constructor.
                                            // Myfile is the object-variable, ios::app is the mode of the file to append the data instead of replacing it
    if (myfile.is_open()) // check if the file is open
    {
		myfile << name; // write to the file
		myfile.close(); // close the file
        cout<< "Data has been written to the file" << endl<<endl;
	}
    else
    {
		cout << "Unable to open file";
	}
    cout<< "Reading from the file" << endl;
    ifstream obj("example.txt"); // read from the file
    obj.get(name1, 100); // get the data from the file
    cout<< "Array content: "<<name1 << endl;
    cout << "File reading was successful" << endl;
    obj.close(); // close the file

    return 0;

}
