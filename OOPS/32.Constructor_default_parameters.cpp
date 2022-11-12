#include<iostream>
using namespace std;

class Simple
{
    int d1,d2,d3;

    public:
    Simple(int a, int b = 20, int c = 30)
    {
        d1 = a;
        d2 = b;
        d3 = c;
    }
    void display()
    {
        cout << "The number in the class are " << d1 << ","<< d2 << "," << d3;
    }
};

int main()
{
    Simple x(5);
    x.display();
}