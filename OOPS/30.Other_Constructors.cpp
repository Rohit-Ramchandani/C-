#include<iostream>
using namespace std;

class Complex
{
    int a;
    int b;

    public:
    Complex(int, int);
    void printNumber()
    {
        cout << "The complex number is " << a << "+" <<b <<"i" << endl;
    }
};

Complex :: Complex(int x, int y)
{
    a = x;
    b = y;
}

int main()
{
    // Implicit Call
    Complex a(10,20);
    a.printNumber();

    // Explicit Call
    Complex b = Complex(5,7);
    b.printNumber();

}