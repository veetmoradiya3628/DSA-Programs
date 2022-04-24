#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subSetSum(int arr[], int n, int sum)
    {
        int dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = 0;
                }
                if (j == 0)
                {
                    dp[i][j] = 1;
                }
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int min = INT_MAX;
        for (int i = sum / 2; i >= 0; i--)
        {
            if (dp[n][i] == true)
            {
                min = sum - (i * 2);
                break;
            }
        }
        return min;
    }
    int minDifference(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        return subSetSum(arr, n, sum);
    }
};
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}