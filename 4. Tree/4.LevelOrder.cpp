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
    
    Tree(){ root = NULL;}

    TreeNode* insertNode(int data)
    {
        struct TreeNode* newnode = new TreeNode(data);
        //If tree is empty insert at root and return
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
                    TreeNode* temp = q.front();
                    q.pop();
                    //If left exist move to the left and if not insert at left
                    if(temp->left)
                    {
                        q.push(temp->left);
                    }
                    else
                    {
                        temp -> left = newnode;
                        return root;
                    }

                    //If right exist move to the right and if not insert at right
                    if(temp->right)
                    {
                        q.push(temp->right);
                    }
                    else
                    {
                        temp -> right = newnode;
                        return root;
                    }
                }
            }
        }
        return root;
    }

    void levelOrder(TreeNode* root)
    {
        if(root == NULL)
        {
            cout << " ";
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

                    cout << temp->data << " ";

                    if(temp->left)
                    {
                        q.push(temp->left);
                    }
                    if(temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Tree tr;
    TreeNode* root;
    root = tr.insertNode(10);
    tr.insertNode(20);
    tr.insertNode(30);
    tr.insertNode(40);
    tr.insertNode(50);
    tr.insertNode(60);
    tr.insertNode(70);
    tr.insertNode(80);

    tr.levelOrder(root);
    return 0;
}
