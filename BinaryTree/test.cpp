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

vector<int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    queue<Node*> q;
    stack<int> s;
    q.push(root);
    bool reverse = false;
    while(!q.empty()){
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node* curr = q.front();
            q.pop();

            if(reverse)
                s.push(curr->data);
            else
                ans.push_back(curr->data);

            if(curr->left!=NULL)
                q.push(curr->left);
            
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        if(reverse){
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
        }
        reverse = !reverse;
    }
    return ans;
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if(root==NULL)
        return ans;
    queue<TreeNode*> q;
    stack<int> s;
    q.push(root);
    bool reverse = false;
    while(!q.empty()){
        vector<int> t;
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            TreeNode* curr = q.front();
            q.pop();

            if(reverse)
                s.push(curr->val);
            else
                t.push_back(curr->val);

            if(curr->left!=NULL)
                q.push(curr->left);
            
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        if(reverse){
            while(!s.empty()){
                t.push_back(s.top());
                s.pop();
            }
        }
        reverse = !reverse;
        ans.push_back(t);
        t.clear();
    }
    return ans;
}
int main()
{
    //     10
    //  /      \
    // 20       30
    //   /   \
//  40   60

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    vector<int> ans = zigZagTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}