#include<bits/stdc++.h>
using namespace std;
int cnt_of_subset_sum(int arr[], int n, int sum)
{
    // declaration
    int t[n + 1][sum + 1];

    // initialization
    t[0][0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        t[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        t[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if(arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            } else {
                t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
            }
        }
    }
    
    return t[n][sum];
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
    cout<<cnt_of_subset_sum(arr, n, sum)<<endl;
    return 0;
}