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

Node* rotateRight(Node* head, int k) 
{
    // Cover Edge Cases i.e. lsi
    if(!head || !head->next || k==0) return head;
    
    int len = 1;
    Node* temp = head;
    while(temp->next)
    {
        temp = temp->next;
        len++;
    }
    
    if(k > len)
        k = k % len;
    
    Node* fn;    
    int counter = k;
    while(counter)
    {
        Node* fast = head;
        
        while(fast->next->next)
            fast = fast ->next;
        
        fn = fast->next;
        fn -> next = head;
        head = fn;
        fast -> next = NULL;
        counter--;
    }
    return head;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);

    print(head);

    head = rotateRight(head,3);

    print(head);
    return 0;
}
