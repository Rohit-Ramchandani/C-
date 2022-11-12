#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = right =  NULL;
    }
};

Node* sortedhelper(vector<int>& nums, int start, int end)
{
    if(start > end) return NULL;
    int mid = start + (end-start)/2;
    Node* root = new Node(nums[mid]);
    root->left = sortedhelper(nums, start, mid-1);
    root->right = sortedhelper(nums, mid+1, end);
    return root;
}

Node* sortedArrayToBST(vector<int>& nums) 
{
    int size = nums.size();
    Node* root = sortedhelper(nums, 0, size-1);
    return root;
}

void levelOrder(Node* root)
{
    if(root == NULL)
        return;
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                Node* temp = q.front();
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
            cout << endl;
        }
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* root = sortedArrayToBST(arr);
    levelOrder(root);
    return 0;
}