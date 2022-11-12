#include<bits/stdc++.h>
#include<iostream>
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
            //cout << temp->data << " ";
            root = temp;
            return root;
        }
        else
        {
            struct TreeNode* temp = new TreeNode(data);
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                int size = q.size();

                for(int i=0; i<size; i++)
                {
                    TreeNode* curr = q.front();
                    q.pop();

                    if(curr->left)
                    {
                        curr = curr->left;
                    }
                    else
                    {
                        curr->left = temp;
                        //cout << curr->left ->data << " ";
                        return root;
                    }

                    if(curr->right)
                    {
                        curr = curr->right;
                    }
                    else
                    {
                        curr->right = temp;
                        //cout << curr->right ->data << " ";
                        return root;
                    }
                }
            }
        } 
        return root;
    }

    void preorder(TreeNode* root)
    {
        if(root==NULL)
            cout << " ";
        else
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
};


int main()
{
    Tree tr;
    TreeNode* root =  tr.insertNode(10);
    tr.insertNode(20);
    tr.insertNode(30);
    tr.preorder(root);
    return 0;
}