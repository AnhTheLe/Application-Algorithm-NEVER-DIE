// Dao Trong Hoan
// 20204974
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    // dp[i][j] represents the number of consecutive black cells from (i, j) to (i, k)
    vector<vector<int>> dp(n, vector<int>(m));

    // fill the dp table for the first column
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = grid[i][0];
    }

    // fill the dp table for the rest of the columns
    for (int j = 1; j < m; j++) // j cot
    {
        for (int i = 0; i < n; i++) // i hang
        {
            if (grid[i][j] == 1) // Nếu ví trị i, j là 1 thì dp[i][j] = dp[i][j - 1] + 1
            {
                dp[i][j] = dp[i][j - 1] + 1; 
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int max_area = 0;

    // find the largest rectangle using the dp table
    for (int j = 0; j < m; j++) {
        vector<int> height(n);

        for (int i = 0; i < n; i++) {
            height[i] = dp[i][j];
        }
        // use the largest rectangle in histogram algorithm to find the largest area
        int area = 0;
        int top = 0;
        vector<int> stk(n + 1);

        for (int i = 0; i <= n; i++) {
            while (top > 0 && height[stk[top-1]] >= height[i]) {
                int h = height[stk[top-1]];
                top--;
                int w = (top == 0) ? i : i - stk[top-1] - 1;
                area = max(area, h*w);
                cout<< "area: " << area << endl;
            }
            stk[top++] = i;
        }

        max_area = max(max_area, area);
    }

    cout << max_area << endl;

    return 0;
}
