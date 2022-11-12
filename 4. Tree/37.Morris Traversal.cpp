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
void morristrav(TreeNode* root)
{
    TreeNode* curr = root;
    while(curr)
    {
        if(curr->left)
        {
            TreeNode* pred = curr->left;
            while(pred->right!=NULL && pred->right!= curr)
                pred = pred->right;

            if(pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
        else
        {
            cout << curr->data << " ";
            curr = curr -> right;
        }
    }
    return;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);

    root -> left -> left = new TreeNode(4);
    root -> left -> left -> right = new TreeNode(7);
    root -> left -> right = new TreeNode(5);

    root -> right = new TreeNode(3);
    root -> right -> right = new TreeNode(6);

    morristrav(root);

    return 0;
}


