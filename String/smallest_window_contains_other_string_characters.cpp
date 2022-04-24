#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string smallestWindow(string s, string p)
    {
        // Your code here
        int shash[26] = {0};
        int phash[26] = {0};
        for (int i = 0; i < p.length(); i++)
            phash[p[i] - 'a']++;
        int len = p.length();
        int res = 100007;
        int count = 0, i = 0, j = 0;
        string str;
        int start, end;
        while (j < s.length())
        {
            char ch = s[j];
            if (phash[ch - 'a'] > 0 and shash[ch - 'a'] < phash[ch - 'a'])
            {
                shash[ch - 'a']++;
                count++;
            }
            else
                shash[ch - 'a']++;
            if (count == len)
            {
                while (count == len)
                {
                    if ((j - i + 1) < res)
                    {
                        res = j - i + 1;
                        start = i;
                        end = j;
                    }
                    if (shash[s[i] - 'a'] - 1 < phash[s[i] - 'a'])
                        count--;
                    shash[s[i] - 'a']--;
                    i++;
                }
            }
            j++;
        }
        if (res == 100007)
            str = "-1";
        else
        {
            for (int i = start; i <= end; i++)
                str += s[i];
        }
        return str;
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
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
}