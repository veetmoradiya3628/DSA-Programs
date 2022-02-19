#include<bits/stdc++.h>
using namespace std;
class Solution {
    // function to find the coordinates for given current possible value in chess board
    vector<int> cordinates(int curr, int n)
    {
        vector<int> ans;

        int r = n - (curr - 1) / (n - 1);
        int c = (curr - 1) % n;

        if(r % 2 == n % 2)
        {
            ans.push_back(r);
            ans.push_back(n - 1 - c);
        }else{
            ans.push_back(r);
            ans.push_back(c);
        }
        return ans;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // size of board
        int n = board.size();

        // no. of steps
        int steps = 0;

        
        queue<int> q;
        
        // boolean matrix to track the visited vertex
        bool visited[n][n];

        // push the first bottom left value in queue as we are starting snack game from here
        q.push(1);
        
        // make bottom left position visited
        visited[n-1][0] = true;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i) {

                int x = q.front();
                q.pop();

                // if we reach top left corner as 100 then we can say we have won the match, and we can return the steps
                if(x*x == n*n) return steps;

                // for each possible value from 1 to 6
                for (int k = 1; k <= 6; ++k) {
                     
                    // if position is out of bound then return
                    if(k+x > n*n) break;

                    // to get the appropriate position on board
                    vector<int> pos = cordinates(k + n, n);

                    int r = pos[0];
                    int c = pos[1];

                    // if we have already visited then don't do nothing
                    if(visited[r][c]) continue;

                    // mark position visited
                    visited[r][c] = true;

                    // if not snack or ladder then add it to the queue
                    if(board[r][c] == -1)
                        q.push(k+x);
                    // else add value from board to the queue
                    else
                        q.push(board[r][c]);
                }
            }
            steps++;
        }
        return  -1;
    }
};
int main()
{
    return 0;
}
