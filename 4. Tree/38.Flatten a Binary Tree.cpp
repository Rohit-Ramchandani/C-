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

/*
Morris Traversal 
Time Complexity = O(n)
Space Complexity = O(1)
*/
void flatten(TreeNode *root)
{
    TreeNode* curr = root;
    while(curr!=NULL)
    {
        if(curr->left)
        {
            TreeNode* pred = curr->left;
            
            while(pred->right)
                pred = pred->right;
            
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void printTree(TreeNode* root)
{
    if(root == NULL)
        return;
    
    else
    {
        cout << root->data << " ";
        printTree(root->right);
        printTree(root->left);
    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);

    root -> left -> left = new TreeNode(3);
    root -> left -> right = new TreeNode(4);

    root -> right = new TreeNode(5);
    root -> right -> right = new TreeNode(6);

    flatten(root);
    printTree(root);
    return 0;
}