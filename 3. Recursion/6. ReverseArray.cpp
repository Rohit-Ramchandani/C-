#include "bits/stdc++.h"
#include<vector>
#include<iostream>
using namespace std;

void reverseArr(int arr[], int index, int n)
{
    if(index >= n/2)
        return;
    else
    {
        swap(arr[index], arr[n-index-1]);
        reverseArr(arr, index+1,n);
    }        
}

int main()
{
    int arr[] = {3,1,2};
    int n = 3;
    reverseArr(arr,0,n);

    for(auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
