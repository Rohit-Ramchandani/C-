#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void verticalTrav(TreeNode* root)
{
    map<int, map<int, vector<int>>> mp;
    queue<pair<TreeNode*, pair<int,int>>> q;
    q.push({root,{0,0}});

    while(!q.empty())
    {
        pair<TreeNode*, pair<int,int>> p = q.front();
        q.pop();

        TreeNode* temp = p.first;
        int hrdist = p.second.first;
        int vrdist = p.second.second;

        mp[hrdist][vrdist].push_back(temp->data);

        if(temp->left)
        {
            q.push(make_pair(temp->left,make_pair(hrdist-1, vrdist+1)));
        }
        if(temp->right)
        {
            q.push(make_pair(temp->right,make_pair(hrdist+1, vrdist+1)));
        }
    }

    vector<vector<int>> ans;
    for(auto i : mp)
    {
        vector<int> tmp;
        for(auto j : i.second)
        {
            ans.push_back(j.second);
        }
    }
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    
    root->right->left = new TreeNode(9); 
    root->right->right = new TreeNode(10);
    
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    verticalTrav(root);
    return 0;
}