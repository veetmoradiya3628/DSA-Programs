#include <bits/stdc++.h>
using namespace std;
class Solution{
    int minEle;
    stack<int> s;
    stack<int> ss;
public:
    
    /*returns min element from stack*/
    int getMin(){
        if(ss.size()==0)
            return -1;
        return ss.top();
    }
       
    /*returns popped element from stack*/
    int pop(){
        if(s.size()==0)
            return -1;
        int ans = s.top();
        s.pop();
        if(ss.top()==ans)
        {
            ss.pop();
        }
            
        return ans;
    }
       
    /*push element x into the stack*/
    void push(int x){
        s.push(x);
        if(ss.size()==0 || ss.top() >= x)
        {
            ss.push(x);
        }
    }
};

int main()
{
    
    return 0;
}