#include<bits/stdc++.h>
using namespace std;
void print_all_perm(int l, int r, string str)
{
    if(l == r)
    {
        cout<<str<<endl;
        return;
    }else{
        for (int i = l; i <= r; i++)
        {
            swap(str[i], str[l]);
            print_all_perm(l + 1, r, str);
            swap(str[i], str[l]);
        }
    }
}
int main()
{
    string str;
    cin>>str;
    int n = str.length();
    print_all_perm(0, n-1, str);
    return 0;
}