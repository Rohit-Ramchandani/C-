#include<iostream>
using namespace std;

void fact(int i, int x)
{
    if(x == 1)
        cout << i;
    fact(i*x, x-1);
}

int main()
{
    int n;
    cin >> n;

    fact(1,n);
    return 0;
}