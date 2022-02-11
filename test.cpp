#include <bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2)
{
    bool ans = false;
    int len = s1.length();
    for (int i = 0; i < s2.length()-len; i++)
    {
        string sub_str = s2.substr(i, i+len);
        cout<<sub_str<<endl;
    }
    return ans;
}
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<checkInclusion(s1, s2)<<endl;
    return 0;
}