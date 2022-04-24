/*

// Striver Code

class Solution {
  public:
  vector<vector<int>> ans;
 void find(vector<int>& A,vector<int>& comb,int B,int k){
     if(B==0){
         ans.push_back(comb);
     }
     if(B<=0)
     return;
     for(int i=k;i<A.size();i++){
          if (i > k && A[i] == A[i-1])
               continue;
         if(A[i]<=B){
             comb.push_back(A[i]);
             find(A,comb,B-A[i],i);
             comb.pop_back();
         }
     }
     return;
 }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
       vector<int> comb;
       sort(A.begin(),A.end());
       find(A,comb,B,0);
       return ans;
    }
};
*/

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<vector<int>> ans;
 void find(vector<int>& A,vector<int>& comb,int B,int k){
     if(B==0){
         ans.push_back(comb);
     }
     if(B<=0)
     return;
     for(int i=k;i<A.size();i++){
          if (i > k && A[i] == A[i-1])
               continue;
         if(A[i]<=B){
             comb.push_back(A[i]);
             find(A,comb,B-A[i],i);
             comb.pop_back();
         }
     }
     return;
 }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
       vector<int> comb;
       sort(A.begin(),A.end());
       find(A,comb,B,0);
       return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends