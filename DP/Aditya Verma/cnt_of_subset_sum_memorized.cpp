// problem with this code

#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int cnt_of_subset_sum(int arr[], int n, int idx, int sum, int cnt)
{
    // base case
    if(idx == n)
    {
        // if we get sum is equal to 0 for given subset then we can increament the cnt
        if(sum == 0)
        {
            return 1;
        }
        return 0;
    }

    if(t[n][sum] != -1)
    {
        return t[n][sum];
    } else {
        // t[n][sum] = 1;
        // include + exclude 
        t[n][sum] = cnt_of_subset_sum(arr, n, idx + 1, sum, cnt) + cnt_of_subset_sum(arr, n, idx + 1, sum - arr[idx], cnt);
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
    
    memset(t, -1, sizeof(t));    
    
    cout<<cnt_of_subset_sum(arr, n, 0, sum, 0)<<endl;
    return 0;
}