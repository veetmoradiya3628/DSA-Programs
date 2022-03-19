#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    void helper( string str, int k, string& max, int ctr)
    {

    if (k == 0)
        return;
 
    int n = str.length();

    char maxm = str[ctr];
    for (int j = ctr + 1; j < n; j++) {

        if (maxm < str[j])
            maxm = str[j];
    }
 
    if (maxm != str[ctr])
        --k;

    for (int j = n-1; j >=ctr; j--) {

        if (str[j] == maxm) {

            swap(str[ctr], str[j]);

            if (str.compare(max) > 0)
                max = str;

            helper(str, k, max, ctr + 1);
 
            swap(str[ctr], str[j]);
        }
    }
    }
    public:
    string findMaximumNum(string str, int k)
    {
       // code here.
       string maxx = str;
       helper(str, k, maxx, 0);
       return maxx;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends