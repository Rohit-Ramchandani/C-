#include<iostream>
using namespace std;

int fibo(int x)
{
    int last;
    int slast;
    if(x<=1)
        return 1;
    else
        last =  fibo(x-1);
        slast = fibo(x-2);
        return (last+slast); 

}

int main()
{
    int n;
    cin >> n;

    cout << fibo(n);
    return 0;
}