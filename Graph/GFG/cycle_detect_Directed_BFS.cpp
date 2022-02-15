/*
 * Detect Cycle in Directed Graph using BFS Algo - similar to Topological Sort
 * */
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> vec[], int src, int des)
{
    vec[src].push_back(des);
}
void printGraph(vector<int> vec[], int V)
{
    for (int i = 0; i < V; ++i)
    {
        cout << "Adj list for vertex " << i << " is -> ";
        for (auto val : vec[i])
            cout << val << " ";
        cout << endl;
    }
}
bool topologicalSort(vector<int> ver[], int V)
{
    int cnt = 0;
    int In_degrees[V];
    for (int i = 0; i < V; ++i)
    {
        In_degrees[i] = 0;
    }
    for (int i = 0; i < V; ++i)
    {
        for (auto it : ver[i])
        {
            In_degrees[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; ++i)
    {
        if (In_degrees[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        for (auto item : ver[val])
        {
            In_degrees[item]--;
            if (In_degrees[item] == 0)
            {
                q.push(item);
            }
        }
        cnt++;
    }
    if (cnt != V)
    {
        return true;
    }
    return false;
}
bool isCyclic(vector<int> adj[], int V)
{
    return topologicalSort(adj, V);
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
    cout << isCyclic(ver, V) << endl;
    return 0;
}