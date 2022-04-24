#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
1. Find first and last positions of an element in a sorted array
2. Find a Fixed Point (Value equal to index) in a given array
3. Search in a rotated sorted array
4. square root of an integer
5. Find minimum and maximum element in an array
6. Optimum location of point to minimize total distance                             - Later on
7. Find the repeating and the missing
8. find majority element                                                            - Moores voting algorithm
9. Searching in an array where adjacent differ by at most k
10. find a pair with a given difference
11. find four elements that sum to a given value
12. maximum sum such that no 2 elements are adjacent
13. Count triplet with sum smaller than a given value
14. merge 2 sorted arrays
15. print all subarrays with 0 sum
16. Product array Puzzle
17. Sort array according to count of set bits
18. minimum no. of swaps required to sort the array
19. 

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
pair<long long, long long> getMinMax(long long a[], int n)
{
    long long min_val = LLONG_MAX;
    long long max_val = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        min_val = min(min_val, a[i]);
        max_val = max(max_val, a[i]);
    }
    return make_pair(min_val, max_val);
}

// 7. Find the repeating and the missing
int *findTwoElement(int *arr, int n)
{
    int a, b;
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] < 0)
        {
            a = abs(arr[i]);
        }
        else
        {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            b = i + 1;
            break;
        }
    }
    int *v = new int[2];
    v[0] = a;
    v[1] = b;
    return v;
}

// 8. find majority element - Moores voting algorithm

int majorityElement(int arr[], int size)
{
    int res = 0, count = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[res] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[res] == arr[i])
        {
            count++;
        }
    }
    if (count <= size / 2)
    {
        return -1;
    }
    return arr[res];
}

// 9. Searching in an array where adjacent differ by at most k
int search(int arr[], int n, int x, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (n == 1 && arr[0] == x)
        {
            return 0;
        }
        if (arr[i] == x && n > 1)
        {
            if (i == 0 && abs(arr[i] - arr[i + 1]) <= k)
            {
                return i;
            }
            else if (i == n - 1 && abs(arr[i] - arr[i - 1]) <= k)
            {
                return i;
            }
            else
            {
                if (arr[i] == x && abs(arr[i] - arr[i - 1]) <= k && abs(arr[i] - arr[i + 1]) <= k)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}

// 10. find a pair with a given difference
bool findPair(int arr[], int size, int n)
{
    unordered_map<int, int> mp;
    int f = -1;
    for (int i = 0; i < size; i++)
    {
        mp[arr[i]] = 1;
    }
    for (int i = 0; i < size; i++)
    {
        if (mp[arr[i] + n])
        {
            f = 1;
            break;
        }
    }
    if (f == -1)
    {
        return false;
    }
    return true;
}

// 11. find four elements that sum to a given value

vector<vector<int>> fourSum(vector<int> &a, int k)
{
    // Your code goes here
    if (a.size() < 4)
        return {};
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 3; ++i)
    {

        if (a[i] > 0 && a[i] > k)
            break;

        if (i > 0 && a[i] == a[i - 1])
            continue;
        for (int j = i + 1; j < a.size() - 2; ++j)
        {

            if (j > i + 1 && a[j] == a[j - 1])
                continue;

            int left = j + 1;
            int right = a.size() - 1;
            while (left < right)
            {
                int old_l = left;
                int old_r = right;

                int sum = a[i] + a[j] + a[left] + a[right];
                if (sum == k)
                {

                    ans.push_back({a[i], a[j], a[left], a[right]});

                    while (left < right && a[left] == a[old_l])
                        left++;
                    while (left < right && a[right] == a[old_r])
                        right--;
                }
                else if (sum > k)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
    return ans;
}

// 12. maximum sum such that no 2 elements are adjacent

/*

class Solution
{
    public:
    int dp[10001];
    int solve(int i, int a[]){
        if(i<=-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int op1 = a[i] + solve(i-2, a);
        int op2 = solve(i-1, a);
        return dp[i] = max(op1, op2);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n-1, arr);
    }
};

*/

// 13. Count triplet with sum smaller than a given value

long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    sort(arr, arr + n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int start = i + 1, end = n - 1;
        while (start < end)
        {
            int s = arr[i] + arr[start] + arr[end];
            if (s < sum)
            {
                count += (end - start);
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    return count;
}

// 14. merge 2 sorted arrays

class Solution
{
    int nextGap(int gap)
    {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    }

public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int i, j, gap = n + m;
        for (gap = nextGap(gap);
             gap > 0; gap = nextGap(gap))
        {
            for (i = 0; i + gap < n; i++)
                if (arr1[i] > arr1[i + gap])
                    swap(arr1[i], arr1[i + gap]);

            for (j = gap > n ? gap - n : 0;
                 i < n && j < m;
                 i++, j++)
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);

            if (j < m)
            {
                for (j = 0; j + gap < m; j++)
                    if (arr2[j] > arr2[j + gap])
                        swap(arr2[j], arr2[j + gap]);
            }
        }
    }
};

// 15. print all subarrays with 0 sum
// Function to count subarrays with sum equal to 0.
ll findSubarray(vector<ll> arr, int n)
{
    map<long long, long long> cnt;
    long long preSum = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        cnt[preSum]++;
    }
    long long ans = 0;
    map<long long, long long>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); it++)
    {
        int c = it->second;
        ans += (c * (c - 1)) / 2;
        if (it->first == 0)
        {
            ans += it->second;
        }
    }
    return ans;
}

// 16. Product array Puzzle

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> l(n), r(n);
    l[0] = 1;
    r[n - 1] = 1;

    for (int i = 1; i < n; i++)
    {
        l[i] = l[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = r[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = l[i] * r[i];
    }
    return nums;
}

// 17. Sort array according to count of set bits

/*
int count_bits(int n)
{
    int count = 0;
    for (; n; count++)
        n = n & (n - 1);

    return count;
}

class Solution
{
public:
    static int cmp(int a, int b)
    {
        int i = count_bits(a);
        int j = count_bits(b);

        if (i <= j)
            return 0;
        return 1;
    }

    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, cmp);
    }
};

*/

// 18. minimum no. of swaps required to sort the array

int minSwaps(vector<int> &nums)
{
    // Code here
    vector<pair<int, int>> V(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        V[i] = {nums[i], i};
    }
    sort(V.begin(), V.end());
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (V[i].second == i)
            continue;
        else
        {
            count++;
            swap(V[i], V[V[i].second]);
            i--;
        }
    }
    return count;
}
int main()
{

    return 0;
}
