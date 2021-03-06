// 1. Write a Program to reverse the Linked List. [Iterative]
// 2. Write a Program to reverse the Linked List. [recursive]
// 3. Reverse a Linked List in group of Given Size. [Very Imp]
// 4. Write a program to Detect loop in a linked list. - Using Hashing
// 5. Write a program to Delete loop in a linked list.
// 6. Find the starting point of the loop. 
// 7. Remove Duplicates in a sorted Linked List.
// 8. Remove Duplicates in a Un-sorted Linked List.
// 9. Write a Program to Move the last element to Front in a Linked List.
// 10. Add “1” to a number represented as a Linked List.
// 11. Add two numbers represented by linked lists.
// 12. Intersection of two Sorted Linked List.
// 13. Intersection Point of two Linked Lists.
// 14. Merge Sort For Linked lists.[Very Important]
// 15. Quicksort for Linked Lists.[Very Important]                                          - Not Done
// 16. Find the middle Element of a linked list. - Easy
// 17. Check if a linked list is a circular linked list.
// 18. Split a Circular linked list into two halves.
// 19. Write a Program to check whether the Singly Linked list is a palindrome or not.
// 20. Deletion from a Circular Linked List.                                                - Not Done
// 21. Reverse a Doubly Linked list.
// 22. Find pairs with a given sum in a DLL.
// 23. Count triplets in a sorted DLL whose sum is equal to given value “X”.                - Not Done
// 24. Sort a “k”sorted Doubly Linked list.[Very IMP]
// 25. Rotate Doubly Linked list by N nodes.
// 26. Rotate a Doubly Linked list in group of Given Size.[Very IMP]                        - Not Done
// 27. Flatten a Linked List
// 28. Sort a LL of 0's, 1's and 2's
// 29. Clone a linked list with next and random pointer
// 30. Merge K sorted Linked list
// 31. Multiply two linked lists
// 32. Delete nodes which have a greater value on right side
// 33. Segregate even and odd nodes in a Linked List
// 34. Program for n’th node from the end of a Linked List
// 35. Find the first non-repeating character from a stream of characters

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
    Node *slow_p = head, *fast_p = head;
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
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
    Node *low = head;
    Node *high = head;

    while (low != NULL && high != NULL && high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
        if (low == high)
            break;
    }
    if (low == head)
    {
        while (high->next != low)
        {
            high = high->next;
        }
        high->next = NULL;
    }
    else if (low == high)
    {
        low = head;
        while (low->next != high->next)
        {
            low = low->next;
            high = high->next;
        }
        high->next = NULL;
    }
}
// 6. Find the starting point of the loop. 
Node *startingPointOfLoop(Node *head)
{
    Node *low = head;
    Node *high = head;

    while (low != NULL && high != NULL && high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
        if (low == high)
        {
            break;
        }
    }
    if (low != high)
        return NULL;

    low = head;
    while (low != high)
    {
        low = low->next;
        high = high->next;
    }
    return low;
}
// 7. Remove Duplicates in a sorted Linked List.
Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    if (!curr)
        return NULL;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
// 8. Remove Duplicates in a Un-sorted Linked List.
Node *removeDuplicates(Node *head)
{
    map<int, int> m;
    Node *curr = head;
    m[curr->data] = 1;
    Node *prev = curr;
    curr = curr->next;
    while (curr != NULL)
    {
        if (m[curr->data])
        {
            prev->next = curr->next;
            free(curr);
        }
        else
        {
            m[curr->data] = 1;
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}
// 9. Write a Program to Move the last element to Front in a Linked List.
void moveToFront(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *secLast = NULL;
    Node *last = head;

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = head;
    head = last;
}
// 10. Add “1” to a number represented as a Linked List.
Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    head = reverseList(head);
    bool f = true;
    Node *curr = head;
    while (curr != NULL and f == true)
    {
        if (curr->next == NULL and curr->data == 9)
        {
            curr->data = 1;
            Node *temp = new Node(0);
            temp->next = head;
            head = temp;
            curr = curr->next;
        }
        else if (curr->data == 9)
        {
            curr->data = 0;
            curr = curr->next;
        }
        else
        {
            curr->data = curr->data + 1;
            curr = curr->next;
            f = false;
        }
    }
    head = reverseList(head);
    return head;
}
// 11. Add two numbers represented by linked lists.

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    first = reverseList(first);
    second = reverseList(second);

    int carry = 0, sum = 0;
    Node *temp;
    Node *res = NULL;
    Node *curr = NULL;

    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = new Node(sum);
        if (res == NULL)
            res = temp;
        else
            curr->next = temp;
        curr = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
    {
        temp = new Node(carry);
        curr->next = temp;
        curr = temp;
    }
    res = reverseList(res);
    return res;
}
// 12. Intersection of two Sorted Linked List.
Node *findIntersection(Node *head1, Node *head2)
{
    // Your Code Here
    Node *curr1 = head1;
    Node *curr2 = head2;

    Node *ans = NULL;
    Node *curr;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data == curr2->data)
        {
            if (ans == NULL)
            {
                ans = new Node(curr1->data);
                curr = ans;
            }
            else
            {
                curr->next = new Node(curr1->data);
                curr = curr->next;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else
        {
            if (curr1->data < curr2->data)
            {
                curr1 = curr1->next;
            }
            else
            {
                curr2 = curr2->next;
            }
        }
    }
    return ans;
}
// 13. Intersection Point of two Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;

    int c1 = 0, c2 = 0;
    while (ptr1)
    {
        c1++;
        ptr1 = ptr1->next;
    }
    while (ptr2)
    {
        c2++;
        ptr2 = ptr2->next;
    }
    ptr1 = head1;
    ptr2 = head2;
    int dif = abs(c1 - c2);
    if (c1 > c2)
    {
        for (int i = 0; i < dif; i++)
        {
            ptr1 = ptr1->next;
        }
    }
    else if (c2 > c1)
    {
        for (int i = 0; i < dif; i++)
        {
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (ptr1)
        return ptr1->data;
    return -1;
}

// 14. Merge Sort For Linked lists.[Very Important]
/*
void MergeSorting(Node** head){
    Node* curr = *head;
    Node* first;
    Node* second;

    if(!curr or !curr->next) return;

    FindMiddle(curr, &first, &second);

    MergeSorting(&first);
    MergeSorting(&second);

    *head = MergeBoth(first, second);
}
Node* MergeBoth(Node* first, Node* second){
    Node* answer = NULL;

    if(!first)
        return second;
    else if(!second)
        return first;

    if(first->data<=second->data){
        answer = first;
        answer->next = MergeBoth(first->next, second);
    }else{
        answer = second;
        answer->next = MergeBoth(first, second->next);
    }
    return answer;
}
void FindMiddle(Node* curr, Node** first, Node** second){
    Node* fast;
    Node* slow;
    slow = curr;
    fast = curr->next;

    while (fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *first = curr;
    *second = slow->next;
    slow->next = NULL;
}
Node *mergeSort(Node* head)
{
    MergeSorting(&head);
    return head;
}

*/

// 17. Check if a linked list is a circular linked list.
bool isCircular(Node *head)
{
    // Your code here
    if (head == NULL)
        return true;

    bool flag = false;
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
        if (curr->next == head)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

// 18. Split a Circular linked list into two halves.
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here

    Node *slow = head;
    Node *fast = head->next;

    while (fast != head && (fast->next) != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = head;
    Node *curr = *head2_ref;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = *head2_ref;
}

// 19. Write a Program to check whether the Singly Linked list is a palindrome or not.
/*

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

        while (head2!=NULL)
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

*/

// 21. Reverse a Doubly Linked list.

/*
Node* reverseDLL(Node * head)
{
    //Your code here
  Node* ptr1 = head;
  Node* ptr2 = ptr1->next;

  ptr1->next = NULL;
  ptr1->prev = ptr2;

  while(ptr2!=NULL){
      ptr2->prev = ptr2->next;
      ptr2->next = ptr1;
      ptr1 = ptr2;
      ptr2 = ptr2->prev;
  }

  head = ptr1;
  return head;
}
*/

// 22. Find pairs with a given sum in a DLL.
/*
void pairSum(Node* head, int val){
    Node* first = head;
    Node* second = head;

    while (second->next!=NULL)
    {
        second = second->next;
    }
    bool found = false;
    while (first!=second && second->next!=first)
    {
        if((first->data+second->data)==val){
            found = true;
            cout<<"("<<first->data<<" "<<second->data<<")"<<endl;
            first = first->next;
            second = second->prev;
        }else{
            if ((first->data + second->data) < val)
                first = first->next;
            else
                second = second->prev;
        }
    }
    if(!found)
        cout<<"No pair found"<<endl;
}
*/

// 24. Sort a “k”sorted Doubly Linked list.[Very IMP]

/*
struct compare {
    bool operator() (struct Node* first, struct Node* second){
        return first->data > second->data;
    }
};

struct Node* sort_K_LL(struct Node* head, int k){
    if(head==NULL){
        return head;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    struct Node* newHead = NULL, *curr;

    for (int i = 0; i <= k && head!=NULL; i++)
    {
        pq.push(head);
        head = head->next;
    }

    while (!pq.empty())
    {
        if(newHead==NULL){
            newHead = pq.top();
            newHead->prev = NULL;
            curr = newHead;
        }else{
            curr->next = pq.top();
            pq.top()->prev = curr;
            curr = pq.top();
        }
        pq.pop();
        if(head!=NULL){
            pq.push(head);
            head = head->next;
        }
    }
    curr->next = NULL;
    return newHead;
}
*/

// 25. Rotate DoublyLinked list by N nodes.

/*
Node *update(Node *start, int p)
{
    // Add your code here
    if(p==0)
        return start;

    Node* curr = start;
    int count = 1;
    while (count<p && curr!=NULL)
    {
        curr = curr -> next;
        count++;
    }
    Node* nthNode = curr;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
     curr->next = start;
     start->prev = curr;

     start = nthNode->next;
     start->prev = NULL;
    nthNode->next = NULL;

    return start;
}
*/

// 27. Flatten a Linked List

/*
Node* merge(Node* a, Node* b){
    if(a==NULL) return b;
    if(b==NULL) return a;

    Node* result;
    if(a->data<b->data){
        result = a;
        result->bottom = merge(a->bottom, b);
    }else{
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}
Node *flatten(Node *root)
{
   // Your code here
    if(root==NULL or root->next==NULL)
        return root;
    return merge(root, flatten(root->next));
}

*/

// 28. Sort a LL of 0's, 1's and 2's

/*
class Solution
{
    void insertAtTail(Node* &tail, Node* curr){
        tail->next = curr;
        tail = curr;
    }
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;

        Node* curr = head;
        while (curr!=NULL)
        {
            int val = curr->data;

            if(val==0){
                insertAtTail(zeroTail, curr);
            }else if(val==1){
                insertAtTail(oneTail, curr);
            }else if(val==2){
                insertAtTail(twoTail, curr);
            }
            curr = curr->next;
        }
        // merge two LL
        if(oneHead->next!=NULL){
            zeroTail->next = oneHead->next;
        }else{
            zeroTail->next = twoHead->next;
        }
        oneTail->next = twoHead->next;
        twoTail->next = NULL;

        head = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
};
*/

// 29. Clone a linked list with next and random pointer

/*
class Solution
{
    private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode!=NULL && cloneNode!=NULL)
        {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

         temp = head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                    temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
            }

                temp = temp->next->next;
        }

        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode!=NULL && cloneNode!=NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            if(originalNode!=NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        return cloneHead;

    }

};
*/

// 30. Merge K sorted Linked list

Node *sMerge(Node *a, Node *b)
{
    Node *result;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->data <= b->data)
    {
        result = a;
        result->next = sMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sMerge(a, b->next);
    }
    return result;
}
Node *mergeKLists(Node *arr[], int K)
{
    // Your code here
    int i = 0;
    int last = K - 1;
    int j;
    while (last != 0)
    {
        i = 0;
        j = last;
        while (i < j)
        {
            arr[i] = sMerge(arr[i], arr[j]);
            i++;
            j--;
            if (i >= j)
            {
                last = j;
            }
        }
    }
    return arr[0];
}

// 31. Multiply two linked lists

long long multiplyTwoLists(Node *l1, Node *l2)
{
    // Your code here
    long long num1 = 0;
    long long num2 = 0;
    while (l1 != nullptr)
    {
        num1 = (num1 * 10 + l1->data) % 1000000007;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        num2 = (num2 * 10 + l2->data) % 1000000007;
        l2 = l2->next;
    }
    return (num1 * num2) % 1000000007;
}

// 32. Delete nodes which have a greater value on right side

Node *compute(Node *head)
{
    head = reverseList(head);
    Node *curr = head;
    int max_so_far = head->data;
    Node *prev = head;
    head = head->next;
    while (head)
    {
        if (head->data >= max_so_far)
        {
            max_so_far = head->data;
            prev = head;
            head = head->next;
        }
        else
        {
            prev->next = head->next;
            head = prev->next;
        }
    }
    head = reverseList(curr);
    return head;
}

// 33. Segregate even and odd nodes in a Linked List

Node *divide(int N, Node *head)
{
    // code here
    Node *eS = NULL, *eE = NULL, *oS = NULL, *oE = NULL;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        int val = curr->data;
        if (val % 2 == 0)
        {
            if (eS == NULL)
            {
                eS = curr;
                eE = eS;
            }
            else
            {
                eE->next = curr;
                eE = eE->next;
            }
        }
        else
        {
            if (oS == NULL)
            {
                oS = curr;
                oE = oS;
            }
            else
            {
                oE->next = curr;
                oE = oE->next;
            }
        }
    }
    if (oS == NULL || eS == NULL)
    {
        return head;
    }
    eE->next = oS;
    oE->next = NULL;
    return eS;
}

// 34. Program for n’th node from the end of a Linked List

// approach - 1:
int getNthFromLast_1(Node *head, int n)
{
    // Your code here
    head = reverseList(head);
    while (n-- != 1 && head != NULL)
    {
        head = head->next;
    }
    if (head == NULL)
    {
        return -1;
    }
    return head->data;
}

// approach - 2:
int getNthFromLast_2(Node *head, int n)
{
    // Your code here
    if (head == NULL)
        return -1;

    Node *first = head;
    for (int i = 0; i < n; i++)
    {
        if (first == NULL)
            return -1;
        first = first->next;
    }
    Node *second = head;
    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    return second->data;
}

// 35. Find the first non-repeating character from a stream of characters

string FirstNonRepeating(string A)
{
    vector<int> vis(26, 0);
    string ans = "";
    vector<char> v;
    int n = A.length();
    for (int i = 0; i < n; i++)
    {
        if(!vis[A[i]-'a']){
            v.push_back(A[i]);
        }
        vis[A[i]-'a']++;
        int f = 0;
        int m = v.size();
        for (int j = 0; j < m; j++)
        {
            if(vis[v[j]-'a']==1){
                ans.push_back(v[j]);
                f = 1;
                break;
            }
        }
        if(f==0){
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    return 0;
}