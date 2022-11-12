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

Node* sumoflist(Node* head1, Node* head2)
{
    Node* tmp2 = new Node(0);
    Node* tmp = tmp2;
    int carry = 0;
    while(head1||head2||carry)
    {
        int sum = carry;

        if(head1)
        {
            sum = sum + head1->data;
            head1 = head1->next;
        }

        if(head2)
        {
            sum = sum + head2->data;
            head2 = head2->next;
        }

        Node* newnode = new Node(sum%10);
        tmp2 -> next = newnode;

        tmp2 = tmp2->next;

        carry = sum/10;
    }
    return tmp->next;
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
    struct Node* head1=NULL;
    head1 = new Node(9);
    head1->next = new Node(9);
    head1->next->next = new Node(9);
    head1->next->next->next = new Node(9);
    head1->next->next->next->next = new Node(9);
    head1->next->next->next->next->next = new Node(9);
    head1->next->next->next->next->next->next = new Node(9);
    
    struct Node* head2;
    head2 = new Node(9);
    head2->next = new Node(9);
    head2->next->next = new Node(9);
    head2->next->next->next = new Node(9);

    print(head1);
    print(head2);

    Node* sum = sumoflist(head1, head2);
    while(sum!=NULL)
    {
        cout << sum->data << " ";
        sum = sum->next;
    }
    return 0;
}

