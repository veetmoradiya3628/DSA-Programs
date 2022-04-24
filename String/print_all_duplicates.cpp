#include <bits/stdc++.h>
using namespace std;
//print all the duplicates in string
void print_duplicate(string str)
{
    map<char, int> mp;
    for (char & i : str) {
        mp[i]++;
    }
    for(auto it : mp)
        if(it.second > 1){
            cout<<it.second<<" -> count : "<<it.first<<endl;
        }
}
int main()
{
    print_duplicate("veetmoradiya");
    return 0;
}