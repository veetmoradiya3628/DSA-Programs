#include<bits/stdc++.h>
using namespace std;
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	     vector<int> v;
        priority_queue<int> p(k, 0);
        for(int i=0; i<n; i++)
        {
            p.push(arr[i]);
        }
       for(int i=0; i<k; i++)
       {
           int x=p.top();
           v.push_back(x);
           p.pop();
       }
        return v;
	}
int main()
{

    return 0;
}