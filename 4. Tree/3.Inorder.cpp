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

struct Tree
{
    struct TreeNode* root;

    Tree(){root = NULL;}

    TreeNode* insertNode(int data)
    {
        struct TreeNode* newnode = new TreeNode(data);
        if(root==NULL)
        {
            root = newnode;
            return root;
        }
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                int size = q.size();
                for(int i=0; i<size; i++)
                {
                    TreeNode* temp = q.front();
                    q.pop();
                    if(temp->left)
                    {
                        q.push(temp->left);
                    }
                    else
                    {
                        temp->left = newnode;
                        return root;
                    }

                    if(temp->right)
                    {
                        q.push(temp->right);
                    }
                    else
                    {
                        temp->right = newnode;
                        return root;
                    }
                }
            }
        }
        return root;
    }

    void inorder(TreeNode* root)
    {
        if(root==NULL)
            cout << " ";
        else
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main()
{
    Tree tr;
    TreeNode* root = tr.insertNode(10);
    tr.insertNode(20);
    tr.insertNode(30);
    tr.insertNode(40);
    tr.insertNode(50);
    tr.insertNode(60);
    tr.inorder(root);
    return 0;
}
