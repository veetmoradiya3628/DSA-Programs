#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int romanToDecimal(string &str)
    {
        // code here
        unordered_map<char, int> mpp;
        mpp['V'] = 5;
        mpp['I'] = 1;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        int n = str.size();
        int ans = 0;
        int prev = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (mpp[str[i]] < prev)
            {
                ans -= mpp[str[i]];
            }
            else
            {
                ans += mpp[str[i]];
            }
            prev = mpp[str[i]];
        }
        return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}