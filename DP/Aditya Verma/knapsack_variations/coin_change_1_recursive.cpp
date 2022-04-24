#include<bits/stdc++.h>
using namespace std;
int count_ways(int arr[], int n, int sum)
{
    // if no coin still there is one solution that is do not include any coin
    if(sum == 0)
    {
        return 1;
    }

    // if n < 0 - no solution exists
    if(sum < 0)
        return 0;

    // if there are no coin and sum is greater than 0, then no solution exists
    if(n <= 0 && sum >= 1)
        return 0;

    return count_ways(arr, n - 1, sum) + count_ways(arr, n, sum - arr[n - 1]);
    
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

    cout<<count_ways(arr, n, sum)<<endl;
    return 0;
}