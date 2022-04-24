/*
 * BFS Traversal of Graph which is represented in form of Adj Matrix
 * */
#include <bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(int arr[][V], int src, int des)
{
    arr[src][des] = 1;
    arr[des][src] = 1;
}
void printGraph(int arr[][V]){
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void BFS_Matrix(int arr[][V], int src){
    bool is_visited[V] = {false};
    vector<int> que;
    que.push_back(src);

    is_visited[src] = true;

    int vis;
    while(!que.empty()){
        vis = que[0];
        cout<<vis<<" ";
        que.erase(que.begin());

        for(int i=0; i< V; i++)
        {
            if(arr[vis][i]==1 && (!is_visited[i])){
                que.push_back(i);
                is_visited[i] = true;
            }
        }
    }
    cout<<endl;
}
int main()
{
    int arr[V][V] = {0};
    addEdge(arr, 0, 1);
    addEdge(arr, 0, 2);
    addEdge(arr, 0, 3);
    addEdge(arr, 1, 3);
    addEdge(arr, 2, 3);
    addEdge(arr, 3, 4);
    addEdge(arr, 1, 4);
    printGraph(arr);
    cout<<"BFS traversal from vertex 0 : ";
    BFS_Matrix(arr, 0);
    cout<<"BFS traversal from vertex 1 : ";
    BFS_Matrix(arr, 1);
    cout<<"BFS traversal from vertex 2 : ";
    BFS_Matrix(arr, 2);
    cout<<"BFS traversal from vertex 3 : ";
    BFS_Matrix(arr, 3);
    cout<<"BFS traversal from vertex 4 : ";
    BFS_Matrix(arr, 4);
    return 0;
}

