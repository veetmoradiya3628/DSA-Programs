#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int editDistance(string word1, string word2) {
        // Code here
         int n1=word1.size();
        int n2=word2.size();
        int dp[n1+1][n2+1];
        for(int i=0;i<n1+1;i++)
        {
            dp[i][0]=i;
        }
        for(int i=0;i<n2+1;i++)
        {
            dp[0][i]=i;
        }
        for(int i=1;i<n1+1;i++)
        {
            for(int j=1;j<n2+1;j++)
            {
                 if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                } 
                else 
                {
                  dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        return dp[n1][n2];
    }
};
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}