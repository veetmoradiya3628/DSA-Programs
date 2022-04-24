/*
 * Detect Cycle in Undirected Graph using DFS Algo
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
bool checkForCycle(int node, int parent, bool is_visited[], vector<int> ver[])
{
    is_visited[node] = true;
    for(auto it : ver[node])
    {
        if(!is_visited[it])
        {
            if(checkForCycle(it, node, is_visited, ver))
                return true;
        }else if(it!=parent){
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> ver[]) {
    bool is_visited[V];
    for (int i = 0; i < V; ++i) {
        is_visited[i] = false;
    }
    for (int i = 0; i < V; ++i) {
        if(!is_visited[i])
        {
            if(checkForCycle(i, -1, is_visited, ver)){
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