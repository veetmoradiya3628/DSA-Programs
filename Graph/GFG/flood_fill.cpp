#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &image, int newColor, int n, int m , int oldColor)
    {
        if(i<0 || j<0 || i>=n || j>=m)
            return;
        if(vis[i][j] || image[i][j]!=oldColor)
            return;
        vis[i][j] = 1;
        image[i][j] = newColor;
        dfs(i+1, j, vis, image, newColor, n, m, oldColor);
        dfs(i-1, j, vis, image, newColor, n, m, oldColor);
        dfs(i, j+1, vis, image, newColor, n, m, oldColor);
        dfs(i, j-1, vis, image, newColor, n, m, oldColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image.size();
        int y = image[0].size();
        vector<vector<int>> vis(x, vector<int>(y, 0));
        int oldColor = image[sr][sc];
        dfs(sr, sc, vis, image, newColor, x, y, oldColor);
        return image;
    }
};
int main()
{
    vector<vector<int>> matrix;

    return 0;
}