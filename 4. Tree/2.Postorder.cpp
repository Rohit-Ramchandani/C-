#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode()
    {
        data = 0;
        left = right = NULL;
    }
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

struct Tree
{
    struct TreeNode* root;

    Tree(){ root = NULL;}

    TreeNode* insertNode(int data)
    {
        if(root==NULL)
        {
            struct TreeNode* temp = new TreeNode(data);
            root = temp;
            return root;
        }
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                struct TreeNode* newnode = new TreeNode(data);
                int size = q.size();
                for(int i=0; i<size; i++)
                {
                    struct TreeNode* temp = q.front();
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

    void postorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        else
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
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
    tr.postorder(root);
    return 0;
}
