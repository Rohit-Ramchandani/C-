#include<bits/stdc++.h>
using namespace std;

int binarysearchFast(int arr[], int start, int end, int k)
{
    if(start <= end)
    {
        // Calculate Mid
        int mid = start + (end - start)/2;
        
        // If element is equal to mid
        if(arr[mid] == k)
            return mid;

        //If mid element is less than the element to be found
        if(arr[mid] < k)
            return binarysearchFast(arr, mid+1, end, k);
            
        //If mid element is greater than the element to be found
        else
            return binarysearchFast(arr, start, mid-1, k);
    }
    
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int ans = binarysearchFast(arr, 0, 8, 7);
    cout << ans << " ";
    return 0;
}