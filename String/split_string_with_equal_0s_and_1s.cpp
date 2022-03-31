#include<bits/stdc++.h>
using namespace std;
int find_equal_0s_and_1s(string str)
{
    int n = str.length();
    int cnt_0 = 0, cnt_1 = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if(str[i] == '0')
        {
            cnt_0++;
        }else if(str[i] == '1')
        {
            cnt_1++;
        }

        if(cnt_0 == cnt_1)
            cnt++;
    }
    if(cnt_0 != cnt_1)
        return -1;
    
    return cnt;
}
int main()
{
    string str;
    cin>>str;
    cout<<"no. of sub string : "<<find_equal_0s_and_1s(str)<<endl;
    return 0;
}