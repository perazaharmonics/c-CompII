/*
Author: Enrique Peraza
Version:1.0
Last Modified: 3/14/2024
*/

#include <iostream>
using namespace std;
class Array
{
    public:
        /*
         * Declaring Variables
        */
        
        int size;
        int* arr;
    public:
        /*
         * Declaring Constructor and Destructor
        */
        
        Array(int s): size(s) 
        {
            arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = 0;
            }
            cout << " Constructor " << endl; 
        };
        ~Array()
        {
            delete [] arr;
            arr = nullptr;
            cout << " \n Destructor Freeing Memory " << endl;
        }
        /*
        * Overloading the operators
        */
       friend std::ostream& operator<<(std::ostream &os, Array &rhs)
       {
        os << " Object Array has Size :: " << rhs.size << endl;
        for (int i = 0; i < rhs.size; i++)
        {
            os << rhs.arr[i] << " ";
        }
        return os;
       }
       void operator() (int index, int data)
       {
              arr[index] = data;
       }
       int &operator()(int index)
       {
        return arr[index];
       }

       Array& operator =(Array &rhs)
{
    cout << " Assignment Operator " << endl;
    if (this == &rhs)
    {
        cout << " Address is the same "<< endl;
        return *this;
    }
    else
    {
        delete [] arr;
        size = rhs.size;
        arr = new int[size];

        for (int i=0; i<size; i++)
        {
            arr[i] = rhs.arr[i];
        }

        return *this;
    }


       }
       public:
         /*
          * Methods
          */
         void addElements(int index, int data)
         {
            arr[index] = data;
         }

         int getData(int index)
         {
            return arr[index];
         }

         


};

int main() {
    Array a1(5);
    a1(0,1);
    a1(1,2);
    a1(2,3);
    cout << a1 << endl;
    Array a2(5);
    a2=a1;
    cout<<a2<<endl;
    //a1.addElements(0, 1);
    a1(0, 11);
    cout << a1(0) << endl;

    return 0;
}
