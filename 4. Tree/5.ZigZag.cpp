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

    vector<vector<int>> zigzag(TreeNode* root, vector<vector<int>>& ans)
    {
        bool flag = true;
        if(root ==NULL)
            return ans;
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                int size = q.size();
                vector<int> temp(size);
                if(flag)
                {
                    for(int i=0; i<size; i++)
                    {
                        TreeNode* num = q.front();
                        q.pop();
                        if(num->left)
                            q.push(num->left);
                        if(num->right)
                            q.push(num->right);
                        temp[i] = num->data;
                    }
                    ans.push_back(temp);
                    flag =  false;
                }
                else
                {
                    for(int i=0; i<size; i++)
                    {
                        TreeNode* num = q.front();
                        q.pop();
                        if(num->left)
                            q.push(num->left);
                        if(num->right)
                            q.push(num->right);
                        temp[size-i-1] = num->data;
                    }
                    ans.push_back(temp);
                    flag =  true;
                }
            }
        }
        return ans;
    }

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
                    struct TreeNode* temp = q.front();
                    q.pop();
                    // Insert at left if not present and move left if present
                    if(temp->left)
                    {
                        q.push(temp->left);
                    }
                    else
                    {
                        temp->left = newnode;
                        return root;
                    }

                    // Insert at right if not present and move right if present
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
};

int main()
{
    Tree tr;
    vector<vector<int>> ans;     
    TreeNode *root = tr.insertNode(10);
    tr.insertNode(20);
    tr.insertNode(30);
    tr.insertNode(40);
    tr.insertNode(50);
    tr.insertNode(60);

    ans = tr.zigzag(root, ans);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}