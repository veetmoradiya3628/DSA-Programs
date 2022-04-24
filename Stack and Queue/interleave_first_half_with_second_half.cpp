#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);

    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    int n = 10;
    stack<int> st;

    for (int i = 0; i < n/2; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < n/2; i++)
    {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < n/2; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}