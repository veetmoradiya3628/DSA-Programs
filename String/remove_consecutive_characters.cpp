#include <bits/stdc++.h> 
using namespace std; 
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        int n = S.length();
        string res;
        
        for(int i = 0; i < n; i++)
        {
            if(i < n - 1 && S[i] == S[i + 1])
                continue;
            else
                res += S[i];
        }        
        return res;
    }
};
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 