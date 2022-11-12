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

struct LinkedList
{
    struct Node* head;

    LinkedList(){head = NULL;}

    void print()
    {
        Node* tmp = head;
        while(tmp!=NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void push(int data)
    {
        Node* newnode = new Node(data);
        newnode->next = head;
        head = newnode;
    }

    void reverse()
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = head;

        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
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

    ls.reverse();

    ls.print();
    return 0;
}