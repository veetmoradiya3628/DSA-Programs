#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Solution{
    int getMaxArea(vector<int> arr, int n)
    {
        // Your code here
        vector<int> left , right , area;
        stack<pair<int , int>>s;
        int pseudo_ind = -1;
        for(int i=0;i<n;i++){
            if(s.size() == 0){
                left.push_back(pseudo_ind);
            }
            else if(!s.empty() && arr[i] > s.top().first  ){
                left.push_back(s.top().second);
            }
            else if(s.size() > 0 && s.top().first >= arr[i]){
                while(s.size() > 0 && s.top().first >= arr[i]){
                    s.pop();
                }
                if(s.size() ==0)
                    left.push_back(pseudo_ind);
                else
                    left.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }

        pseudo_ind = n;
        while(!s.empty()){
            s.pop();
        }
        //NSR
        for(int i = n-1 ; i>=0 ;i--){
            if(s.size() == 0){
                right.push_back(pseudo_ind);
            }
            else if(!s.empty() && arr[i] > s.top().first  ){
                right.push_back(s.top().second);
            }
            else if(s.size() > 0 && s.top().first >= arr[i]){
                while(s.size() > 0 && s.top().first >= arr[i]){
                    s.pop();
                }
                if(s.size() ==0)
                    right.push_back(pseudo_ind);
                else
                    right.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        reverse(right.begin() , right.end());

        for(int i=0;i<n;i++){
            left[i] = right[i] - left[i] - 1;
        }
        int ans = INT_MIN;
        for(int i = 0 ;i <n;i++){
            long x = left[i] * arr[i];
            ans = x > ans ? x : ans;
        }
        return ans;
    }
public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> v;
        for (int i = 0; i < m; ++i) {
            v.push_back(M[0][i]);
        }
        int mx = getMaxArea(v, m);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(M[i][j] == 0)
                    v[j] = 0;
                else
                    v[j] = v[j] + M[i][j];
            }
            mx = max(mx, getMaxArea(v, m));
        }
        return mx;
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