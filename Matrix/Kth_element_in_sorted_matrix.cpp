#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
      return 0;
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int left = 0, right = 10000;
 while(left<=right)
 {
     int mid = (left + right)/2;
      int count = 0;
     for(int i = 0; i<n;i++)
     {
         int l =0,r = n-1;
        
         while(l<=r)
         {
             int m=(l+r)/2;
             if(mat[i][m]>mid)
             {
                 r = m-1;
             }
             else
             {
                 l = m + 1;
             }
         }
         
         count+=l;
         
     }
     
     if(count<=k-1)
     {
        left = mid + 1;
     }
     else
     {
         right = mid - 1;
     }
 } 
 return left;
}
