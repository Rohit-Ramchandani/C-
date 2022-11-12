#include<bits/stdc++.h>
using namespace std;

void printSpiral(vector<vector<int>>& arr)
{
    int counter = 0;
    int left = 0;
    int right = arr[0].size()-1;
    int top = 0;
    int bottom = arr.size()-1;  
    
    while(left<=right && top<=bottom)
    {
        if(counter == 0)
        {
            for(int i=left ; i<=right; i++)
            {
                //cout << top<<" "<<i <<" ";
                //cout << endl;
                cout << arr[top][i] << " ";
            }
            top++;
        }
        else if(counter == 1)
        {
            for(int i=top ; i<=bottom; i++)
            {
                //cout << i<<" "<<right <<" ";
                //cout << endl;
                cout << arr[i][right] << " ";
            }
            right--;
        }
        else if(counter == 2)
        {
            for(int i=right ; i>=left; i--)
            {
                //cout << bottom<<" "<<i <<" ";
                //cout << endl;
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }
        else
        {
            for(int i=bottom ; i>=top; i--)
            {
                //cout << i<<" "<<left <<" ";
                //cout << endl;
                cout << arr[i][left] << " ";
            }
            left++;
        }
        counter = (counter+1) % 4;
    }    
}

int main()
{
    vector<vector<int>> arr ={{1,2,3},
                              {4,5,6},
                              {7,8,9}};
    printSpiral(arr);
    return 0;
}