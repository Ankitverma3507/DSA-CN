#include <bits/stdc++.h>
using namespace std;

//////////////////////---------------------------------Memoization
int maxi(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + maxi(ind - 2, nums, dp);
    int notpick = 0 + maxi(ind - 1, nums, dp);

    return dp[ind] = max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    return maxi(n - 1, nums, dp);
}

///////////////////////------------->>>tabulation
#include <bits/stdc++.h>

int maxi(int ind, vector<int> &arr, vector<int> &dp)
{
    dp[0] = arr[0];

    for (int i = 1; i < ind; i++)
    {

        int pick = arr[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int notpick = 0 + dp[i - 1];

        dp[i] = max(pick, notpick);
    }

    return dp[ind - 1];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    return maxi(n, nums, dp);
}




//////////////////------------------>>>>space optimize
#include <bits/stdc++.h> 


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n= nums.size();

    int prev= nums[0];
    int prev2= 0;
    for(int i=1; i<n; i++)
    {
        int take= nums[i];
        if(i>1) take+= prev2;

        int nontake= 0+ prev;

        int curri= max(take,nontake);
        prev2=prev;
        prev=curri;
    }

    return prev;
}




