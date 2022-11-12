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

pair<int,int> diameterFast(TreeNode* root)
{
    if(root==NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);
    
    int op1 = left.first;
    int op2 = right.first; // diameter
    int op3 = left.second + right.second + 1; //height

    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(TreeNode* root)
{
    return diameterFast(root).first;
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