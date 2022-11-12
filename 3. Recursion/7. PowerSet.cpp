#include "bits/stdc++.h"
#include<vector>
#include<iostream>
using namespace std;

void powerSet(int arr[], int index, vector<int> &ds, int n)
{
    if(index == n)
    {
        for(auto it : ds)
        {
            cout << it << " ";
        }
        if(ds.size()==0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    
    // Pick the element
    ds.push_back(arr[index]);
    powerSet(arr, index+1, ds,n);
    ds.pop_back();

    // Do not pick the element
    powerSet(arr, index+1, ds,n);
    
}

int main()
{
    int arr[] = {3,1,2};
    int n = 3;

    vector<int> ds;

    powerSet(arr,0,ds,n);
    return 0;
}
