/*
 * BFS Traversal of Graph which is represented in form of Adj List
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
void BFS_List(vector<int> vec[], int V, int src){
    bool is_visited[V];
    for (int i = 0; i < V; ++i) {
        is_visited[i] = false;
    }

    queue<int> que;
    is_visited[src] = true;
    que.push(src);

    while (!que.empty()){
        src = que.front();
        cout<<src<<" ";
        que.pop();

        for (int & i : vec[src]) {
            if(!is_visited[i]){
                is_visited[i] = true;
                que.push(i);
            }
        }
    }
    cout<<endl;
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
    cout<<"BFS from vertex 0 : "<<endl;
    BFS_List(ver, 5, 0);

    cout<<"BFS from vertex 2 : "<<endl;
    BFS_List(ver, 5, 2);

    cout<<"BFS from vertex 1 : "<<endl;
    BFS_List(ver, 5, 1);

    cout<<"BFS from vertex 4 : "<<endl;
    BFS_List(ver, 5, 4);

    cout<<"BFS from vertex 3 : "<<endl;
    BFS_List(ver, 5, 3);


    return 0;
}