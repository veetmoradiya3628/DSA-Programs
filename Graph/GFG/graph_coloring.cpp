#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v, e;
    cin>>v>>e;
    vector<vector<int>> g(v);
    for (int i = 0; i < e; ++i) {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // to store the answer
    int res[v];
    
    // to track the available and used colors
    bool available[v];
    
    // colored first vertex with color 0
    res[0] = 0;
    
    // remaining vertex color set as -1 for tracking purpose as well
    for (int i = 1; i < v; ++i) {
        res[i] = -1;
    }
    
    // set all the colors as available
    for (int i = 0; i < v; ++i) {
        available[i] = false;
    }

    // number of chromatic numbers
    int cn = 0;
    
    // traverse over all the vertex
    for (int i = 1; i < v; ++i) {
        
        // for present vertex traverse to it's neighbours
        for(auto it : g[i])
        {
            // if any vertex is colored then we will make that color unavailable as we can not use same color for neighbours
            if(res[it]!=-1)
            {
                available[res[it]] = true;
            }
        }

        // now track over the list of colors which we have taken it number of vertex - 1
        int cr;
        for (cr = 0; cr < v; ++cr) {
            
            // if color is available to use then break the loop
            if(!available[cr])
            {
                break;
            }
        }
    
        // set the available vertex color for our present vertex
        res[i] = cr;
        
        // now update chromatic number with updated number
        cn = max(cn, cr + 1);

        // now reset all the color available for others
        for (auto it : g[i]) {
            if(res[it] != -1)
            {
                available[res[it]] = false;
            }
        }
    }
    
    // print the chromatic number
    cout<<"Chromatic number : "<<cn<<endl;
    
    // print the colors by which the vertex is colored
    for (int i = 0; i < v; ++i) {
        cout<<res[i]<<" ";
    }
    return 0;
}

/*
INPUT : 
 
5 7
0 1
1 3
2 3
0 2
2 4
1 4
0 4
 * */