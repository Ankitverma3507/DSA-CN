#include <bits/stdc++.h> 
using namespace std;

//////////////////////////////------------->>>>>>>>>>>>normal recursion
int f(int i, int j,vector<vector<int>> &grid)
{
    if (i == 0 and j == 0)
        return grid[i][j];
    if (i < 0 or j < 0)
        return 1e9;
        
    int up = grid[i][j] +f(i - 1, j,grid);
    int left = grid[i][j] + f(i, j - 1,grid);

    return min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n= grid.size();
    int m= grid[0].size();
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n-1, m-1,grid);
}




//////////////////////////////------------->>>>>>>>>>>>Memoization
#include <bits/stdc++.h> 
int f(int i, int j,vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return grid[i][j];
    if (i < 0 or j < 0)
        return 1e9;
    if(dp[i][j] !=-1)
    return dp[i][j];
    int up = grid[i][j] +f(i - 1, j,grid,dp);
    int left = grid[i][j] + f(i, j - 1,grid,dp);

    return dp[i][j]=min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n= grid.size();
    int m= grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n-1, m-1,grid,dp);
}







//////////////////////////////------------->>>>>>>>>>>>Tabulation
#include <bits/stdc++.h> 
int f(int n, int m,vector<vector<int>> &grid, vector<vector<int>> &dp)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 and j == 0) {
        dp[i][j] = grid[0][0];
      }

      else {
        int up = grid[i][j];
        if (i > 0)
          up += dp[i - 1][j];
        else
          up += 1e9;

        int left = grid[i][j];
        if (j > 0)
          left += dp[i][j - 1];
        else
          left += 1e9;

        dp[i][j] = min(up, left);
      }
    }
  }
      return dp[n-1][m-1];

}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n= grid.size();
    int m= grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    return f(n, m,grid,dp);
}










//////////////////////////////------------->>>>>>>>>>>>space optimize
#include <bits/stdc++.h> 

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n= grid.size();
    int m= grid[0].size();
    vector<int> prev(m,0);
    // vector<vector<int>> dp(n, vector<int>(m, 0));
    // return f(n, m,grid,prev);
    for (int i = 0; i < n; i++) {
    vector<int> curr(m,0);
    for (int j = 0; j < m; j++) {
      if (i == 0 and j == 0) {
        curr[j] = grid[0][0];
      }

      else {
        int up = grid[i][j];
        //requiring prev row's column
        if (i > 0)
          up += prev[j];
        else
          up += 1e9;

        int left = grid[i][j];
        //curr row j-1 column
        if (j > 0)
          left += curr[j - 1];
        else
          left += 1e9;

        curr[j] = min(up, left);
      }
    }
    prev=curr;
  }
      return prev[m-1];

}

