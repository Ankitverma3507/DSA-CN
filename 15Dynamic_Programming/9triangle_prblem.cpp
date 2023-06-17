#include <bits/stdc++.h>
using namespace std;

//////////////////////-------------------->>>>>>>>>>>>>>>>>>memoization
int f(int i, int j, vector<vector<int>> &triangle, int n,
      vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[n - 1][j];

    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + f(i + 1, j, triangle, n, dp);
    int diag = triangle[i][j] + f(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diag);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, triangle, n, dp);
}

//////////////////////-------------------->>>>>>>>>>>>>>>>>>tabbulation


int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    for (int row = n - 2; row >= 0; row--)
    {
        for (int col = row; col >= 0; col--)
        {
            int down = triangle[row][col] + dp[row + 1][col];
            int diag = triangle[row][col] + dp[row + 1][col + 1];

            dp[row][col] = min(down, diag);
        }
    }
    return dp[0][0];
}

//////////////////////-------------------->>>>>>>>>>>>>>>>>>Space Optimisation

#include <bits/stdc++.h>

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    vector<int> front(n, 0), cur(n, 0);

    for (int j = 0; j < n; j++)
    {
        front[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {

            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];

            cur[j] = min(down, diagonal);
        }
        front = cur;
    }

    return front[0];
}