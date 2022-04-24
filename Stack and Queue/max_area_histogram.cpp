#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
        //Function to find largest rectangular area possible in a given histogram.
        long long getMaxArea(long long arr[], int n)
        {
            // Your code here
            vector<long long> left , right , area;
            stack<pair<long long , long long>>s;
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
            long long ans = INT_MIN;
            for(int i = 0 ;i <n;i++){
                long x = left[i] * arr[i];
                ans = x > ans ? x : ans;
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