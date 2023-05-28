#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////-------------------------->>>>>>>>>>>normal recursion
bool f(int ind, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);
    bool nontake = f(ind - 1, target, arr);
    bool take = false;
    if (target >= arr[ind])
        take = f(ind - 1, target - arr[ind], arr);

    return (take) | (nontake);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    return f(n - 1, k, arr);
}

/////////////////////////////////-------------------------->>>>>>>>>>>memoization
#include <bits/stdc++.h>

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool nontake = f(ind - 1, target, arr, dp);
    bool take = false;
    if (target >= arr[ind])
        take = f(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (take) | (nontake);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

/////////////////////////////////-------------------------->>>>>>>>>>>Tabulation
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if(arr[0]<=k)
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
    return dp[n - 1][k];
}




/////////////////////////////////-------------------------->>>>>>>>>>>space optimze

#include <bits/stdc++.h> 


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    
    return prev[k];
}