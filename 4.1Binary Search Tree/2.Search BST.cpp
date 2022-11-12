#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

struct BST
{
    TreeNode* root;
    BST() { root = NULL;}

    TreeNode* insertBST(int data)
    {
        TreeNode* newnode = new TreeNode(data);
        if(root == NULL)
        {
            root = newnode;
            return root;
        }
        else
        {
            TreeNode* temp = root;
            while(temp->left != NULL && temp->right != NULL)
            {
                if(temp -> data > data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }

            if(temp->data > data)
                temp->left = newnode;
            else
                temp->right = newnode;
        }
        return root;
    }

    void levelorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        else
        {
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty())
            {
                int size = q.size();
                for(int i=0; i<size; i++)
                {
                    TreeNode* val = q.front();
                    q.pop();
                    cout << val->data << " ";                    
                    if(val->left)
                        q.push(val->left);
                    if(val->right)
                        q.push(val->right);
                }
            }
        }
    }
};

int main()
{
    BST bst;
    TreeNode* root = bst.insertBST(50);
    bst.insertBST(60);
    bst.insertBST(70);
    bst.insertBST(30);
    bst.insertBST(20);
    bst.insertBST(40);
    bst.levelorder(root);
    cout << endl;
    return 0;
}

