#include <bits/stdc++.h>
using namespace std;
/*
Input:  9 6
        7 4 98
        5 9 72
        4 6 10
        2 8 22
        9 7 17
        3 1 66
Output: 3
        2 8 22
        3 1 66
        5 6 10
*/

class Solution
{
public:
    vector<int> in, out, weight;
    int ans;
    int dfs(int x)
    {
        if (out[x] == 0 && in[x])
        {
            return x;
        }
        if (weight[x] < ans)
            ans = weight[x];
        return dfs(out[x]);
    }
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> c)
    {
        // code here
        vector<vector<int>> res;
        in.resize(1001, 0);
        out.resize(1001, 0);
        weight.resize(1001, 0);
        int i = 0;
        while (i < p)
        {
            int q = a[i], h = b[i], t = c[i];
            out[q] = h;
            weight[q] = t;
            in[h] = q;
            i++;
        }
        for (int j = 1; j <= n; ++j)
        {
            if (in[j] == 0 && out[j])
            {
                ans = INT_MAX;
                int w = dfs(j);

                // We put the details of component
                // in final output array
                res.push_back({j, w, ans});
            }
        }
        return res;
    }
};
int main()
{

    return 0;
}