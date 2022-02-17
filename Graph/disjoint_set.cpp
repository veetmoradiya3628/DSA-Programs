#include<bits/stdc++.h>
using namespace std;
int parent[100000];
int _rank[100000];

void makeSet(int n) {
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        _rank[i] = 0;
    }
}

int findPar(int node) {
    if(node == parent[node])
        return node;
    
    return parent[node] = findPar(parent[node]);
}

void _union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if (_rank[u] < _rank[v])
    {
        parent[u] = v;
    }else if(_rank[u] > _rank[v])
    {
        parent[v] = u;
    }else{
        parent[v] = u;
        _rank[u]++;
    }
}

int main()
{
    makeSet(100000);
    int m;
    cin>>m;
    while (m-->0)
    {
        int u, v;
        _union(u, v);
    }
    // if 2 and 3 belong to the same component or not
    if(findPar(2) != findPar(3))
    {
        cout<<"Different Component"<<endl;
    }else{
        cout<<"Same Component"<<endl;
    }
    return 0;
}