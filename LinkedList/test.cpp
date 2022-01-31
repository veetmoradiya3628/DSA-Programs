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