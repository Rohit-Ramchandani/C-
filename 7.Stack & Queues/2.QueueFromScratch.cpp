#include<bits/stdc++.h>
using namespace std;

class Queue
{
    private:
    int front;
    int rear;
    int queue[100];

    public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        if(rear == (sizeof(queue)/sizeof(int)) - 1 )
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            rear++;
            queue[rear] = data;
        }
    }

    void dequeue()
    {
        if(front == rear)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "Element deleted is " << queue[front] << endl;
            front++;
        }
    }

    void traverse()
    {
        for(int i=front; i<=rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue qe;
    qe.push(10);
    qe.push(11);
    qe.push(12);
    qe.push(13);
    qe.push(14);
    qe.push(15);
    qe.push(16);
    qe.traverse();
    qe.dequeue();
    qe.traverse();
    return 0;
}