#include<iostream>
using namespace std;

/*
Constructors in C++ :-
1. A constructor is a special member function with the same name as the class. 
2. The constructor doesn’t have a return type. 
3. Constructors are used to initialize the objects of its class. 
4. Constructors are automatically invoked whenever an object is created.

Important Characteristics of Constructors in C++ :-
1. A constructor should be declared in the public section of the class.
2. They are automatically invoked whenever the object is created.
3. They cannot return values and do not have return types.
4. It can have default arguments.
5. We cannot refer to their address.
*/

class Complex
{
    int a,b;
    
    public:
    Complex(void);

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

Complex :: Complex()
{
    a = 10;
    b = 0;
}

int main()
{
    Complex c1, c2, c3;
    c1.printNumber();
    c2.printNumber();
    c3.printNumber();  
}

