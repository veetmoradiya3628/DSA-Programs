#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
    // Code here
	    vector<vector<int>> v;
         sort(arr.begin(), arr.end());
         int first_ele = arr[0][0], last_ele = arr[0][1];
         for(int i=1; i<arr.size(); i++)
         {
             if(arr[i][0] <= last_ele)
             {
                 last_ele = max(last_ele, arr[i][1]);
             }else{
                 v.push_back({first_ele, last_ele});
                 first_ele = arr[i][0];
                 last_ele = arr[i][1];
             }
         }
         v.push_back({first_ele, last_ele});
         return v;
}
int main()
{
	
	return 0;
}