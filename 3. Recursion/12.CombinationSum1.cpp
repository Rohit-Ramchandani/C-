#include <bits/stdc++.h>
using namespace std;
 
void findCombination(int ind, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int> ds)
{
    if(ind == arr.size())
    {
        if(target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    
    if(arr[ind] <=target)
    {
        ds.push_back(arr[ind]);
        findCombination(ind, arr, target-arr[ind], ans, ds);
        ds.pop_back();            
    }
    
    findCombination(ind+1, arr, target, ans, ds);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) 
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, arr, target, ans, ds);
    return ans;
}

int main()
{
    vector<int> ar = {2, 4, 6, 8};
    int n = ar.size();
 
    int sum = 8;
    vector<vector<int> > res = combinationSum(ar, sum);
 
    if (res.size() == 0) {
        cout << "Empty";
        return 0;
    }
 
    for (int i = 0; i < res.size(); i++) {
        if (res[i].size() > 0) {
            cout << " ( ";
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << ")";
        }
    }
  return 0;
}
