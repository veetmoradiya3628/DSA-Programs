#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
  bool isSubsetSum(vector<int> arr, int sum){
        int n = arr.size();
        bool t[n + 1][sum + 1];
 
        for (int i = 0; i <= n; i++)
            t[i][0] = true;

        for (int i = 1; i <= sum; i++)
            t[0][i] = false;
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j < arr[i - 1])
                    t[i][j] = t[i - 1][j];
                if (j >= arr[i - 1])
                    t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
            }
        }
        
        return t[n][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if(sum % 2 != 0)
            return false;
        else 
        {
            vector<int> t_arr;
            for (int i = 0; i < N; i++)
            {
                t_arr.push_back(arr[i]);
            }
            return isSubsetSum(t_arr, sum / 2);
        }
    }
};
int main()
{

    return 0;
}