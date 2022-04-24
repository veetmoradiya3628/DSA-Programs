#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int LCS(string x, string y, int n, int m)
{
    // base condition
    if(n == 0 || m == 0)
        return 0;

    if(t[n][m] != -1)
    {
        return t[n][m];
    }

    // choice diagram
    if(x[n - 1] == y[m - 1])
        return t[n][m] = 1 + LCS(x, y, n - 1, m - 1);
    else
        return t[n][m] = max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1));
}
int main()
{
    string x, y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();
    memset(t, -1, sizeof(t));
    cout<<LCS(x, y, n, m)<<endl;
    return 0;
}