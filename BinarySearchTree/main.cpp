/*
1. Find a value in a BST
2. Deletion of a node in a BST
3. Find min and max value in a BST
4. Find inorder successor and inorder predecessor in a BST
5. Check if a tree is a BST or not
6. Populate Inorder successor of all nodes
7. Find LCA  of 2 nodes in a BST
8. Construct BST from preorder traversal
9. Convert Binary tree into BST 
10. Sorted Array to BST Conversion - Extra One
11. Convert a normal BST into a Balanced BST
12. Merge two BST [ V.V.V>IMP ]
13. Find Kth largest element in a BST
14. Find Kth smallest element in a BST
15. Count pairs from 2 BST whose sum is equal to given value "X"
16. Find the median of BST in O(n) time and O(1) space
17. Count BST ndoes that lie in a given range
18. Replace every element with the least greater element on its right 
19. Not Attampted - Given "n" appointments, find the conflicting appointments
20. Not Attampted - Check preorder is valid or not
21. Check whether BST contains Dead end
22. Largest BST in a Binary Tree [ V.V.V.V.V IMP ]
23. Flatten BST to sorted list

*/

#include <bits/stdc++.h>
using namespace std;
// For Leetcode
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// for Gfg
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *next;
    Node(int x)
    {
        key = x;
        left = next = right = NULL;
    }
};
// Function to search a node in BST.
bool search(Node *root, int x)
{
    // Your code here
    if (!root)
        return 0;

    if (root->key == x)
        return 1;
    else if (root->key > x)
    {
        return search(root->left, x);
    }
    else if (root->key < x)
    {
        return search(root->right, x);
    }
}
// Deletion of a node in a BST
TreeNode *findLastRight(TreeNode *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findLastRight(root->right);
}
TreeNode *delete_helper(TreeNode *root)
{
    if (root->left == NULL)
        return root->right;
    else if (root->right == NULL)
        return root->left;
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->val == key)
        return delete_helper(root);
    TreeNode *dummy = root;
    while (root != NULL)
    {
        if (root->val > key)
        {
            if (root->left != NULL && root->left->val == key)
            {
                root->left = delete_helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->val == key)
            {
                root->right = delete_helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}
// Find min and max value in a BST - for max we can go to right side
int minValue(Node *root)
{
    // Code here
    Node *curr = root;
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return (curr->key);
}

// Find inorder successor and inorder predecessor in a BST
Node *inpre(Node *root)
{
    Node *p = root->left;
    while (p->right)
        p = p->right;
    return p;
}
Node *insuc(Node *root)
{
    Node *p = root->right;
    while (p->left)
    {
        p = p->left;
    }
    return p;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (!root)
        return;
    if (root->key == key)
    {
        if (root->left)
            pre = inpre(root);
        if (root->right)
            suc = insuc(root);
        return;
    }
    if (key > root->key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else if (key < root->key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}
// Function to check whether a Binary Tree is BST or not.
bool isBSTRec(Node *root, int min, int max)
{
    if (!root)
        return true;
    return (root->key > min && root->key < max &&
            isBSTRec(root->left, min, root->key) &&
            isBSTRec(root->right, root->key, max));
}
bool isBST(Node *root)
{
    return isBSTRec(root, INT_MIN, INT_MAX);
}
// Populate Inorder successor of all nodes
vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> res;
    stack<TreeNode *> s1, s2;

    while (root1 || root2 || !s1.empty() || !s2.empty())
    {
        while (root1 != NULL)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2 != NULL)
        {
            s2.push(root2);
            root2 = root2->left;
        }
        if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val))
        {
            root1 = s1.top();
            s1.pop();
            res.push_back(root1->val);
            root1 = root1->right;
        }
        else
        {
            root2 = s2.top();
            s2.pop();
            res.push_back(root2->val);
            root2 = root2->right;
        }
    }
    return res;
}
// Populate Inorder successor of all nodes
void solve(Node *root, Node *&prev)
{
    if (!root)
        return;

    solve(root->left, prev);
    if (prev != NULL)
    {
        prev->next = root;
    }
    prev = root;
    solve(root->right, prev);
}
void populateNext(Node *root)
{
    // code here
    Node *prev = NULL;
    solve(root, prev);
}
// Find LCA  of 2 nodes in a BST
Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->key == n1 || root->key == n2)
        return root;

    Node *lca1 = LCA(root->left, n1, n2);
    Node *lca2 = LCA(root->right, n1, n2);

    if (lca1 != NULL && lca2 != NULL)
        return root;

    if (lca1 != NULL)
        return lca1;
    else
        return lca2;
} 
//  Construct BST from preorder Traversal
Node* constructTreeUtil(int pre[],int* index, int key, int min, int max, int size){
    if(*index>=size)
        return NULL;

    Node* root = NULL;
    if(key>min && key<max){
        root = new Node(key);
        *index = *index+1;
        if(*index<size){
            root->left = constructTreeUtil(pre, index, pre[*index], min, key, size);
        }
        if(*index<size){
            root->right = constructTreeUtil(pre, index, pre[*index], key, max, size);
        }
    }
    return root;
}
Node* constructTree(int pre[], int size){
    int index = 0;
    return constructTreeUtil(pre, &index, pre[0], INT_MIN, INT_MAX, size);
}
// Convert Binary tree into BST 
void inorder_tree(Node* root, vector<int> &v){
    if(!root) return;
    inorder_tree(root->left, v);
    v.push_back(root->key);
    inorder_tree(root->right, v);
}
void inorder_bst(Node* root, vector<int> v, int &i){
    if(!root) return;
    inorder_bst(root->left, v,i);
    root->key = v[i];
    i++;
    inorder_bst(root->right, v,i);
}
Node *binaryTreeToBST(Node *root)
{
    vector<int> v;
    inorder_tree(root, v);    
    sort(v.begin(), v.end());
    int i = 0;
    inorder_bst(root, v, i);
    return root;
}
// Convert Sorted Array to BST
Node* sortedArrayToBSTRec(vector<int>& arr, int start, int end){
    if(start>end)
        return NULL;
    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToBSTRec(arr, start, mid-1);
    root->right = sortedArrayToBSTRec(arr, mid+1, end);
    return root;
}
Node* sortedArrayToBST(vector<int> &nums)
{
    Node* root = sortedArrayToBSTRec(nums, 0, nums.size()-1);
    return root;
}
// Convert a normal BST into a Balanced BST
void inorder(Node* root, vector<int>& ans){
    if(root==NULL) 
        return;
    inorder(root->left, ans);
    ans.push_back(root->key);
    inorder(root->right, ans);
}
Node* buildBalancedTree(Node* root)
{
    vector<int> ino;
    inorder(root, ino);
    return sortedArrayToBST(ino);
}
// Merge two BST [ V.V.V>IMP ]

/*
1. Get the inorder traversals of both trees
2. both traversals will be sorted so merge them into one array
3. now convert this sorted merged array into BST so resultant BST will be Balanced BST
*/

// Find Kth largest element in a BST 
int ans;
void kthLargestUtil(Node* root, int k, int& idx){
    if(!root) return;
    kthLargestUtil(root->right, k, idx);
    if(k==idx){
        ans = root->key;
        idx++;
        return;
    }
    else idx++;
    kthLargestUtil(root->left, k, idx);
}
int kthLargest(Node *root, int K)
{
    int idx = 1;
    ans = -1;
    kthLargestUtil(root, K, idx);
    return ans;    
}

// Find Kth smallest element in a BST
void kthSmallestUtil(Node* root, int k, int& idx){
    if(!root) return;
    kthSmallestUtil(root->left, k, idx);
    if(k==idx){
        ans = root->key;
        idx++;
        return;
    }
    else idx++;
    kthSmallestUtil(root->right, k, idx);
}
int kthSmallest(Node *root, int K)
{
    int idx = 1;
    ans = -1;
    kthSmallestUtil(root, K, idx);
    return ans;    
}

// Count pairs from 2 BST whose sum is equal to given value "X" 

/*
int c;
bool fetch(Node* root2, int k){
    if(!root2) return false;
    if(k==root2->key) return true;
    bool x, y;
    x = false;
    y = false;
    if(k<root2->key) x = fetch(root2->left, k);
    else if(k>root2->key) y = fetch(root2->right, k);
    return x or y;
}
void solve(Node* root1, Node* root2, int k){
    if(!root1) return;
    solve(root1->left, root2, k);
    if(fetch(root2, k-root1->key)) c++;
    solve(root1->right, root2, k);
}
int countPairs(Node *root1, Node *root2, int x)
{
    c = 0;
    solve(root1, root2, x);
    return c;
}
*/

// Find the median of BST in O(n) time and O(1) space

/*

void count_nodes(Node* root,int &c){
    if(!root) return;
    count_nodes(root->left,c);
    c++;
    count_nodes(root->right,c);
}

void func(Node* root,Node* &cur,Node* &prev,int &c,int k,int &f){
    if(!root) return;
    func(root->left,cur,prev,c,k,f);
    if(prev==NULL){
        prev = root;
        c++;
    }
    else if(c==k){
        c++;
        cur = root;
        f = 1;
        return;
    }
    else if(f==0){
        c++;
        prev = root;
    }
    func(root->right,cur,prev,c,k,f);
}

float findMedian(struct Node *root)
{
      //Code here
      int n = 0;
      count_nodes(root,n);
      Node* cur = NULL;
      Node* prev = NULL;
      int c = 1;
      int x = (n/2)+1;
      int f = 0;
      func(root,cur,prev,c,x,f);
      if(n&1){
          float ans = (cur->key)*1.0;
          return ans;
      }
      else {
          float ans = ((cur->key+prev->key)*1.0)/(2*1.0);
          return ans;
      }
}
*/

// Count BST ndoes that lie in a given range

/*
void inorder(Node* root, int& cnt, int l, int h){
    if(!root) return;
    inorder(root->left, cnt, l, h);
    if(root->data>=l && root->data<=h)
        cnt++;
    inorder(root->right, cnt, l, h);
}
int getCount(Node *root, int l, int h)
{
  int count = 0;
  inorder(root, count, l, h);
  return count;
}
*/

// Replace every element with the least greater element on its right

/*
Node* insert(Node* node, int data, Node*& succ){
    if(node==NULL)
        return node = new Node(data);
    if(data<node->key){
        succ = node;
        node->left = insert(node->left, data, succ);
    }else if(data>node->key){
        node->right = insert(node->right, data, succ);
    }
    return node;
}
void replace(int arr[], int n){
    Node* root = NULL;
    for (int i = n-1; i >= 0; i--)
    {
        Node* succ = NULL;
        root = insert(root, arr[i], succ);
        if(succ){
            arr[i] = succ->key;
        }else{
            arr[i] = -1;
        }
    }
}
*/

// Check whether BST contains Dead end 

/*
bool solve(Node* root, int min, int max){
    if(!root) return false;
    if(min==max) return true;
    return solve(root->left, min, root->key-1) or solve(root->right, root->key+1, max);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    return solve(root, 1, INT_MAX);
}
*/

// Largest BST in a Binary Tree [ V.V.V.V.V IMP ]

/*
class NodeValue
{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
class Solution
{
public:
    // Return the size of the largest sub-tree which is also a BST
    NodeValue largestBSTHelper(Node* root){
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = largestBSTHelper(root->left);
        auto right = largestBSTHelper(root->right);

        if(left.maxNode < root->key && root->key < right.minNode){
            return NodeValue(min(root->key, left.minNode), max(root->key, right.maxNode), left.maxSize+right.maxSize+1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    int largestBst(Node *root)
    {
        return largestBSTHelper(root).maxSize;
    }
};
*/

// Flatten BST to sorted list

/*
void inorder(Node* curr, Node*& prev){
    if(curr==NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

Node* flatten(Node* parent){
    Node* dummy = new Node(-1);
    Node* prev = NULL;

    inorder(parent, prev);

    prev->left = NULL;
    prev->right = NULL;
    Node* ret = dummy->right;
    return ret;
}
*/
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    return 0;
}
