#include<iostream>
using namespace std;

class LinkedList
{
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

    public:
    struct Node* head;

    LinkedList() {head = NULL;}
    
    void push(int data)
    {
        struct Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }

    void print()
    {
        struct Node* temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void removeDuplicate()
    {
        struct Node* curr = head;
        struct Node* del = head;
        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr->data == curr->next->data)
            {
                del = curr->next;
                curr->next = curr->next->next;
                free(del);
            }
            curr = curr->next;
        }
    }
};

int main()
{
    LinkedList ls;
    ls.push(90);
    ls.push(90);
    ls.push(70);
    ls.push(50);
    ls.push(50);
    ls.push(40);
    ls.push(30);
    ls.push(10);
    ls.push(10);
    
    ls.print();

    ls.removeDuplicate();

    ls.print();
    return 0;
}
