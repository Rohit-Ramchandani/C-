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

void topView(TreeNode* root)
{    
    vector<int> ans;
    if(root == NULL) return;

    map<int, int> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        pair<TreeNode*, int> p = q.front();
        q.pop();

        TreeNode* front = p.first;
        int hrdist = p.second;

        if(mp.find(hrdist) == mp.end())
            mp[hrdist] = front->data;
        if(front->left)
            q.push({front->left, hrdist-1});            
        if(front->right)
            q.push({front->right, hrdist+1});
    }
    
    for(auto i : mp)
        ans.push_back(i.second);
    
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->left->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    topView(root);
    
    return 0;
}