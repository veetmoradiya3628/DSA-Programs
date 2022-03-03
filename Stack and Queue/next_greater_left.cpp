#include <bits/stdc++.h>
using namespace std;
vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> ans;
    stack<long long> stk;
    for(int i = 0; i<n; i++)
    {
        if(stk.size()==0){
            ans.push_back(-1);
        }else if(stk.size() > 0 && stk.top() > arr[i])
        {
            ans.push_back(stk.top());
        }else if(stk.size() > 0 && stk.top() <= arr[i]){
            while (stk.size() > 0 && stk.top() <= arr[i])
            {
                stk.pop();
            }
            if(stk.size()==0)
            {
                ans.push_back(-1);
            }else{
                ans.push_back(stk.top());
            }
        }
        stk.push(arr[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    vector<long long> ans = nextLargerElement(arr, n);
    for(long long val : ans)
        cout<<val<<" ";
    cout<<endl;
    return 0;
}