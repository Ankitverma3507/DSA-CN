#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>normal recursion

long f(int ind, int tar, int *denominations)
{
    if (ind == 0)
    {
        if (tar % denominations[0] == 0)
            return 1;
        else
            return 0;
    }

    long nottake = f(ind - 1, tar, denominations);
    long take = 0;
    if (tar >= denominations[ind])
        take = f(ind, tar - denominations[ind], denominations);

    return take + nottake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    return f(n - 1, value, denominations);
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>Memoization

long f(int ind, int tar, int *denominations, vector<vector<long>> &dp)
{
    if (ind == 0)
    {
        if (tar % denominations[0] == 0)
            return 1;
        else
            return 0;
    }
    if (dp[ind][tar] != -1)
        return dp[ind][tar];
    long nottake = f(ind - 1, tar, denominations, dp);
    long take = 0;
    if (tar >= denominations[ind])
        take = f(ind, tar - denominations[ind], denominations, dp);

    return dp[ind][tar] = take + nottake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return f(n - 1, value, denominations, dp);
}

#include <bits/stdc++.h>

using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>tabulation

long countWaysToMakeChange(int *num, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int t = 0; t <= value; t++)
    {
        if (t % num[0] == 0)
            dp[0][t] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= value; tar++)
        {
            long nottake = dp[ind - 1][tar];
            long take = 0;
            if (tar >= num[ind])
                take = dp[ind][tar - num[ind]];

            dp[ind][tar] = take + nottake;
        }
    }

    return dp[n - 1][value];
}

#include <bits/stdc++.h>

using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>space otpi

long countWaysToMakeChange(int *num, int n, int value)
{
    // Write your code here
    //  vector<vector<long>>dp(n,vector<long>(value+1,0));
    vector<long> prev(value + 1, 0), curr(value + 1);
    for (int t = 0; t <= value; t++)
    {
        if (t % num[0] == 0)
            prev[t] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= value; tar++)
        {
            long nottake = prev[tar];
            long take = 0;
            if (tar >= num[ind])
                take = curr[tar - num[ind]];

            curr[tar] = take + nottake;
        }
        prev = curr;
    }

    return prev[value];
}