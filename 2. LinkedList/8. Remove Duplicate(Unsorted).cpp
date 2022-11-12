#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next = NULL;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
    struct Node* head;
    public:
    LinkedList();
    void removeDuplicate();
    void push(int data);
    void print();
};

LinkedList::LinkedList()
{
    head = NULL;
}

void LinkedList::push(int data)
{
    struct Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void LinkedList::print()
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void LinkedList::removeDuplicate()
{
    struct Node* first = head;
    struct Node* last;
    struct Node* temp;
    while(first!=NULL && first->next!=NULL)
    {
        last = first;
        while(last != NULL)
        {
            if(last->data == first->data)
            {
                struct Node* x = last->next;
                last->next = last->next->next;
                free(x);
            }
            else
                last = last -> next;
        }
        first = first ->next;
    }
}

int main()
{
    LinkedList ls;
    ls.push(80);
    ls.push(20);
    ls.push(60);
    ls.push(30);
    ls.push(10);
    ls.push(30);
    ls.push(20);
    ls.push(10);

    ls.print();

    ls.removeDuplicate();   

    ls.print();
}