#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
class Solution
{
    int largestRectangle(int heights[], int n)
    {
        stack<int> st;
        int currArea = 0, maxArea = 0;
        int i = 0;
        for (i = 0; i < n; i++)
        {

            while (!st.empty() && heights[st.top()] >= heights[i])
            {

                int tp = st.top();
                st.pop();
                currArea = (st.empty() ? (i * heights[tp]) : (i - st.top() - 1) * heights[tp]);
                maxArea = max(maxArea, currArea);
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int tp = st.top();
            st.pop();
            currArea = (st.empty() ? (i * heights[tp]) : (i - st.top() - 1) * heights[tp]);
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }

public:
    int maxArea(int arr[MAX][MAX], int n, int m)
    {
        // Your code here
        int area = largestRectangle(arr[0], m);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 0)
                    arr[i][j] = 0;
                else
                {
                    arr[i][j] += arr[i - 1][j];
                }
            }
            area = max(area, largestRectangle(arr[i], m));
        }

        return area;
    }
};
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}