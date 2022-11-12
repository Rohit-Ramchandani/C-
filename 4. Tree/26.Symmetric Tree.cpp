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

bool helper(TreeNode* left,TreeNode* right)
{
    if(left->data != right->data) return false;

    if(right == NULL ||left == NULL) return left==right;

    else
        return helper(left->left, right->left) && helper(left->right, right->right);

}

bool sameTree(TreeNode* root)
{
    return (root==NULL||helper(root->left, root->right));
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    cout << sameTree(root)<< " Yo";
    return 0;
}