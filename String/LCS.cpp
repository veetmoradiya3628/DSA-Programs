#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    //Function to find the length of longest common subsequence in two strings.
    int dp[1001][1001];
    int func(int x, int y, string s1, string s2)
    {
        if(x == -1 || y == -1) return 0;
        if(dp[x][y] != -1) return dp[x][y];

        if(s1[x] == s2[y]) return dp[x][y] = 1 + func(x - 1, y - 1, s1, s2);
        int a = func(x - 1, y, s1, s2);
        int b = func(x, y - 1, s1, s2);
        return dp[x][y] = max(a, b);
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        memset(dp, -1, sizeof(dp));
        return func(x - 1, y - 1, s1, s2);
    }
};
int main()
{

    return 0;
}