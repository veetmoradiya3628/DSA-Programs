#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int N;
        cin >> N;
        long int K;
        cin >> K;
        string str;
        cin >> str;

        int cnt = 0;
        for (int i = 0, j = N - 1; i < j; i++, j--)
        {
            if (str[i] != str[j])
            {
                cnt++;
            }
        }
        if (cnt <= K)
        {
            if (N % 2 == 1)
            {
                cout << "yes" << endl;
            }else if((K-cnt)%2==0){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
        else{
            cout << "no" << endl;
        }
    }
}