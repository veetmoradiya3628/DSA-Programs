#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    // int n = grid.size();
    // int m = grid[0].size();

    // vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
    // queue<pair<int, int>> q;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if(grid[i][j] == 1){
    //             ans[i][j] = 0;
    //             q.push({i, j});
    //         }
    //     }
    // }
    // while(!q.empty())
    // {
    //     int i = q.front().first;
    //     int j = q.front().second;

    //     if((i - 1) >= 0 && ans[i][j] + 1 < ans[i-1][j])
    //     {
    //         ans[i-1][j] = ans[i][j] + 1;
    //         q.push({i-1, j});
    //     }
    //     if((j - 1) >= 0 && ans[i][j] + 1 < ans[i][j-1])
    //     {
    //         ans[i][j-1] = ans[i][j] + 1;
    //         q.push({i, j-1});
    //     }
    //     if((i + 1) >= 0 && ans[i][j] + 1 < ans[i+1][j])
    //     {
    //         ans[i+1][j] = ans[i][j] + 1;
    //         q.push({i+1, j});
    //     }
    //     if((j + 1) >= 0 && ans[i][j] + 1 < ans[i][j+1])
    //     {
    //         ans[i][j+1] = ans[i][j] + 1;
    //         q.push({i, j+1});
    //     }
    //     q.pop();
    // }
    // return ans;


    queue<pair<int,pair<int,int>>> q;
	    int counter = 0;
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            
	            if(grid[i][j] == 0){
	                grid[i][j] = INT_MAX;
	                counter++;
	            }else{
	                grid[i][j] = 0;
	                q.push({0,{i,j}});
	            }
	            
	        }
	    }
	    
	    
	    while(!q.empty()){
	        
	        auto top = q.front(); q.pop();
	        int dist = top.first;
	        int i  = top.second.first;
	        int j  = top.second.second;
	        
	        int arr[] = {0,1,0,-1,0};
	        for(int k=0;k<4;k++){
	            int x = i+arr[k];
	            int y = j+arr[k+1];
	            
	            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]>0){
	                if(grid[x][y]>dist+1){
	                   grid[x][y]=dist+1;
	                   q.push({grid[x][y],{x,y}});
	                   //if(--counter==0) return grid;
	                }
	            }
	        }
	        
	        int arr2[] = {1,1,-1,-1,1};
	        for(int k=0;k<4;k++){
	            int x = i+arr2[k];
	            int y = j+arr2[k+1];
	            
	            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]>0){
	                if(grid[x][y]>dist+2){
	                   grid[x][y]=dist+2;
	                   q.push({grid[x][y],{x,y}});
	                   //if(--counter==0) return grid;
	                }
	            }
	        }
	        
	    }
	    
	    return grid;
}
int main()
{

    return 0;
}