#include<iostream>
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


bool sametree(TreeNode* root1, TreeNode* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if((root1==NULL && root2!=NULL)||(root1!=NULL && root2==NULL))
        return false;
    if(root1->data != root2->data)
        return false;
    return (sametree(root1->left , root2->left) && sametree(root1->right,root2->right));
}

int main()
{
    struct TreeNode* root1;
    root1 = new TreeNode(10);
    root1->left = new TreeNode(20);
    root1->right = new TreeNode(30);
    root1->left->left = new TreeNode(40);
    root1->left->right = new TreeNode(50);

    struct TreeNode* root2;
    root2 = new TreeNode(10);
    root2->left = new TreeNode(20);
    root2->right = new TreeNode(30);
    root2->left->left = new TreeNode(40);
    root2->left->right = new TreeNode(50);

    if(sametree(root1,root2)) cout << "Same Tree";
    else cout << "Different Tree";
    return 0;
}