#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data= data;
        next = NULL;
    }
};

struct Node* commonpoint(struct Node* a ,struct Node* b)
{
    struct Node* x = a;
    struct Node* y = b;
    
    while(x!=y)
    {
        x = x==NULL? b: x->next;
        y = y==NULL? a: y->next;
    }

    return x;
}

void print(Node* head)
{
    struct Node* tmp = head;
    while(tmp!=NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    struct Node* head1=NULL;
    head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = new Node(40);
    head1->next->next->next->next = new Node(50);
    head1->next->next->next->next->next = new Node(60);
    
    struct Node* head2;
    head2 = new Node(11);
    head2->next = new Node(21);
    head2->next->next = new Node(31);
    head2->next->next->next = head1->next->next;

    print(head1);
    print(head2);

    struct Node* common = commonpoint(head1, head2);
    cout << common->data << " ";
    
    return 0;
}