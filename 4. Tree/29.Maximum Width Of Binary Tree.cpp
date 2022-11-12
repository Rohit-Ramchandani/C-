#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data)
    {
        left = NULL;
        right = NULL;
        this->data = data;        
    }
};

int width(TreeNode* root)
{
    if(root == NULL) return 0;
    
    int ans;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {

    }
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(4);
    return 0;
}
