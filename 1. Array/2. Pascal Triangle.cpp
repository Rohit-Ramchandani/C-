#include<bits/stdc++.h>
using namespace std;
int biCo(int n, int r)
{
    int ans = 1;
    for(int i=0; i<r; i++)
    {
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}

void pasTri(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
            cout << " ";

        for(int k=0; k<=i; k++)
            cout << biCo(i,k) << " ";

        cout << endl;
    }
}

int main()
{
    int n = 5;
    pasTri(5);
    return 0;
}