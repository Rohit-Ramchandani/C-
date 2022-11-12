#include<bits/stdc++.h>
using namespace std;

class Stack
{
    private:
    int data;
    int tos;
    int stack[100];

    public:
    Stack()
    {
        this->tos = -1;
    }

    void pop()
    {
        if(tos == -1)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        else
        {
            cout << "Element deleted is " << stack[tos] << endl;
            tos--;
        }
    }

    void push(int data)
    {
        if(tos == sizeof(stack)/sizeof(int) - 1)
        {
            cout << "Stack is Full" << endl;
            return;
        }
        else
        {
            tos++;
            stack[tos] = data;
            return;
        }
    }

    void traverse()
    {
        for(int i=tos; i>=0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.traverse();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.traverse();
    return 0;
}