/*
 * Shortest Path in An Unweighted Graph
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

void shortest_Path(int src, int V, vector<int> ver[])
{
    bool visited[V];
    int dist[V];
    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    queue<int> que;
    que.push(src);
    visited[src] = true;

    while (!que.empty())
    {
        int val = que.front();
        que.pop();
        for(int ele : ver[val])
        {
            if(!visited[ele])
            {
                dist[ele] = dist[val] + 1;
                visited[ele] = true;
                que.push(ele);
            }
        }
    }
    cout<<"Paths from src vertex to all other vertex is : "<<endl;
    for (int i = 0; i < V; ++i) {
        cout<<"Vertex : "<<i<<" dist : "<<dist[i]<<endl;
    }
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
    shortest_Path(0, V, ver);
    return 0;
}