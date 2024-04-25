#include <iostream>
using namespace::std;

class Complex
{
    private:
        int real, imag;
    public:
        Complex(int r = 0, int i = 0) : real(r), imag(i) {};    
        void print() { cout << real << " + i" << imag << endl; }
        // operator overloading syntax: return_type operator op (argument_type)
        Complex operator +(Complex c) {Complex temp; temp.real = real + c.real; temp.imag = imag + c.imag; return temp;}
};

int main()
{
    Complex c1(5, 4);
    Complex c2(2, 5);
    Complex c3(1, 1), c4;

    // Adding two complex numbers using operator overloading 
    c4 = c1 + c2 + c3; // c1.operator+(c2) -> c1 + c2 (binary operations given they operate on two objects at a time) -> c1.operator+(c2) + c3 -> c1 + c2 + c3
    c4.print(); // 8 + i10
    ++c4; // prefix increment unary operator
    c4.print(); // 9 + i11
    c4++; // postfix increment unary operator
    c4.print(); // 10 + i12

    // ternary operator with operator overloading
    c4 = (c1 > c2) ? c1 : c2; // c1.operator>(c2) -> c1 > c2 -> c1.operator>(c2) ? c1 : c2



    // Adding two numbers with primitive data types
    // int x=5;
    // int y = 4;
    // int z = x + y;
    // cout << "z value is: " << z << endl; // "z value is: 9"
    return 0;
}