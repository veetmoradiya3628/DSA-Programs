#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector<int> solve_longPath(Node* root){
    if(!root) return {0, 0};
    vector<int> a = solve_longPath(root->left);
    vector<int> b = solve_longPath(root->right);
    if(a[0]>b[0]) return {a[0]+1, a[1]+root->data};
    
}
int sumOfLongRootToLeafPath(Node *root)
{
    //code here
}
int main()
{
    //     10
    //  /      \
    // 20       30
    //   /   \
//  40   60
    // Node *root = new Node(1);
    //     root->left = new Node(2);
    //     root->left->left = new Node(4);
    //     root->left->right = new Node(5);
    //     root->right = new Node(3);
    //     root->right->right = new Node(2);
    //     root->right->right->left = new Node(4);
    //     root->right->right->right = new Node(5);

    return 0;
}