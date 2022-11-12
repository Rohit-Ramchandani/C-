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
    struct Node* head;
    LinkedList() {head  = NULL;}

    void push(int data)
    {
        struct Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void print()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void middle()
    {
        Node* slow = head;
        Node* fast = head;
        while(fast->next !=NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data;
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
    ls.push(80);
    //ls.push(90);

    ls.print();
    ls.middle();
}
