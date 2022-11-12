#include<bits/stdc++.h>
using namespace std;

int fastFib(int n)
{
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<=n+1; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the term you want to print" << endl;
    cin >> n;
    cout << fastFib(n);
    return 0;
}