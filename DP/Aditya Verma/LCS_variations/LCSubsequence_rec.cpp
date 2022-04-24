// Q. Diff between sub-string and sub-sequence? 

#include<bits/stdc++.h>
using namespace std;
string str1, str2;
int LCSubsequence(int i, int j, int count)
{
    // base condition
    if(i == 0 || j == 0)
        return count;
    
    if(str1[i - 1] == str2[j - 1])
    {
        count = LCSubsequence(i - 1, j - 1, count + 1);
    }
    count = max(count, max(LCSubsequence(i, j - 1, 0), LCSubsequence(i - 1, j, 0)));
    return count;
}
int main()
{
    cin>>str1>>str2;
    int n = str1.length();
    int m = str2.length();

    cout<<LCSubsequence(n, m, 0)<<endl;
    return 0;
}  