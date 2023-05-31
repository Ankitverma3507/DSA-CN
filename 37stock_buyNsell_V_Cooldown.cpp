#include <bits/stdc++.h> 
using namespace std;
////////////////////-------------------------->>>>>>>>>>>memoization
int f(int ind, int buy, vector<int> &values, int n,vector<vector<int>> &dp){
    if(ind>= n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    int profit;
    if(buy){
        profit= max(-values[ind] + f(ind+1, 0, values,n,dp),
         0+f(ind+1, 1, values,n,dp));
    }

    else{
        profit=max(values[ind] + f(ind+2, 1, values,n,dp), 
        0+ f(ind+1, 0, values,n,dp));
    }

    return dp[ind][buy] =profit;
}

int stockProfit(vector<int> &prices){
    // Write your code here.
    int n= prices.size();
    vector<vector<int>> dp(n, vector<int>(2,-1));
    return f(0,1,prices,n,dp);
}






#include <bits/stdc++.h> 
using namespace std;
////////////////////-------------------------->>>>>>>>>>>tabulation

int stockProfit(vector<int> &prices){
    // Write your code here.
    int n= prices.size();
     vector<vector<int>> dp(n+2, vector<int>(2,0));
   

    for(int ind=n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            int profit;
            if(buy){
                profit= max(-prices[ind] + dp[ind+1][0],
                0+dp[ind+1][1]);
            }

            else{
                profit=max(prices[ind] + dp[ind+2][1], 
                0+ dp[ind+1][0]);
            }

             dp[ind][buy] =profit;
        }
    }
    return dp[0][1];
}