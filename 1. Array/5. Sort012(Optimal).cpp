#include<bits/stdc++.h>
using namespace std;

void dfl(vector<int>& arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size()-1;

    while(mid <= high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
            mid++;
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {1,2,2,1,2,1,1,2,2,0,0,1,0,2,0};
    dfl(arr);
    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}

