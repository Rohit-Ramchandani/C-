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

    Node* swapPairs() 
    {
        if(!head || !head->next) return head;
        
        Node* temp = new Node(-1);
        temp -> next = head;
        
        Node* prev = temp;
        Node* curr = head;
        
        while(curr && curr->next)
        {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            curr = curr->next;
            prev = prev->next->next;            
        }
        return head = temp->next;
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
    ls.swapPairs();
    ls.print();
    return 0;
}