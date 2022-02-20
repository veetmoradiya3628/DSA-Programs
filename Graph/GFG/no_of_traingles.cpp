#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int V = 4;
    int graph[][V] = {
            {0, 1, 1, 0},
            {1, 0, 1, 1},
            {1, 1, 0, 1},
            {0, 1, 1, 0}
        };
    bool isDirected = false;
    int countTraingle = 0;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            for (int k = 0; k < V; ++k) {
                if(graph[i][j] && graph[j][k] && graph[k][i])
                    countTraingle++;
            }
        }
    }
    if(isDirected) countTraingle/=3;
    else countTraingle/=6;
    
    cout<<countTraingle<<endl;
}
int main()
{
    solve();
    return 0;
}