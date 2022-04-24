// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();
        
        if(len1 != len2) return false;
        
        int m1[256] = {0};
        int m2[256] = {0};
        
        for(int i = 0; i < len1; i++)
        {
            if(!m1[str1[i]] && !m2[str2[i]]){
                m1[str1[i]] = str2[i];
                m2[str2[i]] = str1[i];
            }else if(m1[str1[i]] != str2[i]){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
} 