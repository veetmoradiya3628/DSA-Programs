#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for(auto it : adj[node])
    {
        if(it == parent) continue;

        if(!vis[it])
        {
            dfs(it, node, vis, tin, low, timer, adj);
            low[node] = min(low[node], low[it]);

            if(low[it] > tin[node])
            {
                cout<<node<<" "<<it<<endl;
            }
        }else{
            low[node] = min(low[node], tin[it]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<int> vis(n, 0);

    int timer = 0;
    for (int i = 0; i < n; ++i) {
        if(!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, adj);
        }
    }
    return 0;
}

/*

GRAPH - 1 With Bridge

 5 5
1 0
0 2
2 1
0 3
3 4

 GRAPH - 2 With bridge

7 8
0 1
1 2
2 0
1 3
1 4
1 6
3 5
4 5
 
 */