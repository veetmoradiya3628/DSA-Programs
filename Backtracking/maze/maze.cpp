#include<bits/stdc++.h>
using namespace std;
// count the path in maze of m x n
int count_path(int r, int c)
{
    if(r == 1 || c == 1){
        return 1;
    }
    int left = count_path(r - 1, c);
    int right = count_path(r, c - 1);
    return left + right;
}
// print the paths
void path(string ans, int r, int c)
{
    if(r == 1 && c == 1){
        cout<<ans<<endl;
        return;
    }

    if(r > 1){
        path(ans + "D", r - 1, c);
    }

    if(c > 1){
        path(ans + "R", r, c - 1);
    }
}
// print the paths when we can go Horizontal, Vertical and Diagonal as well
void path_diagonal(string ans, int r, int c)
{
    if(r == 1 && c == 1){
        cout<<ans<<endl;
        return;
    }

    if(r > 1 && c > 1){
        path_diagonal(ans + "D", r - 1, c - 1);
    }

    if(r > 1){
        path_diagonal(ans + "V", r - 1, c);
    }

    if(c > 1){
        path_diagonal(ans + "H", r, c - 1);
    }
}
// path with restrictions on maze
void pathRestrictions(string ans, vector<vector<bool>> maze, int r, int c){
    if(r == maze.size() - 1 && c == maze[0].size() - 1){
        cout<<ans<<endl;
        return;
    }

    if(!maze[r][c])
    {
        return;
    }

    if(r < maze.size() - 1){
        pathRestrictions(ans + "D", maze, r + 1, c);
    }

    if(c < maze[0].size() - 1){
        pathRestrictions(ans + "R", maze, r, c + 1);
    }
}
int main()
{
//     cout<<count_path(3, 3)<<endl;
//     cout<<count_path(4, 4)<<endl;

    // path("", 3, 3);
    // cout<<endl;
    // path("", 4, 4);

    // path_diagonal("", 3, 3);

    vector<vector<bool>> board
    {
        {true, true, true},
        {true, false, true},
        {true, true, true}
    };
    pathRestrictions("", board, 0, 0);
    return 0;
}