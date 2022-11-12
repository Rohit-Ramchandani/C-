#include<bits/stdc++.h>
using namespace std;

void brutesetzero(vector<vector<int>>& arr)
{
    //Set 1 to -1 for all the numbers in the matrix
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); i++)
        {
            if(arr[i][j] == 0)
            {
                int ind = i-1;
                while(i<=arr.size())
                {
                    if(arr[ind][j]!=0)
                        arr[ind][j] = -1;
                }
                int ind = i+1;

                int ind = j-1;

                int ind = j+1;

            }
        }
    } 
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
    //brutesetzero(arr);
    return 0;
}