#include "bits/stdc++.h"
#include<vector>
#include<iostream>
using namespace std;

bool printSub(int arr[], int index , vector<int> &ds , int n , int sum , int k)
{
    if(index == n){
        if(sum == k){
            for(auto it : ds)cout << it << " ";
            cout << endl;
            return true;
        }
        else
            return false;
    }
    
    // Pick the element
    ds.push_back(arr[index]);
    sum = sum + arr[index];
    if(printSub(arr, index+1, ds,n,sum,k)==true) return true;
    ds.pop_back();
    sum = sum - arr[index];

    // Do not pick the element
    if(printSub(arr, index+1, ds,n,sum,k)==true) return true;

    return false;
}

int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    int k = 2;
    vector<int> ds;

    printSub(arr,0,ds,n,0,k);
    return 0;
}