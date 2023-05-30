#include <bits/stdc++.h>
using namespace std;
/////////////////------------------------>>>>>>>>>>normal recursion
int f(int i, int j, string &t, string &s)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (t[i] == s[j])
    {
        return f(i - 1, j - 1, t, s) + f(i - 1, j, t, s);
    }
    else
        return f(i - 1, j, t, s);
}
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    // Write your code here.
    return f(lt - 1, ls - 1, t, s);
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>memoization with right shifting
int f(int i, int j, string &t, string &s, vector<vector<int>> &dp)
{
    if (j == 0)
        return 1;
    if (i == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (t[i - 1] == s[j - 1])
    {
        return dp[i][j] = f(i - 1, j - 1, t, s, dp) + f(i - 1, j, t, s, dp);
    }
    else
        return dp[i][j] = f(i - 1, j, t, s, dp);
}
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    // Write your code here.
    vector<vector<int>> dp(lt + 1, vector<int>(ls + 1, -1));

    return f(lt, ls, t, s, dp);
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>Tabulation with right shifting
int prime = 1e9 + 7;

int subsequenceCounting(string &t, string &s, int n, int m)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (t[i - 1] == s[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>Space Optimisation
int prime = 1e9 + 7;

int subsequenceCounting(string &t, string &s, int n, int m)
{
    // Write your code here.
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    prev[0] = curr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (t[i - 1] == s[j - 1])
            {
                curr[j] = (prev[j - 1] + prev[j]) % prime;
            }
            else
                curr[j] = prev[j];
        }
        prev = curr;
    }
    return prev[m];
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>super super Space Optimisation
int prime = 1e9 + 7;

int subsequenceCounting(string &t, string &s, int n, int m)
{
    // Write your code here.
    vector<int> prev(m + 1, 0);
    prev[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (t[i - 1] == s[j - 1])
            {
                prev[j] = (prev[j - 1] + prev[j]) % prime;
            }
        }
    }
    return prev[m];
}