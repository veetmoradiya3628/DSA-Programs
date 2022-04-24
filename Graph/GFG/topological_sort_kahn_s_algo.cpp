/*
 * Topological Sort in DAG using Kahn's Algorithm - BFS based
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
vector<int> topologicalSort(vector<int> ver[], int V)
{
    vector<int> ans;
    int In_degrees[V];
    for (int i = 0; i < V; ++i) {
        In_degrees[i] = 0;
    }
    for (int i = 0; i < V; ++i) {
        for(auto it : ver[i])
        {
            In_degrees[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if(In_degrees[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty()){
        int val = q.front();
        ans.push_back(val);
        q.pop();
        for(auto item : ver[val])
        {
            In_degrees[item]--;
            if(In_degrees[item] == 0)
            {
                q.push(item);
            }
        }
    }
    return ans;
}
int main()
{
    int V = 5;
    vector<int> ver[V];
    addEdge(ver, 0, 1);
    addEdge(ver, 1, 2);
    addEdge(ver, 3, 4);
     addEdge(ver, 3, 2);
    vector<int> ans = topologicalSort(ver, V);
    for (int an : ans) {
        cout<<an<<" ";
    }
    cout<<endl;
    return 0;
}