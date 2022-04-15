#include <bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int len[], int n, int i, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return (n / len[0]) * price[0];
    }

    if (dp[i][n] != -1)
        return dp[i][n];

    int notPick = maxProfit(price, len, n, i - 1, dp);

    int pick = INT_MIN;
    if (n >= len[i])
        pick = price[i] + maxProfit(price, len, n - len[i], i, dp);

    return dp[i][n] = max(pick, notPick);
}
int cutRod(int price[], int n)
{
    int len[n];
    for (int i = 0; i < n; i++)
        len[i] = i + 1;
    int i = n - 1;
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return maxProfit(price, len, n, i, dp);
}

int main()
{

    return 0;
}