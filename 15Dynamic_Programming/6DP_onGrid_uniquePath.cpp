#include <bits/stdc++.h>
using namespace std;

// /////////////////////////--------------------->>>>>>>>>>Normal recursion
int f(int i, int j)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;
    int up = f(i - 1, j);
    int left = f(i, j - 1);

    return up + left;
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1);
}

// /////////////////////////--------------------->>>>>>>>>>Memoization
#include <bits/stdc++.h>

int f(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = f(i - 1, j, dp);
    int left = f(i, j - 1, dp);

    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);
}

// /////////////////////////--------------------->>>>>>>>>>Tabulation
#include <bits/stdc++.h>

int ans(int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // base condition
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return ans(m, n, dp);
}














// /////////////////////////--------------------->>>>>>>>>>space otpimization


#include <bits/stdc++.h> 


int uniquePaths(int m, int n) {
	vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];
                
            temp[j] = up + left;
        }
        prev = temp;
    }
    
    return prev[n-1];
    
}

