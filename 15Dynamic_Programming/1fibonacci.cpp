#include <bits/stdc++.h>

using namespace std;

int f(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int main()
{
// memoization
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);
    return 0;

    ////////////////tabulation
  class Solution {
public:

    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int>dp(n+1);

        dp[0]= 0;
        dp[1]= 1;
        dp[2]= 2;


        for(int i=3; i<=n; i++){
             dp[i]= dp[i-1]+ dp[i-2];
        }
        return dp[n];
    }
};

    ///////////////////space optimization
class Solution {
public:

    int climbStairs(int n) {
        int prev1=0;
        int prev2=1;
        int prev3=2;
        int curr;
        if(n==0) return prev1;
        if(n==1) return prev2;
        if(n==2) return prev3;
        for(int i=3; i<=n; i++){
              curr= prev2+prev3;
             prev1=prev2;
             prev2=prev3;
             prev3=curr;
        }
        return curr;
    }
};