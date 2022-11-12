#include<iostream>
using namespace std;

class Employee
{
    /* Private member cannot be accessed outside the class through the object
       it can only be accessed through the public functions of the class
    */
    private:
        int a, b, c;

    public:
        int d, e;

        // Declaration of the public function
        void setData(int a1, int b1, int c1);
        
        void getData()
        {
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of d is "<<d<<endl;
            cout<<"The value of e is "<<e<<endl;
        }
};

// Definition of the public function using scope resolution operator
void Employee :: setData(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}

int main()
{
    Employee ep;
    ep.setData(1,2,3);   
    //ep.a = 50; It will give error
    ep.d = 4;
    ep.e = 5;
    ep.getData();
    return 0;
}