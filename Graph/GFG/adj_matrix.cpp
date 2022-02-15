/*
 * Undirected Graph Adjacency Matrix Implementation
 * for Directed Graph we will be adding only Source to Destination Entry in addEdge Function
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
    return 0;
}

