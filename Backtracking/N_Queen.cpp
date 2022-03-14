// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
bool isSafe(int row, int col, vector<string> board, int n)
    {
        int duprow=row, dupcol=col ;
        while(row>=0 and col>=0)
        {
            if(board[row][col]=='Q') return false ;
            row--, col-- ;
        }
        row=duprow, col=dupcol ;
        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col-- ;
        }
        col=dupcol ;
        while(row<n and col>=0)
        {
            if(board[row][col]=='Q') return false ;
            col--, row++ ;
        }
        
        return true ; 
    }
    void solve(int col, vector<vector<int>> &ans, vector<string> &board, int n, vector<int> &sol)
    {
        if(col==n) 
        {
            ans.push_back(sol) ;
            return ;
        }
        for(int row=0 ; row<n ; row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q' ;
                sol[col]=row+1 ;
                solve(col+1, ans, board, n, sol) ;
                board[row][col]='.' ;
                sol[col]=0 ;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans ;
        vector<string> board(n) ;
        string s(n, '.') ;
        for(int i=0 ; i<n ; i++)
            board[i]=s ;
        vector<int> sol(n, 0) ;
        solve(0, ans, board, n, sol) ;
        return ans ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends