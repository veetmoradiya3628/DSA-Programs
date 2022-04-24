#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int zero_cnt = 0;
    int negative_cnt = 0;
    int prod = 1;
    int max_negative = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0)
        {
            zero_cnt++;
            continue;
        }
        if(arr[i] < 0){
            negative_cnt++;
            max_negative = max(max_negative, arr[i]);
        }
        prod = prod * arr[i];
    }
    if(zero_cnt == n){
        cout<<"0";
        return 0;
    }else if(negative_cnt == 1 && zero_cnt + negative_cnt == n)
    {
        cout<<"0";
        return 0;
    }else if(negative_cnt & 1){
        prod = prod / max_negative;
    }
    cout<<prod;
    return 0;
}