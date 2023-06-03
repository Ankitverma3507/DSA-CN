#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>.normal recursion
int mod=1000000007l;

int f(int i, int j, bool isTrue, string &exp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue) return exp[i]== 'T';
        else return exp[i]== 'F';
    }
    int mini=0;
    for(int ind=i+1; ind<=j-1; ind=ind+2){
        int lt=f(i,ind-1,1,exp);
        int lf=f(i,ind-1,0,exp);
        int rt=f(ind+1,j,1,exp);
        int rf=f(ind+1,j,0,exp);

        if(exp[ind]== '&'){
            if(isTrue)
            mini+= ((lt*rt)% mod)%mod;
            else
            mini += ((lf*rt)%mod + (lt*rf)%mod + (lf*rf)%mod)%mod; 
        }

        else if(exp[ind]== '|'){
            if(isTrue)
            mini+= ((lf*rt)%mod + (lt*rf)%mod + (lt*rt)%mod)%mod;
            else
            mini+= ((lf*rf)% mod)%mod;
        }

        else if(exp[ind]== '^'){
           if(isTrue)
           mini +=  ((lf*rt)%mod + (lt*rf)%mod)%mod;
           else
           mini+= ((lt*rt)%mod + (lf*rf)%mod)%mod;
        }
    }

    return mini;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n= exp.size();
    return f(0,n-1,true,exp);
}











#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////-------->>>>>.memoization 
#define ll long long
int mod=1000000007l;

int f(int i, int j, bool isTrue, string &exp,vector<vector<vector<ll>>>&dp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue) return exp[i]== 'T';
        else return exp[i]== 'F';
    }
    if(dp[i][j][isTrue] !=-1) return dp[i][j][isTrue];
     ll ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp, dp);
        ll lF = f(i, ind - 1, 0, exp, dp);
        ll rT = f(ind + 1, j, 1, exp, dp);
        ll rF = f(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }

    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n= exp.size();
    vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(n+1, vector<ll>(2,-1)));
    return f(0,n-1,true,exp,dp);
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n= exp.size();
    vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(n+1, vector<ll>(2,-1)));
    return f(0,n-1,true,exp,dp);
}