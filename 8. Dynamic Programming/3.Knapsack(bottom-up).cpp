#include<bits/stdc++.h>
using namespace std;

int static dp[102][1002];

int knapsack(int wt[], int val[], int w, int n)
{
    if(n==0 || w==0)
        return 0;
    
    if(dp[n][w] != -1)
        return dp[n][w];

    if(wt[n-1] <= w)
        return dp[n][w] = max(val[n-1] + knapsack(wt, val, w-wt[n-1], n-1),
                            knapsack(wt, val, w, n-1));

    if(wt[n-1] > w)
        return dp[n][w] = knapsack(wt, val, w, n-1);

    return dp[n][w];
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int n = 4;
    int w = 7;
    for(int i=0; i<102; i++)
    {
        for(int j=0; j<1002; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(wt, val, w, n);
    return 0;
}