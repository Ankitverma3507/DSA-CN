#include <bits/stdc++.h>

using namespace std;
//////////////////////////////////////////////////memoization
bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[ind][target] = true;

    if (ind == 0)
        return dp[ind][target] = arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

int minSubsetSumDifference(vector<int> &arr, int n)
{

    int totSum = 0;

    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

    for (int i = 0; i <= totSum; i++)
    {
        bool dummy = subsetSumUtil(n - 1, i, arr, dp);
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////tabulation

vector<vector<bool>> subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nontake = dp[ind - 1][target];
            bool take = false;
            if (target >= arr[ind])
                take = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = (take) | (nontake);
        }
    }
    return dp;
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.
    int totsum = 0;
    for (int i = 0; i < n; i++)
        totsum += arr[i];
    vector<vector<bool>> dp = subsetSumToK(n, totsum, arr);
    int ans = 1e9; // as we have to give min ans we will take max ans
    for (int i = 0; i <= totsum / 2; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int s1 = i;
            int s2 = totsum - i;
            ans = min(ans, abs(s1 - s2));
        }
    }
    return ans;
}
