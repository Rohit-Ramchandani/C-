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

int height(TreeNode* root)
{
    if(root == 0)
        return 0;
    
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(right, left) + 1;
    return ans;
}

bool balancedTree(TreeNode* root)
{
    if(root == NULL)
        return true;
    
    bool left = balancedTree(root->left);
    bool right = balancedTree(root->right);

    bool both = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && both)
        return true;
    else
        return false;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);

    //root->left->left->left = new TreeNode(7);
    //root->left->left->right = new TreeNode(6);
    
    cout << balancedTree(root);
    return 0;
}