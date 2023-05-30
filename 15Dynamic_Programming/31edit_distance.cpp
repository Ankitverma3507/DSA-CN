#include <bits/stdc++.h>
using namespace std;
/////////////////------------------------>>>>>>>>>>normal recursion
int f(int i, int j, string &s, string &t)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (s[i] == t[j])
    {
        return f(i - 1, j - 1, s, t);
    }

    else
    {
        int insert = 1 + f(i, j - 1, s, t);
        int del = 1 + f(i - 1, j, s, t);
        int repla = 1 + f(i - 1, j - 1, s, t);
        return min(insert, min(del, repla));
    }
}

int editDistance(string s, string t)
{
    // write you code here
    int n = s.size();
    int m = t.size();

    return f(n - 1, m - 1, s, t);
}

#include <bits/stdc++.h>
using namespace std;
/////////////////------------------------>>>>>>>>>>memoization
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
    {
        return dp[i][j] = f(i - 1, j - 1, s, t, dp);
    }

    else
    {
        int insert = 1 + f(i, j - 1, s, t, dp);
        int del = 1 + f(i - 1, j, s, t, dp);
        int repla = 1 + f(i - 1, j - 1, s, t, dp);
        return dp[i][j] = min(insert, min(del, repla));
    }
}

int editDistance(string s, string t)
{
    // write you code here
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, s, t, dp);
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>memoization with right shifting
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i - 1] == t[j - 1])
    {
        return dp[i][j] = f(i - 1, j - 1, s, t, dp);
    }

    else
    {
        int insert = 1 + f(i, j - 1, s, t, dp);
        int del = 1 + f(i - 1, j, s, t, dp);
        int repla = 1 + f(i - 1, j - 1, s, t, dp);
        return dp[i][j] = min(insert, min(del, repla));
    }
}

int editDistance(string s, string t)
{
    // write you code here
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n, m, s, t, dp);
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>Tabulation with right shifting

int editDistance(string s, string t)
{
    // write you code here
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }

            else
            {
                int insert = 1 + dp[i][j - 1];
                int del = 1 + dp[i - 1][j];
                int repla = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(insert, min(del, repla));
            }
        }
    }
    return dp[n][m];
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>space opti

int editDistance(string S1, string S2)
{
    // write you code here
    int n = S1.size();
    int m = S2.size();

    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    for (int j = 0; j <= m; j++)
    {
        prev[j] = j;
    }

    for (int i = 1; i < n + 1; i++)
    {
        cur[0] = i;
        for (int j = 1; j < m + 1; j++)
        {
            if (S1[i - 1] == S2[j - 1])
                cur[j] = 0 + prev[j - 1];

            else
                cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
        }
        prev = cur;
    }

    return prev[m];
}