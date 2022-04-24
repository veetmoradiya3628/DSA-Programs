#include<bits/stdc++.h>
using namespace std;
// all paths in all the directions
void all_path_print(string ans, vector<vector<bool>> maze, int r, int c, vector<vector<int>> path, int step){
    if(r == maze.size() - 1 && c == maze[0].size() - 1){
        path[r][c] = step;
        for (vector<int> row : path)
        {
            for(int val : row){
                cout<<val<<" ";
            }
            cout<<endl;
        }
        cout<<ans<<endl;
        cout<<endl;
        return;
    }

    if(!maze[r][c])
    {
        return;
    }

    // make the change
    maze[r][c] = false;
    path[r][c] = step;
    
    if(r < maze.size() - 1){
        all_path_print(ans + "D", maze, r + 1, c, path, step + 1);
    }

    if(c < maze[0].size() - 1){
        all_path_print(ans + "R", maze, r, c + 1, path, step + 1);
    }

    if(r > 0){
        all_path_print(ans + "U", maze, r - 1, c, path, step + 1);
    }

    if(c > 0){
        all_path_print(ans + "L", maze, r, c - 1, path, step + 1);
    }

    // revert the change back
    maze[r][c] = true;
    path[r][c] = 0;
}
int main()
{
 vector<vector<bool>> board
    {
        {true, true, true},
        {true, true, true},
        {true, true, true}
    };
    vector<vector<int>> path{
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}    
    };
    all_path_print("", board, 0, 0, path, 1);
    return 0;
}