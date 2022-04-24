// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
           if(S<=9 && D==1) {return to_string(S);}
      
      if(S>9 && D==1)  return  to_string(-1);
      
      vector<int> v(D,0);
      v[0]=1;
      S--;
      
      for(int i=D-1; i>0; i--)
      {
          if(S==0) break;
          else if(S>0 && S<=9){
              v[i]=S;
              S=0;
              break;
          }
          else if(S>9)
          {
              v[i]=9;
              S-=9;
          }
          
      }
      
      if(S!=0)
      {
          if(S+ v[0]<=9)  v[0]+=S;
          else return  to_string(-1);;
      }
      
       string ans = "";
      for(int i = 0; i < v.size(); i++){
          ans += to_string(v[i]);
      }
      return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends