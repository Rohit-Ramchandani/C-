/*
1. Reusability is a very important feature of OOPs
2. In C++ we can reuse a class and add additional features to it
3. Reusing classes saves time and money
4. Reusing already tested and debugged classes will save a lot of effort of developing and debugging the same thing again

What is Inheritance in C++?
1. The concept of reusability in C++ is supported using inheritance.
2. We can reuse the properties of an existing class by inheriting it.
3. The existing class is called a base class.
4. The new class which is inherited from the base class is called a derived class.
5. Reusing classes saves time and money.
*/

#include<iostream>
using namespace std;


class Animal
{
    public:
    void legs()
    {
        cout << "Has four Legs"<< endl;
    }
};

class Dog : public Animal
{
    public:
    void dog()
    {
        cout << "Barks"<< endl;
    }
};

class Cat : public Animal
{
    public:
    void cat()
    {
        cout << "Meow"<< endl;
    }
};

int main()
{
    Dog dg;
    cout << "dog" << endl;
    dg.dog();
    dg.legs();

    Cat ct;
    cout << "cat" << endl;
    ct.cat();
    ct.legs();

    return 0;
}