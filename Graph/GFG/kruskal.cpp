#include<bits/stdc++.h>
using namespace std;
// node structure to store our edges
struct node {
    int u;
    int v;
    int wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

// compare function to sort our edges with respect to weight
bool comp(node a, node b) {
    return a.wt < b.wt;
}

// find parent of node in disjoint set
int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u;
    return parent[u] = findPar(parent[u], parent);
}

// make union of two different values in disjoint set
void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}


int main(){
    // N - no. of vertex, m - no. of edges
    int N,m;
    cin >> N >> m;
    vector<node> edges;
    
    // getting edges as input in format of -> src, des, weight
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    
    // sorting the edges by weight
    sort(edges.begin(), edges.end(), comp);

    // making parent and rank array initialized
    vector<int> parent(N);
    for(int i = 0;i<N;i++)
        parent[i] = i;
    vector<int> rank(N, 0);

    // to store the whole cost of MST
    int cost = 0;
    
    // to store the pairs which will be added to make MST
    vector<pair<int,int>> mst;
    for(auto it : edges) {
    
        // find weather edge is valid or not according to algorithm
        if(findPar(it.v, parent) != findPar(it.u, parent)) {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    
    cout << "Total cost : "<<cost << endl;
    cout<<"Edges : "<<endl;
    for(auto it : mst) cout << it.first << " - " << it.second << endl;
    return 0;
}