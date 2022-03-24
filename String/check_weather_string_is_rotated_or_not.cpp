#include <bits/stdc++.h>
using namespace std;
/*
 * Algorithm - 1:
    1. Create a temp string and store concatenation of str1 to
       str1 in temp.
                          temp = str1.str1
    2. If str2 is a substring of temp then str1 and str2 are
       rotations of each other.

    Example:
                     str1 = "ABACD"
                     str2 = "CDABA"

     temp = str1.str1 = "ABACDABACD"
     Since str2 is a substring of temp, str1 and str2 are
     rotations of each other
 */
bool areRotations(string str1, string str2)
{
    /* Check if sizes of two strings are same */
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}
/*
 * Algorithm: 2
    1. If the size of both the strings is not equal, then it can never be possible.
    2. Push the original string into a queue q1.
    3. Push the string to be checked inside another queue q2.
    4. Keep popping q2‘s and pushing it back into it till the number of such operations are less than the size of the string.
    5. If q2 becomes equal to q1 at any point during these operations, it is possible. Else not.
*/
bool check_rotation(string s, string goal)
{
    if (s.size() != goal.size())
        ;
    queue<char> q1;
    for (char & i : s) {
        q1.push(i);
    }
    queue<char> q2;
    for (char & i : goal) {
        q2.push(i);
    }
    int k = goal.size();
    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}

int main()
{
    return 0;
}