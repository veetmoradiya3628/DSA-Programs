#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        long long min_val = LLONG_MAX;
        for(int i = 0; i <= (n - m); i++)
        {
            if((a[m - 1 + i] - a[i]) < min_val){
                min_val = a[m - 1 + i] - a[i];   
            }
        }
        return min_val;
    }   
};
int main()
{

    return 0;
}