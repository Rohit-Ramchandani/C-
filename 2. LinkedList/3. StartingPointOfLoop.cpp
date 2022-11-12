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

struct LinkedList
{
    struct Node* head;
    LinkedList() { head = NULL;}

    void push(int data)
    {
        struct Node* temp = new Node(data);
        temp-> next = head;
        head = temp;
    }

    void print()
    {
        struct Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void x()
    {
        struct Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head->next;
    }

    struct Node* startCycle()
    {
        Node* slow = head;
        Node* fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }

        if(slow == fast)
            fast = head;

        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
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

    ls.print();
    cout << endl;

    ls.x();
    cout << endl;
    cout << ls.startCycle()->data;
    return 0;
}