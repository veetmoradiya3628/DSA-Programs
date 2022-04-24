#include<bits/stdc++.h>
using namespace std;
/*
 * Two Approaches - 
 * 1) T.C : O(n), S.C : O(n)
 * 2) T.C : O(n), S.C : O(1) - Below Code
 * */
class Solution{
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int ans = 0, open = 0, close = 0, fault = 0;
        for(int i = 0; i < S.length(); i++)
        {
            if(S[i] == ']')
            {
                close++;
                fault = close - open;
            }else{
                open++;
                if(fault > 0)
                {
                    ans += fault;
                    fault--;
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}