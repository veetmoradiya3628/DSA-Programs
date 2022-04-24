#include<bits/stdc++.h>
using namespace std;
// all paths in all the directions
void all_paths(string ans, vector<vector<bool>> maze, int r, int c){
    if(r == maze.size() - 1 && c == maze[0].size() - 1){
        cout<<ans<<endl;
        return;
    }

    if(!maze[r][c])
    {
        return;
    }

    // make the change
    maze[r][c] = false;

    if(r < maze.size() - 1){
        all_paths(ans + "D", maze, r + 1, c);
    }

    if(c < maze[0].size() - 1){
        all_paths(ans + "R", maze, r, c + 1);
    }

    if(r > 0){
        all_paths(ans + "U", maze, r - 1, c);
    }

    if(c > 0){
        all_paths(ans + "L", maze, r, c - 1);
    }

    // revert the change back
    maze[r][c] = true;
}
int main()
{
 vector<vector<bool>> board
    {
        {true, true, true},
        {true, true, true},
        {true, true, true}
    };
    all_paths("", board, 0, 0);
    return 0;
}