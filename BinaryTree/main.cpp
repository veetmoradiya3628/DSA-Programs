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
--------------------------------------------
9. Left View of a tree
10. Right View of Tree
11. Top View of a tree
12. Bottom View of a tree
13. Zig-Zag traversal of a binary tree
14. Check if a tree is balanced or not
15. Diagnol Traversal of a Binary tree
16. Boundary traversal of a Binary tree
17. Construct Binary Tree from String with Bracket Representation
18. Convert Binary tree into Doubly Linked List
19. Convert Binary tree into Sum tree
20. Construct Binary tree from Inorder and preorder traversal
21. Find minimum swaps required to convert a Binary tree into BST
22. Check if Binary tree is Sum tree or not
23. Check if all leaf nodes are at same level or not
24. Check if a Binary Tree contains duplicate subtrees of size 2 or more [ IMP ]
25. Check if 2 trees are mirror or not
26. Sum of Nodes on the Longest path from root to leaf node
27. Check if given graph is tree or not.  [ IMP ] -> Will do it in Graph Section
28. Find Largest subtree sum in a tree
29. Maximum Sum of nodes in Binary tree such that no two are adjacent
30. Print all "K" Sum paths in a Binary tree
31. Find LCA in a Binary tree
32. Find distance between 2 nodes in a Binary tree
33. Kth Ancestor of node in a Binary tree
34. Find all Duplicate subtrees in a Binary tree [ IMP ] (Similar to Q - 24)
35. Tree Isomorphism Problem
*/

#include <bits/stdc++.h>
using namespace std;
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
class Solution
{
public:
    // Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *node)
    {
        // Your code here
        vector<int> ans;
        ans.push_back(node->data);
        queue<Node *> que;
        if (node->left != NULL)
        {
            que.push(node->left);
        }
        if (node->right != NULL)
        {
            que.push(node->right);
        }
        while (!que.empty())
        {
            Node *temp = que.front();
            que.pop();
            ans.push_back(temp->data);
            if (temp->left != NULL)
            {
                que.push(temp->left);
            }
            if (temp->right != NULL)
            {
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
        queue<Node *> que;
        if (node->right != NULL)
        {
            que.push(node->right);
        }
        if (node->left != NULL)
        {
            que.push(node->left);
        }
        while (!que.empty())
        {
            Node *temp = que.front();
            que.pop();
            ans.push_back(temp->data);
            if (temp->right != NULL)
            {
                que.push(temp->right);
            }
            if (temp->left != NULL)
            {
                que.push(temp->left);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    // Function to find the height of a binary tree.
    int tree_height(struct Node *node)
    {
        // code here
        if (node == NULL)
            return 0;
        else
            return 1 + max(tree_height(node->left), tree_height(node->right));
    }

    // Function to return the diameter of a Binary Tree.
    int res = 0;
    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        res = max(res, 1 + lh + rh);
        return 1 + max(lh, rh);
    }
    int diameter(Node *root)
    {
        height(root);
        return res;
    }

    // Mirror of a Tree
    Node *mirrorTree(Node *root)
    {
        if (root == NULL)
        {
            return root;
        }
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        if (root->left)
            mirrorTree(root->left);
        if (root->right)
            mirrorTree(root->right);
        return root;
    }

    // iterative Inorder traversal of tree
    void print_inorder_iterative(Node *root)
    {
        cout << "Inorder : ";
        stack<Node *> stk;
        Node *curr = root;
        while (!stk.empty() || curr != NULL)
        {
            if (curr != NULL)
            {
                stk.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stk.top();
                stk.pop();
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
        cout << endl;
    }
    // iterative pre-order traversal of tree
    void print_preorder_iterative(Node *root)
    {
        cout << "Pre-Order : ";
        if (root == NULL)
            return;
        stack<Node *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            Node *curr = stk.top();
            stk.pop();
            cout << curr->data << " ";
            if (curr->right != nullptr)
                stk.push(curr->right);
            if (curr->left != nullptr)
                stk.push(curr->left);
        }
        cout << endl;
    }
    // iterative post-order traversal of tree
    void print_post_iterative(Node *root)
    {
        cout << "Post-Order : ";
        if (root == NULL)
            return;
        stack<Node *> stk;
        stack<int> ans;
        stk.push(root);
        while (!stk.empty())
        {
            Node *curr = stk.top();
            stk.pop();
            ans.push(curr->data);
            if (curr->left != nullptr)
                stk.push(curr->left);
            if (curr->right != nullptr)
                stk.push(curr->right);
        }
        while (!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }

    // left view of Binary Search Tree
    vector<int> leftView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            int count = que.size();
            for (int i = 0; i < count; i++)
            {
                Node *curr = que.front();
                que.pop();
                if (i == 0)
                    ans.push_back(curr->data);
                if (curr->left != NULL)
                    que.push(curr->left);
                if (curr->right != NULL)
                    que.push(curr->right);
            }
        }
        return ans;
    }
    // Right view of Binary Tree
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            int count = que.size();
            for (int i = 0; i < count; i++)
            {
                Node *curr = que.front();
                que.pop();
                if (i == count - 1)
                    ans.push_back(curr->data);
                if (curr->left != NULL)
                    que.push(curr->left);
                if (curr->right != NULL)
                    que.push(curr->right);
            }
        }
        return ans;
    }
    // top view of Binary Search Tree
    vector<int> topView(Node *root)
    {
        // Your code here
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int line = it.second;
            if (mp.find(line) == mp.end())
                mp[line] = node->data;

            if (node->left != NULL)
                q.push({node->left, line - 1});

            if (node->right != NULL)
                q.push({node->right, line + 1});
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }

    // Bottom View of Binary Tree
    vector<int> bottomView(Node *root)
    {
        // Your code here
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int line = it.second;
            mp[line] = node->data;

            if (node->left != NULL)
                q.push({node->left, line - 1});

            if (node->right != NULL)
                q.push({node->right, line + 1});
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
    //  ZigZag or Spiral Traversal
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<Node *> q;
        stack<int> s;
        q.push(root);
        bool reverse = false;
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (reverse)
                    s.push(curr->data);
                else
                    ans.push_back(curr->data);

                if (curr->left != NULL)
                    q.push(curr->left);

                if (curr->right != NULL)
                    q.push(curr->right);
            }
            if (reverse)
            {
                while (!s.empty())
                {
                    ans.push_back(s.top());
                    s.pop();
                }
            }
            reverse = !reverse;
        }
        return ans;
    }

    // Check for Balaced Binary Tree
    int bfsHeight(Node *root)
    {
        if (root == NULL)
            return 0;
        int lh = bfsHeight(root->left);
        int rh = bfsHeight(root->right);
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
            return -1;
        else
            return max(lh, rh) + 1;
    }
    bool isBalanced(Node *root)
    {
        return bfsHeight(root) != -1;
    }

    //  Diagonam Traversal of Binary Tree
    vector<int> diagonal(Node *root)
    {
        // your code here
        queue<Node *> que;
        vector<int> ans;
        if (!root)
            return ans;
        que.push(root);
        while (!que.empty())
        {
            Node *temp = que.front();
            que.pop();
            while (temp)
            {
                if (temp->left)
                    que.push(temp->left);
                ans.push_back(temp->data);
                temp = temp->right;
            }
        }
        return ans;
    }

    // Boundry of a Binary Tree
    void left_boundry(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->left)
        {
            ans.push_back(root->data);
            left_boundry(root->left, ans);
        }
        else if (root->right)
        {
            ans.push_back(root->data);
            left_boundry(root->right, ans);
        }
    }

    void leaf_node(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        leaf_node(root->left, ans);
        if (!(root->left) && !(root->right))
            ans.push_back(root->data);
        leaf_node(root->right, ans);
    }

    void right_boundry(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->right)
        {
            right_boundry(root->right, ans);
            ans.push_back(root->data);
        }
        else if (root->left)
        {
            right_boundry(root->left, ans);
            ans.push_back(root->data);
        }
    }
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        left_boundry(root->left, ans);
        leaf_node(root->left, ans);
        leaf_node(root->right, ans);
        right_boundry(root->right, ans);
        return ans;
    }

    // String to Binary Tree Conversion
    int findIdx(string str, int si, int ei)
    {
        if (si > ei)
            return -1;

        stack<char> s;

        for (int i = si; i <= ei; i++)
        {
            if (str[i] == '(')
                s.push(str[i]);
            else if (str[i] == ')')
            {
                if (s.top() == '(')
                {
                    s.pop();
                    if (s.empty())
                        return i;
                }
            }
        }
        return -1;
    }
    Node *treeFromString(string str, int si, int ei)
    {
        // Base case
        if (si > ei)
            return NULL;

        // new Node
        Node *root = new Node(str[si] - '0');
        int index = -1;

        if (si + 1 <= ei && str[si + 1] == '(')
            index = findIdx(str, si + 1, ei);

        if (index != -1)
        {
            root->left = treeFromString(str, si + 2, index - 1);
            root->right = treeFromString(str, index + 2, ei - 1);
        }
        return root;
    }

    // Binary to DLL Conversion
    Node *previous = NULL;
    Node *bToDLL(Node *root)
    {
        if (root == NULL)
            return root;
        Node *head = bToDLL(root->left);
        if (previous == NULL)
        {
            head = root;
        }
        else
        {
            root->left = previous;
            previous->right = root;
        }
        previous = root;
        bToDLL(root->right);
        return head;
    }
    // Convery Binary Tree to Sum tree
    int solve(Node *root)
    {
        if (!root)
            return 0;

        int lv = solve(root->left);
        int rv = solve(root->right);
        int val = root->data;
        root->data = lv + rv;
        return lv + rv + val;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }

    // Construct Binary tree from Inorder and preorder traversal
    int preIndex = 0;
    Node *cTree(int in[], int pre[], int is, int ie)
    {
        if (is > ie)
            return NULL;

        Node *root = new Node(pre[preIndex++]);
        int inIndex;
        for (int i = is; i <= ie; i++)
        {
            if (in[i] == root->data)
            {
                inIndex = i;
                break;
            }
        }
        root->left = cTree(in, pre, is, inIndex - 1);
        root->right = cTree(in, pre, inIndex + 1, ie);
        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        return cTree(in, pre, 0, n - 1);
    }

    // Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child.
    // The task is to find the minimum number of swap required to convert it into Binary Search Tree.
    int minSwaps(vector<int> &nums)
    {
        // Code here
        vector<pair<int, int>> V(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            V[i] = {nums[i], i};
        }
        sort(V.begin(), V.end());
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (V[i].second == i)
                continue;
            else
            {
                count++;
                swap(V[i], V[V[i].second]);
                i--;
            }
        }
        return count;
    }
    void inorder(int a[], std::vector<int> &v,
                 int n, int index)
    {
        if (index >= n)
            return;
        inorder(a, v, n, 2 * index + 1);
        v.push_back(a[index]);
        inorder(a, v, n, 2 * index + 2);
    }
    int minimumSwapsToConvertToBST(int arr[], int n)
    {
        vector<int> traversal;
        inorder(arr, traversal, n, 0);
        return minSwaps(traversal);
    }

    // Check if Binary tree is Sum tree or not
    int f = 1;
    int helper(Node *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->data;
        if (f == 0)
            return 0;
        int a = helper(root->left);
        int b = helper(root->right);
        if (a + b != root->data)
            f = 0;
        return a + b + root->data;
    }
    bool isSumTree(Node *root)
    {
        // Your code here
        f = 1;
        helper(root);
        return f;
    }

    // Check if all leaf nodes are at same level or not
    int ans;
    void solve(Node *root, int h, int &ma)
    {
        if (root == NULL)
            return;
        if (ans == 0)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            if (ma == -1)
            {
                ma = h;
            }
            else
            {
                if (ma != h)
                {
                    ans = 0;
                }
            }
            return;
        }
        solve(root->left, h + 1, ma);
        solve(root->right, h + 1, ma);
    }
    bool check(Node *root)
    {
        int ma = -1;
        ans = 1;
        solve(root, 0, ma);
        return ans;
    }

    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<string, int> m;
    string solve_duplicate(Node *root)
    {
        if (!root)
            return "#";
        string s = "";
        if (!root->left && !root->right)
        {
            s = to_string(root->data);
            return s;
        }
        s = s + to_string(root->data);
        s = s + solve_duplicate(root->left);
        s = s + solve_duplicate(root->right);
        m[s]++;
        return s;
    }
    int dupSub(Node *root)
    {
        m.clear();
        solve(root);
        for (auto x : m)
        {
            if (x.second >= 2)
                return 1;
        }
        return 0;
    }

    // Check if 2 trees are mirror or not
    int checkMirrorTree(int n, int e, int A[], int B[])
    {
        stack<int> v1[n + 1];
        queue<int> v2[n + 1];

        for (int i = 0; i < 2 * e; i += 2)
        {
            v1[A[i]].push(A[i + 1]);
        }
        for (int i = 0; i < 2 * e; i += 2)
        {
            v2[B[i]].push(B[i + 1]);
        }
        bool flag;
        for (int i = 1; i <= n; i++)
        {
            stack<int> &s = v1[i];
            queue<int> &q = v2[i];
            flag = true;
            while (!s.empty() && !q.empty())
            {
                if (s.top() != q.front())
                {
                    flag = false;
                    break;
                }
                s.pop();
                q.pop();
            }
            if (flag == false)
                break;
        }
        if (flag == true)
            return 1;
        else
            return 0;
    }

    // Sum of Nodes on the Longest path from root to leaf node
    vector<int> solve_longPath(Node *root)
    {
        if (!root)
            return {0, 0};
        vector<int> a = solve_longPath(root->left);
        vector<int> b = solve_longPath(root->right);
        if (a[0] > b[0])
            return {a[0] + 1, a[1] + root->data};
        if (a[0] < b[0])
            return {b[0] + 1, b[1] + root->data};
        else
        {
            return {a[0] + 1, max(a[1], b[1]) + root->data};
        }
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        vector<int> ans = solve_longPath(root);
        return ans[1];
    }

    // Check if given graph is tree or not.  [ IMP ] -> Will do it in Graph Section

    // Find Largest subtree sum in a tree
    int findLargestSubtreeSumRec(Node *root, int &ans)
    {
        if (root == NULL)
            return 0;

        int curr_sum = root->data + findLargestSubtreeSumRec(root->left, ans) + findLargestSubtreeSumRec(root->right, ans);
        ans = max(ans, curr_sum);
        return curr_sum;
    }
    int findLargestSubtreeSum(Node *root)
    {
        if (root == NULL)
            return 0;
        int ans = INT_MIN;
        findLargestSubtreeSumRec(root, ans);
        return ans;
    }

    // Maximum Sum of nodes in Binary tree such that no two are adjacent
    unordered_map<Node *, int> dp;
    int getMaxSum(Node *root)
    {
        if (!root)
            return 0;
        if (dp[root])
            return dp[root];

        int inc = root->data;
        if (root->left)
        {
            inc += getMaxSum(root->left->left);
            inc += getMaxSum(root->left->right);
        }
        if (root->right)
        {
            inc += getMaxSum(root->right->left);
            inc += getMaxSum(root->right->right);
        }

        int exc = getMaxSum(root->left) + getMaxSum(root->right);
        dp[root] = max(inc, exc);
        return dp[root];
    }

    // Print all "K" Sum paths in a Binary tree - Path will used to track of paths
    void func(Node *root, vector<int> &path, int k)
    {
        if (!root)
            return;
        path.push_back(root->data);
        func(root->left, path, k);
        func(root->right, path, k);

        int f = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            f += path[i];
            if (f == k)
            {
                for (int j = i; j < path.size(); j++)
                {
                    cout << path[j] << " ";
                }
                cout << endl;
            }
        }
        path.pop_back();
    }

    // Find LCA in a Binary tree
    Node *lca(Node *root, int n1, int n2)
    {
        // Your code here
        if (!root)
            return NULL;
        if (root->data == n1 || root->data == n2)
            return root;

        Node *lca1 = lca(root->left, n1, n2);
        Node *lca2 = lca(root->right, n1, n2);

        if (lca1 != NULL && lca2 != NULL)
            return root;

        if (lca1 != NULL)
            return lca1;
        else
            return lca2;
    }

    // Find distance between 2 nodes in a Binary tree
    Node *LCA(Node *root, int n1, int n2)
    {
        // Your code here
        if (root == NULL)
            return root;
        if (root->data == n1 || root->data == n2)
            return root;

        Node *left = LCA(root->left, n1, n2);
        Node *right = LCA(root->right, n1, n2);

        if (left != NULL && right != NULL)
            return root;
        if (left == NULL && right == NULL)
            return NULL;
        if (left != NULL)
            return LCA(root->left, n1, n2);

        return LCA(root->right, n1, n2);
    }
    int findLevel(Node *root, int k, int level)
    {
        if (root == NULL)
            return -1;
        if (root->data == k)
            return level;

        int left = findLevel(root->left, k, level + 1);
        if (left == -1)
            return findLevel(root->right, k, level + 1);
        return left;
    }

    int findDist(Node *root, int a, int b)
    {
        Node *lca = LCA(root, a, b);

        int d1 = findLevel(lca, a, 0);
        int d2 = findLevel(lca, b, 0);

        return d1 + d2;
    }

    // Kth Ancestor of node in a Binary tree
    Node *temp = NULL;
    Node *kthAncestorDFS(Node *root, int node, int &k)
    {
        if (!root)
            return NULL;

        if (root->data == node ||
            (temp = kthAncestorDFS(root->left, node, k)) ||
            (temp = kthAncestorDFS(root->right, node, k)))
        {
            if (k > 0)
                k--;

            else if (k == 0)
            {
                cout << "Kth ancestor is: " << root->data;
                return NULL;
            }
            return root;
        }
    }

    // Find all Duplicate subtrees in a Binary tree [ IMP ]
    string print_rec(Node *root, unordered_map<string, int> &m, bool &f, vector<int> &res)
    {
        if (!root)
            return "";
        string s;
        s += print_rec(root->left, m, f, res);
        s += to_string(root->data);
        s += print_rec(root->right, m, f, res);

        if (m[s] == 1)
        {
            f = true;
            res.push_back(root->data);
        }
        m[s]++;
        return s;
    }
    vector<Node *> printAllDups(Node *root)
    {
        // Code here
        bool f = false;
        unordered_map<string, int> m;
        vector<int> res;
        print_rec(root, m, f, res);
        if (f == false)
        {
            cout << "-1";
            return;
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }

    // Tree Isomorphism Problem
    bool isIsomorphic(Node *root1, Node *root2)
    {
        // add code here.
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        if (root1->data != root2->data)
            return false;
        bool l = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
        bool r = isIsomorphic(root1->right, root2->left) && isIsomorphic(root1->left, root2->right);
        return l || r;
    }
};
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
    root->left->right = new Node(60);
    Solution s1;
    return 0;
}