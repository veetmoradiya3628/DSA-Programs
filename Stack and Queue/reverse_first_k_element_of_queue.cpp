#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s;
    for (int i = 1; i <= k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    int n = q.size();
    for (int i = 1; i <= n-k ; i++)
    {
        int x = q.front();
        q.pop();
        q.push(x);
    }
    return q;
}
int main()
{

    return 0;
}