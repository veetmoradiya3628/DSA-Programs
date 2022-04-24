// #include<bits/stdc++.h>
// using namespace std;
// int t[1001][1001];
// int LCSequence(string x, string y, int n, int m)
// {
//     // base condition
//     if(n == 0 || m == 0)
//         return 0;

//     if(t[n][m] != -1)
//     {
//         return t[n][m];
//     }

//     // choice diagram
//     if(x[n - 1] == y[m - 1])
//         return t[n][m] = 1 + LCSequence(x, y, n - 1, m - 1);
//     else
//         return t[n][m] = 0;
// }
// int main()
// {
//     string x, y;
//     cin>>x>>y;
//     int n = x.length();
//     int m = y.length();
//     memset(t, -1, sizeof(t));
//     cout<<LCSequence(x, y, n, m)<<endl;
//     return 0;
// }