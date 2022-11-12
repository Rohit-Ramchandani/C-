#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int height(TreeNode* root)
{
    if(root==NULL)
        return 0;

    int left  = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

int diameter(TreeNode* root)
{
    if(root == NULL)
        return 0;
    
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left)+ height(root->right) + 1;

    int ans = max(op1, max(op2,op3));
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(7);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(0);
    root->right->left->left = new TreeNode(3);

    cout << diameter(root);
    return 0;
}