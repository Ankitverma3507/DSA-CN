#include <bits/stdc++.h>
using namespace std;
int lcs(string s, string t)
{
    // Write your code here
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            }

            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    return dp[n][m];
}

int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}