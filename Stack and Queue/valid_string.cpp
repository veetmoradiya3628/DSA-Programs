#include <bits/stdc++.h>
using namespace std;
int findMaxLen(string s)
{
    stack<int> st;

    st.push(-1);
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(i);

        else
        {
            st.pop();
            if (st.size() == 0)
                st.push(i);

            else
                ans = max(ans, i - st.top());
        }
    }
    return ans;
}
int main()
{

    return 0;
}