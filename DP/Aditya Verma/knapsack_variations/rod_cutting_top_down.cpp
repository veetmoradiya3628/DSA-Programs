#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int cutRod(int price[], int n)
    {
        // code here
        int length[n], i, j;
        int t[n + 1][n + 1];

        for (i = 0; i < n; i++)
            length[i] = i + 1;

        for (i = 0; i < n + 1; i++)
            for (j = 0; j < n + 1; j++)
                if (i == 0 || j == 0)
                    t[i][j] = 0;

        for (i = 1; i < n + 1; i++)
            for (j = 1; j < n + 1; j++)
            {
                if (length[i - 1] <= j)
                    t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);

                else
                    t[i][j] = t[i - 1][j];
            }
        return t[n][n];
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

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}