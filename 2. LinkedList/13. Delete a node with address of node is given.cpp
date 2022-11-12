#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

};

void deleteNode(Node* node)
{
    Node* del = node;
    Node* del1 = node->next;
    del->data = del->next->data;
    del->next = del->next->next;
    free(del1);
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head;
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    print(head);
    
    deleteNode(head->next->next->next->next);
    
    print(head);
    
    return 0;
}