#include "bits/stdc++.h"
#include<vector>
#include<iostream>
using namespace std;

void printSub(int arr[], int index , vector<int> &ds , int n , int sum , int k)
{
    if(index == n){
        if(sum == k){
            for(auto it : ds)cout << it << " ";
            cout << endl;
        }
        return;
    }
    
    // Pick the element
    ds.push_back(arr[index]);
    sum = sum + arr[index];
    printSub(arr, index+1, ds,n,sum,k);
    ds.pop_back();
    sum = sum - arr[index];

    // Do not pick the element
    printSub(arr, index+1, ds,n,sum,k);
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