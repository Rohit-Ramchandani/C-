#include<bits/stdc++.h>
using namespace std;

void semioptimal(vector<vector<int>>& arr)
{
}

void print(vector<vector<int>>& arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); i++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;    
    }  
}

int main()
{
    vector<vector<int>> arr = {{1,1,1},
                               {1,0,1},
                               {1,1,1}};
    print(arr);
    semioptimal(arr);
    print(arr);
    return 0;
}