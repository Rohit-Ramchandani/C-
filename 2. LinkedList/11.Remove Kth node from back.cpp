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
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void removekth(int data)
    {
        Node* slow = head; 
        Node* fast = head;
        int n = data;
        while(n!=0)
        {
            fast = fast->next;
            n--;
        }

        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        cout << slow->data << " ";
        cout << endl;

        //Remove node
        Node* del = slow->next;
        slow->next = slow->next->next;
        free(del);
    }
};

int main()
{
    LinkedList ls;
    ls.push(90);
    ls.push(80);
    ls.push(70);
    ls.push(60);
    ls.push(50);
    ls.push(40);
    ls.push(30);
    ls.push(20);
    ls.push(10);
    ls.print();
    ls.removekth(5);
    ls.print();
    return 0;
}