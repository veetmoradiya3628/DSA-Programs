#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
public:
    /*
     * Idea is good and my code but some how giving wrong answer
     *
     string findSubString(string str)
    {
        unordered_map<char, int> mpp;
        set<char> st;

        for (char & i : str) {
            st.insert(i);
        }

        int n = st.size();
        int i = 0, j = 1;
        mpp[str[i]]++;

        int cnt = 0;
        cnt++;

        int min_val = INT_MAX;

        while (i <= j && j < str.length())
        {
            if(cnt < n){
                if(mpp[str[j]] == 0) cnt++;
                mpp[str[j]]++;
                j++;
            }else if(cnt == n){
                min_val = min(min_val, j - i);
                if(mpp[str[i]] == 1) cnt--;
                mpp[str[i]]--;
                i++;
            }
        }
        while (cnt == n){
            min_val = min(min_val, j - i);
            if(mpp[str[i]] == 1) cnt--;
            mpp[str[i]]--;
            i++;
        }
        cout<<min_val<<endl;
        return to_string(min_val);
    } */

//    Someone others code and good, i will like to Dry run it
    string findSubString(string str)
    {
        set <char> s(str.begin(), str.end());
        int n = s.size();
        s.clear();
        int l = 0, r = 0, ans = INT_MAX, idx1=0, idx2=0;
        map <char,int> mp;
        while(str[r] != '\0'){
            while(str[r] != '\0' && mp.size() != n){
                mp[str[r]]++;
                r += 1;
            }
            while(mp.size() == n){
                mp[str[l]]--;
                if(mp[str[l]] == 0)
                    mp.erase(str[l]);
                l += 1;
            }
            if(r-l < ans){
                ans = r-l;
                idx1 = l;
                idx2 = r;
            }
        }
        return str.substr(idx1-1, idx2-idx1+1);
    }
};
int main()
{
    return 0;
}