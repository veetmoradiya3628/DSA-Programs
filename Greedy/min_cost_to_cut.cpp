#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t-->0)
    {
        int m, n;
        cin>>m>>n;
        m--;
        n--;
        int x[m];
        int y[n];
        for (int i = 0; i < m; i++)
        {
            cin>>x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>y[i];
        }
        sort(x, x+m, greater<int>());
        sort(y, y+n, greater<int>());

        int horizontal_cnt = 1;
        int vertical_cnt = 1;

        int answer = 0;
        int i = 0;
        int j = 0;
        while (i<m && j<n)
        {
            if(x[i] > y[j])
            {
                answer += x[i] * vertical_cnt;
                horizontal_cnt++;
                i++;
            }else{
                answer += y[j] * horizontal_cnt;
                vertical_cnt++;
                j++;
            }
        }
        while (i < m)
        {
            answer += x[i] * vertical_cnt;
            i++;
        }
        while (j < n)
        {
            answer += y[j] * horizontal_cnt;
            j++;
        }
        
        cout<<answer<<endl;
    }
    
    return 0;
}