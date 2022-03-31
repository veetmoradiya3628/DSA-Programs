#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        map<string, vector<string>> mpp;

        for (int i = 0; i < string_list.size(); i++)
        {
            string s = string_list[i];
            sort(s.begin(), s.end());
            mpp[s].push_back(string_list[i]);
        }
        
        vector<vector<string>> ans(mpp.size());

        int idx = 0;

        for(auto x : mpp){
            auto v = x.second;

            for (int i = 0; i < v.size(); i++)
            {
                ans[idx].push_back(v[i]);                
            }
            idx++;
        }

        return ans;
    }
};
int main()
{

    return 0;
}