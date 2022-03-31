#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
int minFlips (string s)
{
    // your code here
    int cnt_1 = 0, cnt_2 = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(i & 1 && s[i] == '0') cnt_1++;
        if(i % 2 == 0 && s[i] == '1') cnt_1++;
        
        if(i & 1 && s[i] == '1') cnt_2++;
        if(i % 2 == 0 && s[i] == '0') cnt_2++;
    }
    return min(cnt_1, cnt_2);
}