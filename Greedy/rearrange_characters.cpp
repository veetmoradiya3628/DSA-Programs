// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
public:
    string rearrangeString(string s)
    {
        // code here
        int n = s.size(), max = 0;
        map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            if (max < m[s[i]])
                max = m[s[i]];
        }
        if (max > (n + 1) / 2)
            return s = "-1";
        multimap<int, char, greater<int>> mp;
        for (auto i : m)
        {
            mp.insert({i.second, i.first});
        }
        vector<char> v;
        for (auto i : mp)
        {
            char x = i.second;
            int count = i.first;
            while (count > 0)
            {
                v.push_back(x);
                count--;
            }
        }
        int l = -2;
        for (int i = 0; i < n; i++)
        {
            l += 2;
            if (l >= n)
                l = 1;
            s[l] = v[i];
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = {0};
        for (int i = 0; i < str.length(); i++)
            c[str[i] - 'a'] += 1;
        int f = 0;
        int x = (str.length() + 1) / 2;
        for (int i = 0; i < 26; i++)
        {
            if (c[i] > x)
                f = 1;
        }
        if (f)
        {
            if (str1 == "-1")
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            int a[26] = {0};
            int b[26] = {0};
            for (int i = 0; i < str.length(); i++)
                a[str[i] - 'a'] += 1;
            for (int i = 0; i < str1.length(); i++)
                b[str1[i] - 'a'] += 1;

            for (int i = 0; i < 26; i++)
                if (a[i] != b[i])
                    flag = 0;

            for (int i = 0; i < str1.length(); i++)
            {
                if (i > 0)
                    if (str1[i - 1] == str1[i])
                        flag = 0;
            }
            if (flag == 1)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
} // } Driver Code Ends