#include<bits/stdc++.h>
using namespace std;

class Polymorphism
{
    public:
    void func()
    {
        cout << "This is function with no argument" << endl;
    }

    void func(int data)
    {
        cout << "This is a function with integer argument" << endl;
    }

    void func(double data)
    {
        cout << "This is a function with double argument" << endl;
    }
};

int main()
{
    Polymorphism pm;
    pm.func();
    pm.func(10);
    pm.func(10.20);
    return 0;
}