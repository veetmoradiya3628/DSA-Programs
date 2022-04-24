#include<bits/stdc++.h>
using namespace std;
void func(string t, int i, int n, string s)
{
    if(i == n){
        cout<<t<<endl;
    }
    else{
        func(t, i+1, n, s);
        t += s[i];
        func(t, i+1, n, s);
    }
}
int main()
{
    string str;
    cin>>str;
    func("", 0, str.length(), str);
    return 0;
}