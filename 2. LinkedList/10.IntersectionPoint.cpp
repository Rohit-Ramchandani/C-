#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node* intersectionpoint(Node* head1, Node* head2)
{
    int len1=0, len2=0;
    Node* temp1 = head1;   
    Node* temp2 = head2;   

    while(temp1!=NULL)
    {
        len1++;
        temp1 = temp1->next;
    }

    while(temp2!=NULL)
    {
        len2++;
        temp2 = temp2->next;
    }    
    
    temp1 = head1;   
    temp2 = head2;   
    if(len1>len2)
    {
        while(len1!=len2)
        {
            len1--;
            temp1 = temp1->next;
        }
    }
    else
    {
        while(len1!=len2)
        {
            len2--;
            temp2 = temp2->next;
        }
    }

    while(temp1!=temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1;
};

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

    struct Node* common = intersectionpoint(head1, head2);
    cout << common->data << " ";
        
    return 0;
}