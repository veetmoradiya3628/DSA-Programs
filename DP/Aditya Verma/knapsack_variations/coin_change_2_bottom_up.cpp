#include<bits/stdc++.h>
using namespace std;
int minCoins(int coins[], int n, int sum)
{
    // dp[i] stores min no. of coins required for i value, so dp[sum] will have answer
    int dp[sum + 1];

    // Base case if sum = 0
    dp[0] = 0;

    // Initialize all value as Infinite
    for (int i = 1; i <= sum; i++)
    {
        dp[i] = INT_MAX;
    }
    
    // compute min coins required for all values from 1 to sum
    for (int i = 1; i <= sum; i++)
    {
        // go through all coins smaller than i
        for (int j = 0; j < n; j++)
        {
            if(coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]];
                if(sub_res != INT_MAX && sub_res + 1 < dp[i])
                {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }

    if(dp[sum] == INT_MAX)
        return -1;
    
    return dp[sum];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<minCoins(arr, n, sum);
    return 0;
}