#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int dp[1001][1001];
    int solve(int n, int a[], int s){
        if(n == -1)
        {
            if(s == 0)
                return 1;
            return 0;
        }
        if(s < 0)
            return 0;

        if(s == 0)
            return 1;
        
        if(dp[n][s] != -1)
            return dp[n][s];

        return dp[n][s] = solve(n - 1, a, s - a[n]) || solve(n - 1, a, s);
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }

        if(sum & 1)
            return 0;

        sum = sum / 2;
        dp[N][sum];
        memset(dp, -1, sizeof(dp));
        return solve(N - 1, arr, sum);
    }
};
int main()
{

    return 0;
}