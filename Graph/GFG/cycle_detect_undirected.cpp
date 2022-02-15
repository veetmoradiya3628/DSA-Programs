/*
Cycle Detection in Undirected Graph using BFS and DFS
*/

#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> vec[], int src, int des)
{
    vec[src].push_back(des);
    vec[des].push_back(src);
}
void printGraph(vector<int> vec[], int V){
    for (int i = 0; i < V; ++i) {
        cout<<"Adj list for vertex "<<i<<" is -> ";
        for(auto val : vec[i])
            cout<<val<<" ";
        cout<<endl;
    }
}


// Cycle Detection in UnDirected Graph - DFS Based
bool CycleRec(vector<int> ver[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for(int val : ver[s])
    {
        if(!visited[val])
        {
            if(CycleRec(ver, val, visited, s))
                return true;
        }
        else if(val!=parent){
            return true;
        }
    }
    return false;
}
bool detect_Cycle_DFS(vector<int> ver[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < V; ++i) {
        if(!visited[i])
        {
            if(CycleRec(ver, i, visited, -1))
                return true;
        }
    }
    return false;
}
// Cycle Detection in UnDirected Graph - BFS Based
bool isCycle_BFS(int src, int V, vector<int> ver[], bool is_visited[])
{
    queue<pair<int, int>> que;
    que.push({src, -1});
    is_visited[src] = true;

    while (!que.empty())
    {
        int node = que.front().first;
        int parent = que.front().second;
        que.pop();
        for(int val : ver[node])
        {
            if(!is_visited[val])
            {
                is_visited[val] = true;
                que.push({val, node});
            }else if(parent!=val)
                return true;
        }
    }
    return false;
}
bool detect_Cycle_BFS(vector<int> ver[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < V; ++i) {
        if(!visited[i])
        {
            if(isCycle_BFS(i, V, ver, visited))
                return true;
        }
    }
    return false;
}
int main()
{
    int V = 6;
    vector<int> ver[V];
    addEdge(ver, 0, 1);
    addEdge(ver, 1, 2);
    addEdge(ver, 2, 3);
    addEdge(ver, 0, 3);
    addEdge(ver, 3, 4);
    addEdge(ver, 4, 5);
    cout<<detect_Cycle_DFS(ver, V)<<endl;
    cout<<detect_Cycle_BFS(ver, V)<<endl;
    return 0;
}