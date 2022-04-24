#include<bits/stdc++.h>
using namespace std;
int cnt_of_subset_sum(int arr[], int n, int idx, int sum, int cnt)
{
    // base case
    if(idx == n)
    {
        // if we get sum is equal to 0 for given subset then we can increament the cnt
        if(sum == 0)
        {
            cnt++;
        }
        return cnt;
    }

    // exclude
    cnt = cnt_of_subset_sum(arr, n, idx + 1, sum, cnt);
    
    // include
    cnt = cnt_of_subset_sum(arr, n, idx + 1, sum - arr[idx], cnt);

    return cnt;
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
    cout<<cnt_of_subset_sum(arr, n, 0, sum, 0)<<endl;
    return 0;
}