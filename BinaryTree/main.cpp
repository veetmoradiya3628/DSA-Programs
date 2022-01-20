/*
1. print the Level order traversal
2. print the reverse level order traversal
3. Find the Height of Binary Tree
4. Find the Diameter of Binary Tree
5. Mirror of a tree 
    A_1 : Create new Tree and pass it's reference as function argument and create node with vice versa child
    A-2 : Swap the left and right links of each node and if null found the nothing to do
6. iterative inorder
7. iterative pre-order
8. iterative post-order
*/


#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution
{
    public:
 //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
        vector<int> ans;
        ans.push_back(node->data);
        queue<Node*> que;
        if(node->left!=NULL){
      	    que.push(node->left);
        }
        if(node->right!=NULL){
      	    que.push(node->right);
        }
        while(!que.empty()){
      	    Node* temp = que.front();
      	    que.pop();
      	    ans.push_back(temp->data);
	        if(temp->left!=NULL){
	      	    que.push(temp->left);
	        }
	        if(temp->right!=NULL){
	      	    que.push(temp->right);
	        }
        }
      return ans;
    }
      // Reverse Level Order Traversal
    vector<int> reverseLevelOrder(Node *node)
    {
        // code here
        vector<int> ans;
        ans.push_back(node->data);
        queue<Node*> que;
        if(node->right!=NULL){
            que.push(node->right);
        }
        if(node->left!=NULL){
            que.push(node->left);
        }
        while(!que.empty()){
            Node* temp = que.front();
            que.pop();
            ans.push_back(temp->data);
            if(temp->right!=NULL){
                que.push(temp->right);
            }
            if(temp->left!=NULL){
                que.push(temp->left);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    //Function to find the height of a binary tree.
    int tree_height(struct Node* node){
        // code here 
        if(node==NULL)
            return 0;
        else 
            return 1 + max(tree_height(node->left), tree_height(node->right));
    }

     // Function to return the diameter of a Binary Tree.
    int res = 0;
    int height(Node* root){
    	if (root==NULL)
    	{
    		return 0;
    	}
    	int lh = height(root->left);
    	int rh = height(root->right);
    	res = max(res, 1+lh+rh);
    	return 1+max(lh, rh);
    }
    int diameter(Node* root) {
    	height(root);
    	return res;
    }

    // Mirror of a Tree
    Node* mirrorTree(Node* root){
        if(root==NULL){
            return root;
        }
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        if(root->left)
            mirrorTree(root->left);
        if(root->right)
            mirrorTree(root->right);
        return root;
    }

    // iterative Inorder traversal of tree 
    void print_inorder_iterative(Node* root){
        cout<<"Inorder : ";
        stack<Node*> stk;
        Node* curr = root;
        while (!stk.empty() || curr!=NULL){
            if(curr!=NULL){
                stk.push(curr);
                curr = curr->left;
            }else{
                curr = stk.top();
                stk.pop();
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
        cout<<endl;
    }
    // iterative pre-order traversal of tree 
    void print_preorder_iterative(Node* root){
        cout<<"Pre-Order : ";
        if(root==NULL)
            return;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty())
        {
            Node* curr = stk.top();
            stk.pop();
            cout<<curr->data<<" ";
            if(curr->right!=nullptr)
                stk.push(curr->right);
            if(curr->left!=nullptr)
                stk.push(curr->left);
        }
        cout<<endl;
    }
    // iterative post-order traversal of tree 
    void print_post_iterative(Node* root){
        cout<<"Post-Order : ";
        if(root==NULL)
            return;
        stack<Node*> stk;
        stack<int> ans;
        stk.push(root);
        while (!stk.empty())
        {
            Node* curr = stk.top();
            stk.pop();
            ans.push(curr->data);
            if(curr->left!=nullptr)
                stk.push(curr->left);
            if(curr->right!=nullptr)
                stk.push(curr->right);
        }
        while(!ans.empty()){
            cout<<ans.top()<<" ";
            ans.pop();
        }
        cout<<endl;
    }
};
int main()
{
    //     10
    //  /      \
    // 20       30
//   /   \
//  40   60

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    Solution s1;
    return 0;
}