#include<iostream>
using namespace std;

class Complex
{
    int x,y;

    public:
    Complex()
    {
        x = 0;
        y = 0;
    }

    //Constructor overloading
    Complex(int a)
    {
        x = a;
        y = 0;
    }

    //Constructor overloading
    Complex(int a, int b)
    {
        x = a;
        y = b;
    }

    void display()
    {
        cout << "The complex number is given by (" << x << "+" <<y << "i" << ")"<<endl;
    }
};

int main()
{
    Complex a;
    a.display();

    Complex b(5);
    b.display();

    Complex c = Complex(1,2);
    c.display();

    return 0;
}
