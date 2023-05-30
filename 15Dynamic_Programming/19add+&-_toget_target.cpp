#include <bits/stdc++.h>
using namespace std;
// int mod= 1e9+7;
int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (target == 0 and arr[0] == 0)
            return 2;
        if (target == 0 or target == arr[0])
            return 1;
        return 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (notTaken + taken);
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int totsum = 0;
    for (int i = 0; i < n; i++)
        totsum += arr[i];
    if (totsum < d or (totsum - d) % 2)
        return false;
    int k = (totsum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysUtil(n - 1, k, arr, dp);
}

int targetSum(int n, int target, vector<int> &arr)
{
    // Write your code here.
    return countPartitions(n, target, arr);
}
