#include <bits/stdc++.h> 
using namespace std;
////////////////////-------------------------->>>>>>>>>>>norml recusion
int f(int ind, int buy, int cp, vector<int>& prices, int n){
    if(ind==n) return 0;
    if(cp==0) return 0;
    int profit=0;
    if(buy){
        profit= max(-prices[ind] + f(ind+1, 0,cp,prices,n),
                 0+ f(ind+1,1,cp,prices,n));
    }

    else
    {
        profit= max(prices[ind] + f(ind+1,1,cp-1,prices,n),
                 0+ f(ind+1,0,cp,prices,n));
    }
    return profit;
}
int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    return  f(0,1,2,prices,n);
}






#include <bits/stdc++.h> 
using namespace std;
////////////////////-------------------------->>>>>>>>>>>memoization
int f(int ind, int buy, int cp, vector<int>& prices, int n
,vector<vector<vector<int>>>&dp){
    if(ind==n) return 0;
    if(cp==0) return 0;
    if(dp[ind][buy][cp] != -1) return dp[ind][buy][cp];
    int profit=0;
    if(buy){
        profit= max(-prices[ind] + f(ind+1, 0,cp,prices,n,dp),
                 0+ f(ind+1,1,cp,prices,n,dp));
    }

    else
    {
        profit= max(prices[ind] + f(ind+1,1,cp-1,prices,n,dp),
                 0+ f(ind+1,0,cp,prices,n,dp));
    }
    return dp[ind][buy][cp]=profit;
}
int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return  f(0,1,2,prices,n,dp);
}