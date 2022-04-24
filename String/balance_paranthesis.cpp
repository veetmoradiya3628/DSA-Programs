#include <bits/stdc++.h>
using namespace std;
bool ispar(string x)
{
    // Your code here
    stack<char> stk;
    for (int i = 0; i < x.size(); ++i)
    {
        char ch = x[i];
        if (ch == '[' || ch == '{' || ch == '(')
        {
            stk.push(ch);
        }
        else if (ch == ']')
        {
            if (stk.empty() || stk.top() != '[')
            {
                return false;
            }
            else if (stk.top() == '[')
            {
                stk.pop();
            }
        }
        else if (ch == '}')
        {
            if (stk.empty() || stk.top() != '{')
            {
                return false;
            }
            else if (stk.top() == '{')
            {
                stk.pop();
            }
        }
        else if (ch == ')')
        {
            if (stk.empty() || stk.top() != '(')
            {
                return false;
            }
            else if (stk.top() == '(')
            {
                stk.pop();
            }
        }
    }
    return stk.empty();
}
int main()
{

    return 0;
}