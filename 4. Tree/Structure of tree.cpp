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

struct Tree
{
    TreeNode* root;

    Tree() { root = NULL;}

    TreeNode* push(int data)
    {
        TreeNode* newnode = new TreeNode(data);
        if(root == NULL)
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
                    TreeNode* tmp = q.front();
                    q.pop();
                    if(tmp->left) q.push(tmp->left);
                    else{
                        tmp->left = newnode;
                        return root;
                    }

                    if(tmp->right) q.push(tmp->right);
                    else{
                        tmp->right = newnode;
                        return root;
                    }
                }
            }
        }
        return root;
    }

    void preorder(TreeNode* root)
    {
        if(root==NULL) return;
        else
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(TreeNode* root)
    {
        if(root==NULL) return;
        else
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    void inorder(TreeNode* root)
    {
        if(root==NULL) return;
        else
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void levelOrder(TreeNode* root)
    {
        if(root==NULL) return;
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                int size = q.size();
                for(int i=0; i<size; i++)
                {
                    TreeNode* tmp = q.front();
                    q.pop();
                    cout << tmp->data << " ";
                    if(tmp->left != NULL) q.push(tmp->left);
                    if(tmp->right != NULL) q.push(tmp->right);
                }
            }
        }
    }
};

int main()
{
    Tree tr;
    TreeNode* root = tr.push(10);
    tr.push(20);
    tr.push(30);
    tr.push(40);
    tr.preorder(root);
    cout << endl;

    tr.postorder(root);
    cout << endl;
    
    tr.inorder(root);
    cout << endl;

    tr.levelOrder(root);
    cout << endl;

    return 0;
}