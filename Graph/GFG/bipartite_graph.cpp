#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true;
}
bool bipartiteDFS(int node, vector<int> adj[], int color[])
{
    if(color[node] == -1) color[node] = 1;

    for(auto it : adj[node])
    {
        if(color[it]==-1)
        {
            color[it] = 1 - color[node];
            if(!bipartiteDFS(it, adj, color))
                return false;
        }else if(color[it]==color[node])
            return false;
    }
    return true;
}
bool checkBipartite_DFS(vector<int> adj[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteDFS(i, adj, color)) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	cout<<endl;
    if(checkBipartite(adj, n)) {
        cout << "yes"<<endl;
    } else {
        cout << "No"<<endl;
    }

    if(checkBipartite_DFS(adj, n)) {
        cout << "yes"<<endl;
    } else {
        cout << "No"<<endl;
    }
    return 0;
}
