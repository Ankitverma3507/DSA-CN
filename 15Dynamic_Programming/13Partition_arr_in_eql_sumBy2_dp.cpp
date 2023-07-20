#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////------------->>>>>>>>>question is same to previous koshan
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<bool> prev(k + 1, false);

    prev[0] = true;

    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> cur(k + 1, false);
        cur[0] = true;
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = prev[target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];

            cur[target] = notTaken || taken;
        }
        prev = cur;
    }

    return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.

    int totsum = 0;
    for (int i = 0; i < n; i++)
        totsum += arr[i];

    if (totsum % 2)
        return false;

    int target = totsum / 2;
    return subsetSumToK(n, target, arr);
}












//tabulation
#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}

int main() {

  vector<int> arr = {1,2,3,4};
  int k=4;
  int n = arr.size();
                                 
  if(subsetSumToK(n,k,arr))
    cout<<"Subset with given target found";
  else 
    cout<<"Subset with given target not found";
}