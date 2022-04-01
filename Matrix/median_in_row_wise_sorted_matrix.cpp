#include <bits/stdc++.h>
using namespace std;
class Solution{   
    int countSmallerThenEqualToMid(vector<int> &row, int mid)
    {
        int l = 0, h = row.size() - 1;
        while(l <= h){
            int md = (l + h)>>1;
            if(row[md] <= mid)
            {
                l = md + 1;
            }else{
                h = md - 1;
            }
        }
        return l;
    }
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
        int low = 1;
        int high = 1e9;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            int cnt = 0;
            
            for(int i = 0; i < n; i++)
            {
                cnt += countSmallerThenEqualToMid(matrix[i], mid);
            }
            
            if(cnt <= (n*m)/2) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
} 