#include <iostream>
using namespace std;
class Fraction
{
    int num, den;
    public:
        Fraction(int n, int d): num(n), den(d) {}
        operator float() const 
        {
            return float(num)/float(den);
        }
    
};

int main()
{
    Fraction f(3, 4);
    float val = f;
    cout << val << endl;
    return 0;
}