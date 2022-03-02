#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, n = pushed.size();
        for(int num : pushed){
            st.push(num);
            while (!st.empty() && st.top() == popped[i])
            {
                st.pop();
                ++i;
            }
        }
        return i == n;
    }
};

int main()
{
    return 0;
}