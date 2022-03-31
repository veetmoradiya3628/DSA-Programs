#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        int mini = INT_MAX;
        if(v.size() == 0) return "";
        
        string c = v[0];
        
        for(int i = 1; i < v.size(); i++)
        {
            int j = 0, k = 0;
            int a = 0;
            while(j < c.size() && k < v[i].size())
            {
                if(c[j] == v[i][k]) a++;
                else break;
                j++;
                k++;
            }
            mini = min(mini, a);
        }
        return c.substr(0, mini);
    }
};
int main()
{

    return 0;
}