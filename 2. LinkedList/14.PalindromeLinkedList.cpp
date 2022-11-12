#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode* next = NULL;
    ListNode()
    {
        data = 0;
        next = NULL;
    }

    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void push(ListNode* head, int data)
{
    ListNode* temp = new ListNode(data);
    temp -> next = head;
    head = temp;
}

void print(ListNode* head)
{
    ListNode* tmp =  head;
    while(tmp!=NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

ListNode* middle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head)
{
    ListNode* next = NULL;
    ListNode* prev = NULL; 
    
    while(head!=NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head)
{
    if(!head || !head->next) return true;
    
    ListNode* slow;
    ListNode* fast;

    slow = middle(head);
    slow->next = reverseList(slow->next);
        
    fast = head;
    slow = slow -> next;
    //Check for Palindrome
    while(slow!=NULL)
    {
        if(slow->data != fast->data)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main()
{
    ListNode* head1=NULL;
    head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(0);
    cout << isPalindrome(head1);
    return 0;
}

