//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

struct triplets
{
    int value , aPos , vPos ;
    triplets(int val , int ap , int vp)
    {
        value = val;
        aPos = ap;
        vPos = vp;
    }
};

struct cmp{
    bool operator()(triplets &t1 , triplets &t2)
    {
        return t1.value > t2.value ;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue< triplets , vector<triplets> , cmp > pq;
        vector<int> v;
        for(int i=0 ; i<arr.size() ; i++)
        {
            triplets t(arr[i][0],i,0);
            pq.push(t);
        }
        while(!pq.empty())
        {
            triplets res = pq.top(); 
            pq.pop();
            int val = res.value , ap = res.aPos , vp = res.vPos ;
            v.push_back(val);
            if(vp+1 < arr[ap].size())
            {
                triplets t(arr[ap][vp+1],ap,vp+1);
                pq.push(t);
            }
                
                
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}