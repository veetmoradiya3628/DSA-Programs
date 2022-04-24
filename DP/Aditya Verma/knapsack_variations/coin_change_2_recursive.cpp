#include<bits/stdc++.h>
using namespace std;
int minCoins(int coins[], int n, int sum)
{
    // base case
    if(sum == 0) return 0;

    // initialize result
    int res = INT_MAX;

    // try every coin that has smaller value then sum
    for (int i = 0; i < n; i++)
    {
        if(coins[i] <= sum)
        {
            int sub_res = minCoins(coins, n, sum - coins[i]);
            if(sub_res != INT_MAX && sub_res + 1 < res)
            {
                res = sub_res + 1;
            }
        }
    }
    return res;
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