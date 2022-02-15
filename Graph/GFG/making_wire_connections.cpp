#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int src, vector<int> g[], vector<int> &vis)
    {
        vis[src] = 1;
        for(auto val : g[src])
        {
            if(!vis[val])
            {
                dfs(val, g, vis);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> g[n];
        int m = connections.size();
        if(m < n-1) return -1;
        for (auto & connection : connections) {
            g[connection[0]].push_back(connection[1]);
            g[connection[1]].push_back(connection[0]);
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(!vis[i])
            {
                cnt++;
                dfs(i, g, vis);
            }
        }
        return cnt - 1;
    }
};
int main()
{
    vector<vector<int>> matrix;

    return 0;
}