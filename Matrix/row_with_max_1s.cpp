#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
   	    int cnt_1s_in_row(vector<int> row)
    {
        int size = row.size();

        for(int i = 0; i < size; i++)
        {
            if(row[i] == 1)
            {
                return size - i;
            }
        }
        return 0;
    }
	int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
	    // code here
        int max_cnt = INT_MIN;
        vector<int> cnt_of_1;
        for(int i = 0; i < n; i++)
        {
            cnt_of_1.push_back(cnt_1s_in_row(arr[i]));
            // cout<<" i = "<<i<< " cnt : "<<cnt_1s_in_row(arr[i])<<endl;
            max_cnt = max(max_cnt, cnt_1s_in_row(arr[i]));
        }
        for (int i = 0; i < cnt_of_1.size(); i++)
        {
            if(cnt_of_1[i] == max_cnt && max_cnt != 0){
                return i;
            }
        }
        return -1;
	}
};
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    Solution s1;
    cout<<s1.cnt_1s_in_row(arr)<<endl;
    return 0;
}