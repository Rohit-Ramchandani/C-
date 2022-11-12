#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertIntoBST(TreeNode* &root, int d)
{
    if(root == NULL)
    {
        root = new TreeNode(d);
        return root;
    }

    if(root->data > d)
        root->left = insertIntoBST(root->left, d);
    else
        root->right = insertIntoBST(root->right, d);

    return root;
}

void takeInput(TreeNode* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrder(TreeNode* root)
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
}


void inorder(TreeNode* root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(TreeNode* root)
{
    if(root==NULL)
        return;
    else
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
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

int main()
{
    TreeNode* root = NULL;
    cout << "Enter data to create a BST" << endl;
    takeInput(root);

    cout << "Level Order Traversal" << endl;
    levelOrder(root);
    cout << endl;

    cout << "Post Order Traversal" << endl;
    postorder(root);
    cout << endl;

    cout << "Pre Order Traversal" << endl;
    preorder(root);
    cout << endl;

    cout << "In Order Traversal" << endl;
    inorder(root);
    cout << endl;

    return 0;
}