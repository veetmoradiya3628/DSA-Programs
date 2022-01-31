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

int sum = 0;
int sumEvenGrandparent(TreeNode* root) {
    if(root==NULL){
        return 0;
    }
    if(root->val%2==0){
        sum+=sumEvenGrandparent(root->left->left)+sumEvenGrandparent(root->left->right)
            +sumEvenGrandparent(root->right->left)+sumEvenGrandparent(root->right->right);
    }
    return sum;
}
int main()
{
}