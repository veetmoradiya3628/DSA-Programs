#include <bits/stdc++.h>
using namespace std;
int isPalindrome(string S)
{
    // Your code goes here
    int len = S.size();
    for (int i = 0; i < len/2; ++i) {
        if(S[i] != S[len - i - 1]){
            return 0;
        }
    }
    return 1;
}

int main()
{

    return 0;
}