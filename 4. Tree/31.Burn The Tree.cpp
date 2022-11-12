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

// Create Parent Mapping and return target node
TreeNode* createParentMapping(TreeNode* root, int target, map<TreeNode*,TreeNode*>& nodeToParent)
{
    TreeNode* res = NULL;

    queue<TreeNode*> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while(!q.empty())
    {
        TreeNode* front = q.front();
        q.pop();

        if(front->data == target)//Find Target Node
        {
            res = front;
        }
        if(front->left)//Add Parent
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right)//Add Parent
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(TreeNode* targetNode, map<TreeNode*,TreeNode*> nodeToParent)
{
    map<TreeNode*,bool> visited;
    queue<TreeNode*> q;

    q.push(targetNode);    
    visited[targetNode] = true;

    int ans = 0;

    while(!q.empty())
    {
        bool flag  = 0;
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            //Process neighbouring nodes
            TreeNode* front = q.front();
            q.pop();

            if(front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            
            if(front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if(flag == 1)
        {
            ans++;
        }
    }
    return ans;
}

int timeToBurnTree(TreeNode* root, int target)
{
    // Algorithm
    // Step 1. Create nodeToParent Mapping 
    // Step 2. Find the target Node.
    // Step 3. Burn the tree in min Time.
    map<TreeNode*, TreeNode*> nodeToParent;
    TreeNode* targetNode = createParentMapping(root, target, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    root->left->left = new TreeNode(4);
    
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    root->left->left->right = new TreeNode(7);

    cout << timeToBurnTree(root,2);//Node and integer value of the node

    return 0;
}