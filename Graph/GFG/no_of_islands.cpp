#include<bits/stdc++.h>
using namespace std;
class Solution{
    void dfs(int i, int j, int vis[][501], vector<int> A[], int N, int M)
    {
        if(i<0 || j<0 || i>=N || j>=M) return;
        if(A[i][j]==0) return;
        if(!vis[i][j])
        {
            vis[i][j] = 1;
            dfs(i+1, j, vis, A, N, M);
            dfs(i-1, j, vis, A, N, M);
            dfs(i, j+1, vis, A, N, M);
            dfs(i, j-1, vis, A, N, M);
            dfs(i+1, j+1, vis, A, N, M);
            dfs(i-1, j-1, vis, A, N, M);
            dfs(i+1, j-1, vis, A, N, M);
            dfs(i-1, j+1, vis, A, N, M);
        }
    }
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<int>>& grid) {
        // Code here
        int vis[501][501];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                vis[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if(!vis[i][j] && A[i][j]==1)
                {
                    dfs(i, j, vis, A, N, M);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    return 0;
}
