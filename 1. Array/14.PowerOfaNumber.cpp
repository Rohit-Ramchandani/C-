#include<iostream>
using namespace std;

int power(int x, int a)
{
    int ans = 1;
    for(int i=0; i<a; i++)
        ans *= x;
    return ans;
}

int pow(int x, int a)
{
    while(a)
    {
        
    }
}

int main()
{
    cout << power(2,5) << endl;
    cout << pow(2,5) << endl;
    return 0;
}
