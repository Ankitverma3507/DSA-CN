#include <bits/stdc++.h>
using namespace std;
//////////////////////--------------------------------------->>>>>>>>>>>>>>>>>>memoization

int f(int n, int m, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
//as in recursion we start from top to down indices so we will not go down,leftdowndiag, rightdowndiag instread we will go up, leftupdiag, rightupdiag
    if (m < 0 or m >= col)
        return -1e9;

    if (n == 0)
        return matrix[0][m];

    if (dp[n][m] != -1)
        return dp[n][m];
    int up = matrix[n][m] + f(n - 1, m, col, matrix, dp);
    int righdig = matrix[n][m] + f(n - 1, m + 1, col, matrix, dp);
    int leftdig = matrix[n][m] + f(n - 1, m - 1, col, matrix, dp);

    return dp[n][m] = max(up, max(leftdig, righdig));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        int ans = f(n - 1, j, m, matrix, dp);
        maxi = max(maxi, ans);
    }

    return maxi;
}

//////////////////////--------------------------------------->>>>>>>>>>>>>>>>>>tabulation

#include <bits/stdc++.h>

using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initializing first row - base condition
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += dp[i - 1][j - 1];
            else
                leftDiagonal += -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += dp[i - 1][j + 1];
            else
                rightDiagonal += -1e9;

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    int maxi = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }

    return maxi;
}

//////////////////////--------------------------------------->>>>>>>>>>>>>>>>>>sapce optimization

#include <bits/stdc++.h>

using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0), cur(m, 0);

    // Initializing first row - base condition
    for (int j = 0; j < m; j++)
    {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int up = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += prev[j - 1];
            else
                leftDiagonal += -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += prev[j + 1];
            else
                rightDiagonal += -1e9;

            cur[j] = max(up, max(leftDiagonal, rightDiagonal));
        }

        prev = cur;
    }

    int maxi = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, prev[j]);
    }

    return maxi;
}