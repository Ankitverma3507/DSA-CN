#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>.memoization 
bool isPalindrome(int i, int j , string &s){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++; j--;

    }
    return true;
}
int f(int i, string &str,int n,vector<int> &dp){
    if(i==n) return 0;
    if(dp[i] != -1) return dp[i];
    int mincost= 1e9;
    for(int j=i; j<n; j++ ){
        if(isPalindrome(i,j,str))
        {
           int cost = 1+ f(j+1,str,n,dp);
            mincost= min(mincost, cost);
        }
    }
    return dp[i]= mincost;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n= str.size();
    vector<int> dp(n,-1);
    return f(0,str,n,dp)-1;
}







#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>.tabulaiton 
bool isPalindrome(int i, int j , string &s){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++; j--;

    }
    return true;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n= str.size();
    vector<int> dp(n+1,0);

    dp[n]=0;
    for(int i=n-1; i>=0; i--){
        int mincost= 1e9;
        for(int j=i; j<n; j++ ){
            if(isPalindrome(i,j,str))
            {
            int cost = 1+ dp[j+1];
                mincost= min(mincost, cost);
            }
        }
         dp[i]= mincost;
    }
    return dp[0]-1;
}
