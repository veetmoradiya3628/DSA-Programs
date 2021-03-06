#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int coin_change(int coin[], int N, int sum)
{
    // code here
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if(i == 0)
            {
                dp[i][j] = 0;
            }
            if(j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][sum];
}
int main()
{
    int N;
    cin>>N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<coin_change(arr, N, sum)<<endl;
    return 0;
}