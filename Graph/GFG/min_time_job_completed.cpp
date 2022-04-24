/*
    Minimum time taken by each job to be completed given by a Directed Acyclic Graph
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v, e;
    cin>>v>>e;

    vector<int> graph[v+1];
    vector<int> indegree(v+1, 0);
    for (int i = 0; i < e; ++i) {
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        indegree[y]++;
    }
    vector<int> ans(v+1, 0);
    queue<int> q;
    for (int i = 0; i <= v; ++i) {
        if(indegree[i]==0){
            q.push(i);
            ans[i] = 1;
        }
    }
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        for(auto it : graph[val])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                ans[it] = ans[val] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i <= v; ++i) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}



/*

INPUT : 
 
10 13
1 3
1 4
1 5
2 3
2 8
2 9
3 6
4 6
4 8
5 8
6 7
7 8
8 10
 */