
#include <bits/stdc++.h> 
using namespace std;

/////////////////////////////////////////////--------->>>>normal recursion with changes
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){

  if (ind == 0) {
    if (target == 0 and arr[0] == 0)
      return 2;
    if (target == 0 or target == arr[0])
      return 1;
    return 0;
  }

    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}














#include <bits/stdc++.h> 
using namespace std;

/////////////////////////////////////////////--------->>>>tabulation

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n= num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1,0));
    for(int i=0;i<n; i++) dp[i][0]=1;
    if(num[0]<=tar) dp[0][num[0]]=1;

    for(int ind=1; ind<n;ind++){
        for(int sum=0; sum<=tar;sum++){
            int nontake = dp[ind - 1][sum];
            int take = 0;
            if (sum >= num[ind])
                take = dp[ind - 1][sum - num[ind]];

             dp[ind][sum]= take+nontake;
        }
    }
    return dp[n-1][tar];
}








/////////////////////////////////////////////--------->>>>space optimization

#include <bits/stdc++.h> 
using namespace std;

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n= num.size();
    vector<int> prev(tar+1,0), curr(tar+1);
    for(int i=0;i<n; i++) prev[0]=1;
    if(num[0]<=tar) prev[num[0]]=1;

    for(int ind=1; ind<n;ind++){
        for(int sum=0; sum<=tar;sum++){
            int nontake = prev[sum];
            int take = 0;
            if (sum >= num[ind])
                take = prev[sum - num[ind]];

             curr[sum]= take+nontake;
        }
        prev= curr;
    }
    return prev[tar];
}