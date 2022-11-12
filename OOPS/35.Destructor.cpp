#include<iostream>
using namespace std;

/*
A destructor is a type of function which is called when the object is destroyed. 
Destructor never takes an argument nor does it return any value.
*/

int count = 0;

class num
{
    public:
    num()
    {
        cout << "Constructor is called!!!" << endl;
        //cout << count<<endl;
        count++;
    }

    ~num()
    {
        cout << "Destructor is called!!!" << endl;
        //cout << count<<endl;
        count--;
    }
};

int main()
{
    cout<<"We are inside our main function"<<endl;
    cout<<"Creating first object n1"<<endl;
    num n1;
    {
        cout<<"Entering this block"<<endl;
        cout<<"Creating two more objects"<<endl;
        num n2, n3;
        cout<<"Exiting this block"<<endl;
    }
    cout<<"Back to main"<<endl;
}