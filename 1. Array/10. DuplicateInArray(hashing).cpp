#include<bits/stdc++.h>
using namespace std;

int duplicate(vector<int>& arr)
{
    unordered_map<int,int> map(5);
    for(int i=0; i<arr.size(); i++)
    {
        if(map[arr[i]]==0)
        {
            map[arr[i]]++;
        }
        
        if(map[arr[i]] > 0)
        {    
            return arr[i];
        }

        xyz
    }

}

int main()
{
    vector<int> nums = {1,3,4,5,2};
    cout << duplicate(nums);
    return 0;
}