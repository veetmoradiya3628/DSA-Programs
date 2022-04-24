/*
 * Undirected Graph Adjacency List Implementation
 * for Directed Graph we will be adding only Source to Destination Entry in addEdge Function
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
int main()
{
    int V = 5;
    vector<int> ver[V];
    addEdge(ver, 0, 1);
    addEdge(ver, 0, 2);
    addEdge(ver, 0, 3);
    addEdge(ver, 1, 3);
    addEdge(ver, 2, 3);
    addEdge(ver, 3, 4);
    addEdge(ver, 1, 4);
    printGraph(ver, V);
    return 0;
}