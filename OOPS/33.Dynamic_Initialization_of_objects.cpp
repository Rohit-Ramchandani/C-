#include <iostream>
using namespace std;

class BankAccount
{
    int principal, years;
    float rate_of_Interest, returnValue;

    public:
    BankAccount(){}
    BankAccount(int p, int y, float r);
    BankAccount(int p, int y, int r);

    void display()
    {
        cout<<endl<<"Principal amount was "<<principal << ". Return value after "<<years<< " years is "<<returnValue<<endl;
    }
};

BankAccount :: BankAccount(int p, int y, float r)
{
    principal = p;
    years = y;
    rate_of_Interest = r;
    for(int i=0; i<years; i++)
    {
        returnValue += returnValue *(1+rate_of_Interest);
    }
}

BankAccount :: BankAccount(int p, int y, int r)
{
    principal = p;
    years = y;
    rate_of_Interest = r;
    for(int i=0; i<years; i++)
    {
        returnValue += returnValue *(1+rate_of_Interest);
    }
}

int main()
{
    BankAccount a1,a2,a3;

    int p;
    int y;
    int r;
    float R;

    cin >> p >> y >> r;
    a2 = BankAccount(p,y,R);
    a2.display();
    
    cin >> p >> y >> r;
    a1 = BankAccount(p,y,r);
    a1.display();

    cin >> p >> y >> r;
    a3 = BankAccount();
    a3.display();
}