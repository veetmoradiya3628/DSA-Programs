/*
 * Detect Cycle in Undirected Graph using BFS Algo
 * */
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
bool checkForCycle(int s, int V, vector<int> ver[], vector<int>& visited)
{
    queue<pair<int, int>> q;
    visited[s] = true;

    q.push({s, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for(auto it : ver[node])
        {
            if(!visited[it])
            {
                visited[it] = true;
                q.push({it, node});
            }else if(parent!=it){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> ver[])
{
    vector<int> visited(V, 0);
    for (int i = 0; i < V; ++i) {
        if(!visited[i])
        {
            if(checkForCycle(i, V, ver, visited)){
                return true;
            }
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
    cout<<isCycle(V, ver)<<endl;
    return 0;
}