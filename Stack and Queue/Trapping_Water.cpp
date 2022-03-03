#include <bits/stdc++.h>
using namespace std;
long long trappingWater(int arr[], int n){
    int mxl[n], mxr[n];
    mxl[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        mxl[i] = max(arr[i], mxl[i-1]);
    }
    mxr[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; --i) {
        mxr[i] = max(mxr[i+1], arr[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += min(mxl[i], mxr[i]) - arr[i];
    }
    return ans;
}
int main()
{

    return 0;
}