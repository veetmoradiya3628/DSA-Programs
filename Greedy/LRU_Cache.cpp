#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
           // code here
        list<int> l;
        int pf = 0;
        for(int i=0;i<N;++i)
        {
            if(l.size()<C)
            {
                auto it = find(l.begin(),l.end(),pages[i]);
                if(it==l.end())
                {
                    l.emplace_back(pages[i]);
                    ++pf;
                }
                else{
                    l.erase(it);
                    l.emplace_back(pages[i]);
                }
            }
            auto it = find(l.begin(),l.end(),pages[i]);
            if(it==l.end())
            {
                l.pop_front();
                l.emplace_back(pages[i]);
                ++pf;
            }
            else{
                l.erase(it);
                l.emplace_back(pages[i]);
            }
            
        }
        return pf;
    }
};
int main()
{

    return 0;
}