#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;

    vector<string> ans;
    char c1 = str[0], r1 = str[1], c2 = str[3], r2 = str[4];

    for (int i = 0; i + c1 <= c2; i++)
    {
        for (int j = 0; j + r1 <= r2; j++)
        {
            string res;
            res += (c1 + i);
            res += (r1 + j);
            
        }        
    }
    

    return 0;
}