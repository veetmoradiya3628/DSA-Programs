#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(n < r) return 0;
        if((n - r) < r) r = n - r;
        
        int mod = 1000000007;
        
        int dp[r + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        for(int i = 1; i<=n; i++)
        {
            for(int j = min(r, i); j>=0; j--)
            {
                dp[j] = (dp[j] + dp[j - 1])%mod;
            }
        }
        return dp[r];
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}