#include <bits/stdc++.h>
using namespace std;
///////////////////////////---------------------->>>>>>>>>>>>>recursion

int f(int i, int j1, int j2, vector<vector<int>> &grid, int r, int c)
{
  if (j1 < 0 or j1 >= c or j2 < 0 or j2 >= c)
    return -1e9;
  if (i == r - 1)
  {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  int maxi = -1e9;
  for (int dj1 = -1; dj1 <= 1; dj1++)
  {
    for (int dj2 = -1; dj2 <= 1; dj2++)
    {
      if (j1 == j2)
        maxi = max(maxi, grid[i][j1] + f(i + 1, j1 + dj1, j2 + dj2, grid, r, c));
      else
        maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i + 1, j1 + dj1, j2 + dj2, grid, r, c));
    }
  }
  return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
  // Write your code here.
  return f(0, 0, c - 1, grid, r, c);
}

///////////////////////////---------------------->>>>>>>>>>>>>memoization
#include <bits/stdc++.h>

int f(int i, int j1, int j2, vector<vector<int>> &grid, int r, int c,
      vector<vector<vector<int>>> &dp)
{
  if (j1 < 0 or j1 >= c or j2 < 0 or j2 >= c)
    return -1e9;
  if (i == r - 1)
  {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }
  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = -1e9;
  for (int dj1 = -1; dj1 <= 1; dj1++)
  {
    for (int dj2 = -1; dj2 <= 1; dj2++)
    {
      if (j1 == j2)
        maxi = max(maxi, grid[i][j1] + f(i + 1, j1 + dj1, j2 + dj2, grid, r, c, dp));
      else
        maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i + 1, j1 + dj1, j2 + dj2, grid, r, c, dp));
    }
  }
  dp[i][j1][j2] = maxi;
  return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
  // Write your code here.
  vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
  return f(0, 0, c - 1, grid, r, c, dp);
}

///////////////////////////---------------------->>>>>>>>>>>>>memoization

#include <bits/stdc++.h>

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
  // Write your code here.
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,
                                                        vector<int>(m, 0)));

  for (int j1 = 0; j1 < m; j1++)
  {
    for (int j2 = 0; j2 < m; j2++)
    {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  // Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j1 = 0; j1 < m; j1++)
    {
      for (int j2 = 0; j2 < m; j2++)
      {

        int maxi = INT_MIN;

        // Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++)
        {
          for (int dj = -1; dj <= 1; dj++)
          {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
                (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];
}
