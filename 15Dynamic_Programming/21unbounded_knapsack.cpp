
#include <bits/stdc++.h> 
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>normal recursion
int f(int ind, int wt,vector<int> &profit, vector<int> &weight){
    if(ind==0)
    return ((int)wt/weight[0])* profit[0];

    int nottake=0+ f(ind-1, wt,profit,weight);
    int take= -1e9;
    if(weight[ind]<=wt)
    take= profit[ind]+ f(ind,wt-weight[ind],profit, weight);
    
    return max(take,nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    return f(n-1,w,profit,weight);
}




#include <bits/stdc++.h> 
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>Memoization 

int f(int ind, int wt,vector<int> &profit, vector<int> &weight
,vector<vector<int>>&dp){
    if(ind==0)
    return ((int)wt/weight[0])* profit[0];
    if(dp[ind][wt] !=-1)return dp[ind][wt];
    int nottake=0+ f(ind-1, wt,profit,weight,dp);
    int take= -1e9;
    if(weight[ind]<=wt)
    take= profit[ind]+ f(ind,wt-weight[ind],profit, weight,dp);
    
    return dp[ind][wt]=max(take,nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>>dp(n, vector<int>(w+1,-1));
    return f(n-1,w,profit,weight,dp);
}







#include <bits/stdc++.h> 
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>tabulation 


int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = -1e9;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}





#include <bits/stdc++.h> 
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>space optimisation 


int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    vector<int> prev(W+1,0), curr(W+1);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + prev[cap];
            
            int taken = -1e9;
            if(wt[ind] <= cap)
                taken = val[ind] + curr[cap - wt[ind]];
                
            curr[cap] = max(notTaken, taken);
        }
        prev=curr;
    }
    
    return prev[W];
}






#include <bits/stdc++.h> 
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>super super  space optimisation 
int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    vector<int> prev(W+1,0);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + prev[cap];
            
            int taken = -1e9;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
    }
    
    return prev[W];
}
