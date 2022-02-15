/*
 * DFS Traversal of Graph which is represented in form of Adj List
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
void dfs(int src, bool is_visited[], vector<int> vec[], vector<int>& ans)
{
    ans.push_back(src);
    is_visited[src] = true;
    for(auto & i : vec[src])
    {
        if(!is_visited[i]){
            dfs(i, is_visited, vec, ans);
        }
    }
}
vector<int> DFS(vector<int> vec[], int V)
{
    vector<int> ans;
    bool is_visited[V];
    for (int i = 0; i < V; ++i) {
        is_visited[i] = false;
    }
    for (int i = 0; i < V; ++i) {
        if(!is_visited[i]){
            dfs(i, is_visited, vec, ans);
        }
    }
    return ans;
}
int main()
{
    int V = 8;
    vector<int> ver[V];
    addEdge(ver, 0, 1);
    addEdge(ver, 1, 2);
    addEdge(ver, 2, 3);
    addEdge(ver, 3, 4);
    addEdge(ver, 1, 5);
    addEdge(ver, 5, 6);
    addEdge(ver, 6, 7);
    printGraph(ver, V);
    vector<int> ans = DFS(ver, V);
    for(int val : ans)
        cout<<val<<" ";
    cout<<endl;
    return 0;
}