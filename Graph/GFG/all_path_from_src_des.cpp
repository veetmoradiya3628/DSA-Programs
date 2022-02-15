/*
Print all the path from Source to Destination - DAG Graph
 * /
/*
 * Undirected Graph Adjacency List Implementation
 * for Directed Graph we will be adding only Source to Destination Entry in addEdge Function
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
void printAllPathsUtil(int src, int des, bool is_visited[], vector<vector<int>>& ans, vector<int>& path, vector<int> ver[])
{
    is_visited[src] = true;
    path.push_back(src);

    if(src==des){
        ans.push_back(path);
    }else{
        for(auto ele : ver[src])
        {
            if(!is_visited[ele])
                printAllPathsUtil(ele, des, is_visited, ans, path, ver);
        }
    }
    path.pop_back();
    is_visited[src] = false;
}
vector<vector<int>> printAllPaths(int src, int des, vector<int> ver[], int V)
{
    bool is_visited[V];
    for (int i = 0; i < V; ++i) {
        is_visited[i] = false;
    }

    vector<vector<int>> ans;
    vector<int> path;
    printAllPathsUtil(src, des, is_visited, ans, path, ver);
    return ans;
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
    vector<vector<int>> ans = printAllPaths(0, 4, ver, V);
    for(const vector<int>& ele : ans)
    {
        for(int val : ele)
            cout<<val<<" ";
        cout<<endl;
    }
    return 0;
}