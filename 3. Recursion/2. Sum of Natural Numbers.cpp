#include "bits/stdc++.h"
#include<vector>
#include<iostream>
using namespace std;

void sum(int n, int i)
{
    if(n==0)
    {
        cout<< i << " ";
        return;
    }    
    else
    {
        sum(n-1,i+n);
    }
}

int main()
{
    int n = 3;
    sum(n,0);
    return 0;
}