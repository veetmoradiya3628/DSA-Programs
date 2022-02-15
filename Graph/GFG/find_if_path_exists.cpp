/*
Find weather path exists from src to destination in graph - for both Diercted and InDirected
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
bool hasPath(vector<int> ver[], int src, int des, bool is_visited[])
{
    if(src==des)
        return true;

    is_visited[src] = true;
    for(int val : ver[src])
    {
        if(!is_visited[val])
        {
            bool has_path = hasPath(ver, val, des, is_visited);
            if(has_path)
                return true;
        }
    }
    return false;
}
int main()
{
    int V = 5;
    vector<int> ver[V];
    addEdge(ver, 0, 1);
    addEdge(ver, 1, 2);
    addEdge(ver, 1, 3);
    addEdge(ver, 3, 4);
    addEdge(ver, 2, 4);
    addEdge(ver, 2, 3);
    bool is_visited[V];
    for (int i = 0; i < V; i++)
    {
        is_visited[i] = false;
    }
    cout<<hasPath(ver, 3, 1, is_visited)<<endl;
    return 0;
}