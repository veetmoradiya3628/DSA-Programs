#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}
int countRev (string s)
{
    // your code here
    if(s.length() & 1) return -1;
    else{
        stack<char> st;
        int close_cnt = 0;
        int open_cnt = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            
            if(ch == '{')
            {
                st.push(ch);
                open_cnt++;
            }else if(ch == '}' && !st.empty() && st.top() == '{')
            {
                st.pop();
                open_cnt--;
            }
            else{
                close_cnt++;
            }
        }
        
        if(open_cnt & 1)
        {
            open_cnt = (open_cnt)/2 + 1;
        }else{
            open_cnt = open_cnt / 2;
        }
        
        if(close_cnt & 1)
        {
            close_cnt = (close_cnt)/2 + 1;
        }else{
            close_cnt = close_cnt / 2;
        }
        
        return open_cnt + close_cnt;
    }
}