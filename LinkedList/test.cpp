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
// add Node at Beginning - Time : O(1), Space : O(1)
Node *addNodeatHead(Node *head, int data)
{
    if (head == NULL)
    {
        return new Node(data);
    }
    Node *new_node = new Node(data);
    new_node->next = head;
    return new_node;
}
// add Node at the end of Linked List : Time : O(n), Space : O(1)
Node *addNodeAtLast(Node *head, int data)
{
    if (head == NULL)
    {
        return new Node(data);
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new Node(data);
    }
    return head;
}
// traverse a Linked List
void Traverse(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
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
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node* slow = head;
    Node* fast = head->next;

    while (fast!=head && (fast->next)!=head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = head;
    Node* curr = *head2_ref;
    while (curr->next!=head)
    {
        curr = curr->next;
    }
    curr->next = *head2_ref;
}

// Check for palindrome
class Solution{
private:
    Node* getMiddle(Node* head){
        Node* slow = head;
        Node* fast = head->next;

        while (fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next == NULL){
            return true;
        }

        //  step - 1: get middle element
        Node* middle = getMiddle(head);

        // step - 2 : reverse list after Middle
        Node* temp = middle->next;
        middle->next = reverse(temp);

        // step - 3: Compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;
        while (head2->next!=NULL)
        {
            if(head1->data!= head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        // step 4: repeat step - 2
        temp = middle->next;
        middle->next = reverse(temp);

        return true;
    }
};

int main()
{
    // Node* head = new Node(10);
    // head = addNodeatHead(head, 30);
    // head = addNodeatHead(head, 20);
    Node *head = addNodeatHead(NULL, 10);
    head = addNodeatHead(head, 20);
    head = addNodeAtLast(head, 5);
    head = addNodeAtLast(head, 25);
    head = addNodeatHead(head, 30);
    Traverse(head);
    return 0;
}