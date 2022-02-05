#include <bits/stdc++.h>
using namespace std;
/*
1. Find first and last positions of an element in a sorted array
2. Find a Fixed Point (Value equal to index) in a given array
3. Search in a rotated sorted array
4. square root of an integer
5. Find minimum and maximum element in an array
6. Optimum location of point to minimize total distance                             - Later on
7. 
*/
// 1. Find first and last positions of an element in a sorted array
int firstOccurance(int low, int high, int arr[], int n, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (x > arr[mid])
    {
        return firstOccurance(mid + 1, high, arr, n, x);
    }
    else if (x < arr[mid])
    {
        return firstOccurance(low, mid - 1, arr, n, x);
    }
    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
        {
            return mid;
        }
        else
        {
            return firstOccurance(low, mid - 1, arr, n, x);
        }
    }
}
int lastOccurance(int low, int high, int arr[], int n, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (x > arr[mid])
    {
        return lastOccurance(mid + 1, high, arr, n, x);
    }
    else if (x < arr[mid])
    {
        return lastOccurance(low, mid - 1, arr, n, x);
    }
    else
    {
        if (mid == n - 1 || arr[mid + 1] != arr[mid])
        {
            return mid;
        }
        else
        {
            return lastOccurance(mid + 1, high, arr, n, x);
        }
    }
}
vector<int> find(int arr[], int n, int x)
{
    vector<int> ans;
    ans.push_back(firstOccurance(0, n - 1, arr, n, x));
    ans.push_back(lastOccurance(0, n - 1, arr, n, x));
    return ans;
}
// 2. Find a Fixed Point (Value equal to index) in a given array
vector<int> valueEqualToIndex(int arr[], int n)
{
    // code here
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == (i + 1))
        {
            ans.push_back(i + 1);
        }
    }
    return ans;
}

// 3. Search in a rotated sorted array
int search(vector<int> &nums, int target)
{
    if (nums.size() == 1)
    {
        if (nums[0] == target)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else if (nums.size() == 2)
    {
        if (nums[0] == target)
        {
            return 0;
        }
        else if (nums[1] == target)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int l = 0, h = nums.size() - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[l] < nums[mid])
            {
                if (nums[l] == target)
                {
                    return l;
                }
                if (target >= nums[l] && target < nums[mid])
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (nums[h] == target)
                {
                    return h;
                }
                if (target > nums[mid] && target <= nums[h])
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
            }
        }
    }
    return -1;
}
// 4. square root of an integer
int countSquares(int N)
{
    // code here
    return floor(sqrt(N - 1));
}
// 5. Find minimum and maximum element in an array
pair<long long, long long> getMinMax(long long a[], int n) {
    long long min_val = LLONG_MAX;
    long long max_val = LLONG_MIN;
    for(int i = 0; i<n; i++){
        min_val = min(min_val, a[i]);
        max_val = max(max_val, a[i]);
    }
    return make_pair(min_val, max_val);
}
int main()
{

    return 0;
}
