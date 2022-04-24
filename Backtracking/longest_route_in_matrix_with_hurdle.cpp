#include<bits/stdc++.h>
using namespace std;
void solve(int r, int c, vector<vector<int>> mat, vector<vector<bool>> visited, int &ans, int prow, int pcol, int dx, int dy, 
    int pathlength)
{
    if(prow == dx && pcol == dy)
    {
        if(ans < pathlength)
        {
            ans = pathlength;
            return;
        }
    }

    if(prow < 0 || pcol < 0 || prow >= r || pcol >= c || visited[prow][pcol] || mat[prow][pcol] == 0)
    {
        return;
    }
    visited[prow][pcol] = true;
    solve(r, c, mat, visited, ans, prow, pcol + 1, dx, dy, pathlength + 1);
    solve(r, c, mat, visited, ans, prow, pcol - 1, dx, dy, pathlength + 1);
    solve(r, c, mat, visited, ans, prow + 1, pcol, dx, dy, pathlength + 1);
    solve(r, c, mat, visited, ans, prow - 1, pcol, dx, dy, pathlength + 1);
    visited[prow][pcol] = false;
    return;
}
int main()
{
    int r, c;
    cin>>r>>c;
    int x1, y1, x2, y2;

    vector<vector<int>> mat(r, vector<int> (c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>mat[i][j];
        }        
    }

    cin>>x1>>y1>>x2>>y2;

    vector<vector<bool>> visited(r, vector<bool> (c, false));

    int ans = INT_MIN;

    if(mat[x1][y1] == 0){
        cout<<"source point is herdle"<<endl;
    }else{
        solve(r, c, mat, visited, ans, x1, y1, x2, y2, 0);
        cout<<"max distance from src to des is : "<<endl;
        cout<<ans<<endl;
    }
    
    return 0;
}