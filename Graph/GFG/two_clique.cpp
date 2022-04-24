#include<bits/stdc++.h>
using namespace std;
int f = 0;
void bipartite(int src, int par, int col, vector<int> &color, vector<int> g[])
{
    color[src] = col;
    for(auto x : g[src])
    {
        if(!color[x])
        {
            bipartite(x, src, 3 - col, color, g);
        }else if(x != par && col == color[x])
        {
            f = 1;
            break;
        }
    }
}
int main()
{
    int v, e;
    cin>>v>>e;
    vector<int> g[v];
    for (int i = 0; i < e; ++i) {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> reverse[v];
    vector<int> dummy(v, 0);
    for (int i = 0; i < v; ++i) {
        dummy[i] = 1;
        for(auto x : g[i])
        {
            dummy[x] = 1;
        }
        for (int j = 0; j < v; ++j) {
            if(dummy[j]==0)
            {
                reverse[i].push_back(j);
                reverse[j].push_back(i);
            }
        }
        dummy.clear();
    }
    vector<int> color(v, 0);
    bipartite(0, 0, 1, color, reverse);
    if(!f)
        cout<<"Two Clique"<<endl;
    else
        cout<<"Not possible"<<endl;
    return 0;
}