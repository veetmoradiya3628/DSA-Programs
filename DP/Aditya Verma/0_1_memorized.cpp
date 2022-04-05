#include<bits/stdc++.h>
using namespace std;
int t[1002][1002];
int knapsack(int wt[], int val[], int W, int n)
{
    if(n == 0 || W == 0)
        return 0;
    if(t[n][W] != -1)
    {
        return t[n][W];
    }
    if(wt[n - 1] <= W)
    {
        return t[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),
                    knapsack(wt, val, W, n - 1));
    }else if(wt[n - 1] > W)
        return t[n][W] = knapsack(wt, val, W, n - 1);
}
int main()
{
    memset(t, -1, sizeof(t));
    return 0;
}