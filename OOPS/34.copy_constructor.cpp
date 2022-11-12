#include<iostream>
using namespace std;

class Number
{
    int a;

    public:
    Number()
    {
        a = 0;
    }

    Number(Number &obj)
    {
        cout << "Copy constructor called!!!"<<endl;
        a = obj.a;
    }

    Number(int num)
    {
        a = num;
    }

    void display()
    {
        cout << "The given number is " << a <<endl;
    }
};


int main()
{
    Number x, y, z(45),z2;
    x.display();
    y.display();
    z.display();

    //Copy constructor invoked
    Number z1(z);
    z1.display();

    //Copy constructor not invoked
    z2 = z;
    z2.display();

    //Copy constructor invoked
    Number z3 = z;
    z3.display();

    return 0;
}