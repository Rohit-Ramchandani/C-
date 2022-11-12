#include<bits/stdc++.h>
using namespace std;

int duplicate(vector<int>& arr)
{
    int ans;
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=i+1; j<arr.size(); j++)
        {
            if(arr[i]==arr[j])
                return arr[j];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1,3,4,5,2};
    cout << duplicate(nums);
    return 0;
}