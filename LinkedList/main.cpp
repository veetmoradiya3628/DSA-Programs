// 1. Write a Program to reverse the Linked List. [Iterative]
// 2. Write a Program to reverse the Linked List. [recursive]
// 3. Reverse a Linked List in group of Given Size. [Very Imp]
// 4. Write a program to Detect loop in a linked list. - Using Hashing
// 5. Write a program to Delete loop in a linked list.
// 6. Find the starting point of the loop. 
// 7. Remove Duplicates in a sorted Linked List.
// 8. Remove Duplicates in a Un-sorted Linked List.
// 9. Write a Program to Move the last element to Front in a Linked List.
// 10. 
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
// 1. Write a Program to reverse the Linked List. [Iterative]
struct Node *reverseList(struct Node *head)
{
    // code here
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// 2. Write a Program to reverse the Linked List. [recursive]
struct Node *_reverse(struct Node *head)
{
    // code here
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = _reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
// 3.Reverse a Linked List in group of Given Size. [Very Imp]
struct Node *reverse(struct Node *head, int k)
{
    if (!head)
        return NULL;

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverse(next, k);
    }
    return prev;
}
// 4.1 Write a program to Detect loop in a linked list. - Using Hashing
bool detectLoop_Hashing(struct Node *h)
{
    unordered_set<Node *> s;
    while (h != NULL)
    {
        if (s.find(h) != s.end())
            return true;
        s.insert(h);

        h = h->next;
    }
    return false;
}
// 4.2 Detect a Loop - Floyd’s Cycle-Finding Algorithm
bool detectLoop(Node *head)
{
    Node* slow_p = head, *fast_p = head;
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if(slow_p==fast_p)
        {
            return 1;
        }
    }
    return 0;
}
// 5. Write a program to Delete loop in a linked list.
void removeLoop(Node *head)
{
    // code here
    Node* low = head;
    Node* high = head;

    while(low!=NULL && high!=NULL && high->next!=NULL){
        low = low->next;
        high = high->next->next;
        if(low==high)
            break;
    }
    if(low==head){
        while(high->next!=low){
            high = high->next;
        }
        high->next = NULL;
    }else if(low==high){
        low = head;
        while(low->next!=high->next){
            low = low->next;
            high = high->next;
        }
        high->next = NULL;
    }
}
// 6. Find the starting point of the loop. 
Node* startingPointOfLoop(Node* head){
    Node* low = head;
    Node* high = head;
    
    while (low!=NULL && high!=NULL && high->next!=NULL)
    {
        low = low->next;
        high = high->next->next;
        if(low==high){
            break;
        }
    }
    if(low!=high) return NULL;

    low = head;
    while (low!=high)
    {
        low = low->next;
        high = high->next;
    }
    return low;
}
// 7. Remove Duplicates in a sorted Linked List.
Node *removeDuplicates(Node *head)
{
    Node* curr = head;
    if(!curr) return NULL;
    while (curr->next!=NULL)
    {
        if(curr->data==curr->next->data){
            curr->next = curr->next->next;
        }else{
            curr = curr->next;
        }
    }
    return head;
}
// 8. Remove Duplicates in a Un-sorted Linked List.
Node *removeDuplicates(Node *head)
{
    map<int, int> m;
    Node* curr = head;
    m[curr->data] = 1;
    Node* prev = curr;
    curr = curr->next;
    while (curr!=NULL)
    {
        if(m[curr->data]){
            prev->next = curr->next;
            free(curr);
        }else{
            m[curr->data] = 1;
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}
// 9. Write a Program to Move the last element to Front in a Linked List.
void moveToFront(Node* head){
    if(head==NULL ||| head->next==NULL)
        return;
    
    Node* secLast = NULL;
    Node* last = head;

    while (last->next!=NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = head;
    head = last;
}
int main()
{
    return 0;
}