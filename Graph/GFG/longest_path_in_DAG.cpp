#include <bits/stdc++.h>
using namespace std;
void printGraph(vector<int> adj[], int n)
{
    for (int i = 0; i<n; i++) {
        cout<<"vertex : "<<i<<" : ";
        for(auto val : adj[i])
            cout<<val<<" ";
        cout<<endl;
    }
}
vector<int> topologicalSort(vector<int> adj[], int V)
{
    vector<int> ans;
    vector<int> LPT(V, 0);          // longest path in a DAG
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; ++i) {
        for(auto it : adj[i])
        {
            indegree[it] = indegree[it] + 1;
        }
    }
    cout<<"In Degree is with specific index: "<<endl;
    for (int i = 0; i < V; ++i) {
        cout<<indegree[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    queue<int> que;
    for (int i = 0; i < V; ++i) {
        if(indegree[i]==0)
            que.push(i);
    }

    while (!que.empty())
    {
        int val = que.front();
        ans.push_back(val);
        que.pop();

        for(auto it : adj[val])
        {
           indegree[it]  = indegree[it] -1;
           LPT[it] = max(LPT[it], 1 + LPT[val]);
           if(indegree[it]==0)
               que.push(it);
        }
    }
    cout<<"Topological Sort and LPT : ";
    for(auto it : ans)
        cout<<it<<" "<<LPT[it]<<endl;
    cout<<endl;
    cout<<endl;
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    printGraph(adj, n);
    vector<int> ans = topologicalSort(adj, n);
    cout<<"Topological Sort : ";
    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}
