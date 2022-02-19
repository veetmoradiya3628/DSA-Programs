#include<bits/stdc++.h>
using namespace std;
// for adjacency list implementation

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int> distTo(V, INT_MAX);

    distTo[S] = 0;

    pq.push(make_pair(0, S)); // pair of distance and vertex

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;

        pq.pop();

        for(auto it : adj[prev])
        {
            int next = it[0];
            int nextDistance = it[1];

            if(distTo[next] > dist + nextDistance){
                distTo[next] = distTo[prev] + nextDistance;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
    return  distTo;
}

// for matrix implementation
int minDistance(int dist[], bool sptSet[], int V)
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

        return min_index;
}
vector<int> dijkstra(vector<vector<int>> graph, int V, int src)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;
    for (int count = 0; count < V-1; ++count) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout<<"min dist from src vertex 0 to other is : "<<endl;
    for (int i = 0; i < V; ++i) {
        cout<<dist[i]<<" ";
    }
}
int main()
{
    vector<vector<int>> graph;
    int V;
    cin>>V;
    for (int i = 0; i < V; ++i) {
        vector<int> temp(V);
        for (int j = 0; j < V; ++j) {
            cin>>temp[j];
        }
        graph.push_back(temp);
    }
    dijkstra(graph, V,0);
    return 0;
}


/*
 INPUT: 
 
 9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
 * */