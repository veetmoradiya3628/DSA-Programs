#include <bits/stdc++.h>
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
int cnt_of_subset_with_given_diff(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return cnt_of_subset_sum(arr, n, (diff + sum) / 2);
}
int findTargetSumWays(vector<int> &A, int target)
{
    // Your code here
    int arr[A.size()];
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        arr[i] = A[i];
        sum += A[i];
    }
    return cnt_of_subset_with_given_diff(arr, A.size(), target);
}
int main()
{

    return 0;
}