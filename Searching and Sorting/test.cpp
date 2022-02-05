#include <bits/stdc++.h>
using namespace std;
int firstOccurance(int low, int high, int arr[], int n, int x){
    if(low>high) 
        return -1;
    int mid = (low + high)/2;
    if(x > arr[mid]){
        return firstOccurance(mid + 1, high, arr, n, x);
    }else if(x<arr[mid]){
        return firstOccurance(low, mid-1, arr, n, x);
    }else{
        if(mid==0 || arr[mid-1]!=arr[mid]){
            return mid;
        }else{
            return firstOccurance(low, mid-1, arr, n, x);
        }
    }
}
int lastOccurance(int low, int high, int arr[], int n, int x){
     if(low>high) 
        return -1;
    int mid = (low + high)/2;
    if(x > arr[mid]){
        return lastOccurance(mid + 1, high, arr, n, x);
    }else if(x<arr[mid]){
        return lastOccurance(low, mid-1, arr, n, x);
    }else{
        if(mid==0 || arr[mid-1]!=arr[mid]){
            return mid;
        }else{
            return lastOccurance(low, mid-1, arr, n, x);
        }
    }
}
vector<int> find(int arr[], int n, int x)
{
    vector<int> ans;
    int fo = firstOccurance(0, n-1, arr, n, x);
    lastOccurance(arr, n, x, ans);
    return ans;
}
int main()
{

    return 0;
}