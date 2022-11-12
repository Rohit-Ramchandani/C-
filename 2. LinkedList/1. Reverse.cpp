#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node (int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node* head;
    LinkedList() { head = NULL;}

    void reverse()
    {
        struct Node* curr = head;
        struct Node* prev = NULL;
        struct Node* next = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void print()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList ls;
    ls.push(10);
    ls.push(20);
    ls.push(30);
    ls.push(40);
    ls.push(50);
    ls.push(60);
    ls.push(70);

    ls.print();
    cout << endl;
    
    ls.reverse();

    ls.print();
    cout << endl;
    return 0;
}

