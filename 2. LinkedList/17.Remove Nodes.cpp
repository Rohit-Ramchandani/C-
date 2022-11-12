#include<iostream>
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
    Node* head;

    LinkedList(){head = NULL;}

    Node* push(int data)
    {
        Node* temp = new Node(data);
        if(head == NULL)
            head = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        return head;
    }

    void print()
    {
        Node* temp = head;
        while(temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* removeElements(int val)
    {
        if(!head) return NULL;
        
        Node* temp = new Node(-1);
        Node* ans = temp;
        temp->next = head;
        
        while(temp->next->data != val)
        {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete(del);
            temp =  temp->next;
        }
        return head = temp->next;
    }
};

int main()
{
    LinkedList ls;
    ls.push(6);
    ls.push(5);
    ls.push(4);
    ls.push(6);
    ls.push(2);
    ls.push(1);
    ls.print();
    ls.removeElements(1);
    ls.print();
    return 0;
}