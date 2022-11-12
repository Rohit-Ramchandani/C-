#include<iostream>
using namespace std;

class Complex
{
    int a;
    int b;

    public:
    void setNum(int x, int y)
    {
        a = x;
        b = y;
    }

    void complexsum(Complex x, Complex y)
    {
        a = x.a + y.a;
        b = x.b + y.b;
    }

    void getNum()
    {
        cout << "The the complex numbers is "<< a << "+" << b <<"i";
    }
};


int main()
{
    Complex a,b,c;
    a.setNum(1,2);
    //a.getNum();

    b.setNum(3,4);
    //b.getNum();

    c.complexsum(a,b);
    c.getNum();
}