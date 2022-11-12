#include "bits/stdc++.h"
#include<vector>
#include<iostream>
using namespace std;

int printSub(int arr[], int index , int n , int sum , int k)
{
    if(index == n){
        if(sum == k) return 1;
        else return 0;
    }
    
    // Pick the element
    sum = sum + arr[index];
    int left = printSub(arr, index+1, n, sum, k);
    sum = sum - arr[index];

    // Do not pick the element
    int right = printSub(arr, index+1, n, sum, k);

    return left + right;
}

int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    int k = 2;
    cout << printSub(arr,0,n,0,k);
    return 0;
}