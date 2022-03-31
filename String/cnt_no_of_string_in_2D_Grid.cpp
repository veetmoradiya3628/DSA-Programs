/*
Algorithm :
    1- Traverse matrix character by character and take one character as string start
    2- For each character find the string in all the four directions recursively
    3- If a string found, we increase the count
    4- When we are done with one character as start, we repeat the same process for the next character
    5- Calculate the sum of count for each character
    6- Final count will be the answer
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, string s, char ch[6][6], int size, int idx)
{
    int found  = 0;
    if(i >= 0 && j >= 0 && i < 6 && j < 6 && s[idx] == ch[i][j])
    {
        char temp = s[idx];
        ch[i][j] = 0;
        idx += 1;
        if(idx == size)
        {
            found = 1;
        }
        else{
            found += solve(i + 1, j, s, ch, size, idx);
            found += solve(i - 1, j, s, ch, size, idx);
            found += solve(i , j + 1, s, ch, size, idx);
            found += solve(i, j - 1, s, ch, size, idx);
        }
        ch[i][j] = temp;
    }
    return found;
}
int main()
{
    string str = "GEEKS";
    char ch[6][6] = {
        {'D', 'D', 'D', 'G', 'D', 'D'},
        {'B', 'B', 'D', 'E', 'B', 'S'},
        {'B', 'S', 'K', 'E', 'B', 'K'},
        {'D', 'D', 'D', 'D', 'D', 'E'},
        {'D', 'D', 'D', 'D', 'D', 'E'},
        {'D', 'D', 'D', 'D', 'D', 'G'}
    };
    int ans = 0;
    int size = 5;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            ans += solve(i, j, str, ch, size, 0);
        }
        
    }
    cout<<ans<<endl;
    return 0;
}