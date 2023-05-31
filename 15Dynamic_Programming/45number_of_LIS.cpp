#include <bits/stdc++.h> 
#include<string>
using namespace std;

int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n= arr.size();
    vector<int> dp(n,1), cnt(n,1);

    int maxi=1;
    for(int i=0 ;i <n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]< arr[i] and dp[j]+1 > dp[i]){
                dp[i]=dp[j]+1 ;
                cnt[i]= cnt[j];
            }

            else if(arr[j]< arr[i] and dp[j]+1 == dp[i]){
                cnt[i]+= cnt[j];
            }
        }
        maxi= max(maxi,dp[i]);
    }

    int nos=0;
    for(int i=0; i<n; i++){
        if(dp[i]==maxi){
            nos += cnt[i];
        }
    }
    return nos;
}