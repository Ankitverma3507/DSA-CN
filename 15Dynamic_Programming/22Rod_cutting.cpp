#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>normal recursion
int f(int ind, int N, vector<int> &price)
{
    if (ind == 0)
        return N * price[0];

    int nontake = 0 + f(ind - 1, N, price);
    int take = -1e9;
    if (N >= ind + 1)
        take = price[ind] + f(ind, N - (ind + 1), price);

    return max(take, nontake);
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    return f(n - 1, n, price);
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>Memoization
int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return N * price[0];
    if (dp[ind][N] != -1)
        return dp[ind][N];

    int nontake = 0 + f(ind - 1, N, price, dp);
    int take = -1e9;
    if (N >= ind + 1)
        take = price[ind] + f(ind, N - (ind + 1), price, dp);

    return dp[ind][N] = max(take, nontake);
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>tabulation
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int nontake = 0 + dp[ind - 1][N];
            int take = -1e9;
            if (N >= ind + 1)
                take = price[ind] + dp[ind][N - (ind + 1)];

            dp[ind][N] = max(take, nontake);
        }
    }
    return dp[n - 1][n];
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>space optimisation
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    vector<int> prev(n + 1, 0), curr(n + 1);
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int nontake = 0 + prev[N];
            int take = -1e9;
            if (N >= ind + 1)
                take = price[ind] + curr[N - (ind + 1)];

            curr[N] = max(take, nontake);
        }
        prev = curr;
    }
    return prev[n];
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>super super  space optimisation

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    vector<int> prev(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int nontake = 0 + prev[N];
            int take = -1e9;
            if (N >= ind + 1)
                take = price[ind] + prev[N - (ind + 1)];

            prev[N] = max(take, nontake);
        }
    }
    return prev[n];
}
