#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        if(A.length() != B.length())
            return -1;
        
        int arr[256] = {0};
        
        for(int i = 0; i < A.length(); i++)
        {
            arr[A[i]]++;
            arr[B[i]]--;
        }
        for(int i = 0; i < 256; i++)
        {
            if(arr[i] != 0)
                return -1;
        }
        
        int res = 0;
        
        int p1 = A.length() - 1;
        int p2 = B.length() - 1;
        
        while(p1 >= 0){
            if(A[p1] != B[p2]){
                res++;
            }else{
                p2--;
            }
            p1--;
        }
        
        return res;
    }
};
int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}