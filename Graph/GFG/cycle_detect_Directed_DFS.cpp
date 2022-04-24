/*
 * Detect Cycle in Directed Graph using DFS Algo
 * */
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> vec[], int src, int des)
{
    vec[src].push_back(des);
}
void printGraph(vector<int> vec[], int V){
    for (int i = 0; i < V; ++i) {
        cout<<"Adj list for vertex "<<i<<" is -> ";
        for(auto val : vec[i])
            cout<<val<<" ";
        cout<<endl;
    }
}
bool isCycleUtil(int v,  vector<int> ver[], bool visited[], bool dfs_visited[])
{
    visited[v] = true;
    dfs_visited[v] = true;

    for(auto it : ver[v])
    {
        if(!visited[it])
        {
            if(isCycleUtil(it, ver, visited, dfs_visited))
            {
                return true;
            }
        }else if(dfs_visited[it])
        {
            return true;
        }
    }
    dfs_visited[v] = false;
    return false;
}
bool isCyclic(vector<int> ver[], int V)
{
    bool is_visited[V];
    bool dfs_visited[V];
    for (int i = 0; i < V; i++)
    {
        is_visited[i] = false;
        dfs_visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if(!is_visited[i]){
            if(isCycleUtil(i, ver, is_visited, dfs_visited))
                return true;
        }
    }
    return false;
}
int main()
{
    int V = 4;
    vector<int> ver[V];
    addEdge(ver, 0, 1);
    addEdge(ver, 1, 2);
    addEdge(ver, 2, 3);
     addEdge(ver, 3, 0);
    printGraph(ver, V);
    cout<<isCyclic(ver, V)<<endl;
    return 0;
}