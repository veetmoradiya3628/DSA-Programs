#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int> ans;
        stack<pair<int, int>> stk;
        for(int i = 0; i<n; i++)
        {
            if(stk.size()==0){
                ans.push_back(-1);
            }else if(stk.size() > 0 && stk.top().first > price[i])
            {
                ans.push_back(stk.top().second);
            }else if(stk.size() > 0 && stk.top().first <= price[i]){
                while (stk.size() > 0 && stk.top().first <= price[i])
                {
                    stk.pop();
                }
                if(stk.size()==0)
                {
                    ans.push_back(-1);
                }else{
                    ans.push_back(stk.top().second);
                }
            }
            stk.push({price[i], i});
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = i - ans[i];
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    return 0;
}