#include<bits/stdc++.h>
using namespace std;
class Solution{
	private: 
	//For making Huffman Tree
    struct Node{
        int data ;
        Node *left, *right ;
        Node(int x)
        {
            data=x ;
            left=NULL ;
            right=NULL ;
        }
    } ;
    
    //For making a Min Heap
    struct comp{
       bool operator()(Node *a, Node *b){
           return a->data > b->data;
       }
   };
	public:
			
		//For Encoding the Alphabets
	    void preorder(Node* root, vector<string> &ans, string c)
	    {
	        if(root==NULL) return ;
	        if(root->left==NULL and root->right==NULL)
	        {
	            ans.push_back(c) ;
	            return ; 
	        }
	        preorder(root->left, ans, c+"0") ;
	        preorder(root->right, ans, c+"1") ;
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    vector<string> ans ;
		    priority_queue<Node*, vector<Node*>, comp> pq ;
		    
		    //For creating leaf nodes
		    for(int i=0 ; i<f.size() ; i++)
		    {
		        Node* temp=new Node(f[i]) ;
		        pq.push(temp) ;
		    }
		    
		    //Creating the Complete Huffman tree
		    while(pq.size()>1)
		    {
		        Node* x=pq.top() ;
		        pq.pop() ;
		        Node* y=pq.top() ;
		        pq.pop() ;
		        Node* temp=new Node(x->data+y->data) ;
		        temp->left=x ;
		        temp->right=y ;
		        pq.push(temp) ;
		    }
		    
		    preorder(pq.top(), ans, "") ;
		    return ans ;
		}
};
int main()
{

    return 0;
}