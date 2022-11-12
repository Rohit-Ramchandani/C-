#include<iostream>
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
    if(root==NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

int main()
{
    TreeNode* root =  new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(20);
    root->right->left = new TreeNode(30);

    cout << height(root);
    return 0;
}