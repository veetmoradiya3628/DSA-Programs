#include<bits/stdc++.h>
using namespace std;

int main()
{

    // same as LCS - Top down
    string x, y;
    cin>>x>>y;
    int m = x.length();
    int n = y.length();

    int t[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if(i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if(x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else   
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }        
    }
    
    // no. of insertion 
    int no_insertion = m - t[m][n];
    int no_deletion = n - t[m][n];
    cout<<"no. of insertion : "<<no_insertion<<" no. of deletion : "<<no_deletion<<"\nTotal : "<<no_insertion + no_deletion<<endl;
    return 0;
}