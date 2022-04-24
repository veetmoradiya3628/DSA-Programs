#include <bits/stdc++.h>
using namespace std;
int coinchange(vector<int> &a, int v, int n,
               vector<vector<int>> &dp)
{
    if (v == 0)
        return dp[n][v] = 1;
    if (n == 0)
        return 0;
    if (dp[n][v] != -1)
        return dp[n][v];
    if (a[n - 1] <= v)
    {
        // Either Pick this coin or not
        return dp[n][v] = coinchange(a, v - a[n - 1], n, dp) + coinchange(a, v, n - 1, dp);
    }
    else // We have no option but to leave this coin
        return dp[n][v] = coinchange(a, v, n - 1, dp);
}
int main()
{
    int n, v;
    cin>>n>>v;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(v + 1, -1));
    int res = coinchange(a, v, n, dp);
    cout << res << endl;
    return 0;
}