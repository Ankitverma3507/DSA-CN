#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>.normal recursion
class Solution {

    private:
    int f(int ind, int n, vector<int>&arr, int k){
        if(ind==n) return 0;

        int len=0; int maxi= -1e9; int maxians= -1e9;
        for(int j= ind; j<min(ind+k,n); j++){
            len++;
            maxi= max(maxi, arr[j]);
            int sum= len*maxi  + f(j+1,n,arr,k);
            maxians= max(maxians,sum);
        }

        return maxians;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        return f(0,n,arr,k);
    }
};









#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>memoization
class Solution {

    private:
    int f(int ind, int n, vector<int>&arr, int k,vector<int>&dp){
        if(ind==n) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int len=0; int maxi= -1e9; int maxians= -1e9;
        for(int j= ind; j<min(ind+k,n); j++){
            len++;
            maxi= max(maxi, arr[j]);
            int sum= len*maxi  + f(j+1,n,arr,k,dp);
            maxians= max(maxians,sum);
        }

        return dp[ind]=maxians;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int> dp(n,-1);
        return f(0,n,arr,k,dp);
    }
};




#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>.tabulaiton 
class Solution {

    private:
    int f(int ind, int n, vector<int>&arr, int k,vector<int>&dp){
        if(ind==n) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int len=0; int maxi= -1e9; int maxians= -1e9;
        for(int j= ind; j<min(ind+k,n); j++){
            len++;
            maxi= max(maxi, arr[j]);
            int sum= len*maxi  + f(j+1,n,arr,k,dp);
            maxians= max(maxians,sum);
        }

        return dp[ind]=maxians;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int> dp(n+1,0);

        dp[n]=0;
        for(int ind=n-1; ind>=0; ind--){
            int len=0; int maxi= -1e9; int maxians= -1e9;
        for(int j= ind; j<min(ind+k,n); j++){
            len++;
            maxi= max(maxi, arr[j]);
            int sum= len*maxi  + dp[j+1];
            maxians= max(maxians,sum);
        }

         dp[ind]=maxians;
        }
        return dp[0];

    }
};