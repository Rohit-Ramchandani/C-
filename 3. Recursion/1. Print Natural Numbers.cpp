#include "bits/stdc++.h"
#include<vector>
#include<iostream>
using namespace std;

void printN(int n, int i)
{
    if(n==i)
    {
        cout<< i << " ";
        return;
    }    
    else
    {
        cout << i << " ";
        printN(n,i+1);
    }
}

int main()
{
    int n = 3;
    printN(n,1);
    return 0;
}

