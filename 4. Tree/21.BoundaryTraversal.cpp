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

bool isLeaf(TreeNode* root)
{
    if(!root->left && !root->right) return true;
    else return false;
}

void printLeft(TreeNode* root)
{
    TreeNode* cur = root->left;

    while(cur)
    {
        if(!isLeaf(cur)) cout << cur->data << " ";
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void printRight(TreeNode* root)
{
    TreeNode* cur = root->right;
    vector<int> rev;
    while(cur)
    {
        if(!isLeaf(cur)) rev.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }

    int size = rev.size();
    for(int i=0; i<size; i++)
    {
        cout << rev[size-i-1] << " ";
    }
}

void printLeaf(TreeNode* root)
{
    if(isLeaf(root)) 
    {
        cout << root->data << " ";
        return;
    }

    if(root->left) printLeaf(root->left);
    if(root->right) printLeaf(root->right);
}

void printBoundary(TreeNode* root)
{
    printLeft(root);
    printLeaf(root);
    printRight(root);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    root->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);

    cout << root->data << " ";
    printBoundary(root);
    return 0;
}