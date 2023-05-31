#include <bits/stdc++.h>
using namespace std;
////////////////////-------------------------->>>>>>>>>>>norml recusion
int f(int ind, int buy, int cp, vector<int> &prices, int n)
{
    if (ind == n)
        return 0;
    if (cp == 0)
        return 0;
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[ind] + f(ind + 1, 0, cp, prices, n),
                     0 + f(ind + 1, 1, cp, prices, n));
    }

    else
    {
        profit = max(prices[ind] + f(ind + 1, 1, cp - 1, prices, n),
                     0 + f(ind + 1, 0, cp, prices, n));
    }
    return profit;
}
int maxProfit(vector<int> &prices, int n,int k)
{
    // Write your code here.
    return f(0, 1, k, prices, n);
}




#include <bits/stdc++.h> 
using namespace std;
////////////////////-------------------------->>>>>>>>>>>memoization
int f(int ind, int buy, int cp, vector<int> &prices, int n,
 vector<vector<vector<int>>> &dp)
{
    if (ind == n)
        return 0;
    if (cp == 0)
        return 0;
    if (dp[ind][buy][cp] != -1)
        return dp[ind][buy][cp];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[ind] + f(ind + 1, 0, cp, prices, n, dp),
                     0 + f(ind + 1, 1, cp, prices, n, dp));
    }

    else
    {
        profit = max(prices[ind] + f(ind + 1, 1, cp - 1, prices, n, dp),
                     0 + f(ind + 1, 0, cp, prices, n, dp));
    }
    return dp[ind][buy][cp] = profit;
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    return f(0, 1, k, prices, n, dp);
}






#include <bits/stdc++.h> 
using namespace std;
////////////////////-------------------------->>>>>>>>>>>tabulation

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
   vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(2, vector<int>(k+1, 0)));
    for (int ind = 0; ind < n; ind++)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            dp[ind][buy][0] = 0;
        }
    }

    for (int buy = 0; buy <= 1; buy++)
    {
        for (int cp = 0; cp <= k; cp++)
        {
            dp[n][buy][cp] = 0;
        }
    }

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cp = 1; cp <= k; cp++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[ind] + dp[ind + 1][0][cp],
                                 0 + dp[ind + 1][1][cp]);
                }

                else
                {
                    profit = max(prices[ind] + dp[ind + 1][1][cp - 1],
                                 0 + dp[ind + 1][0][cp]);
                }
                dp[ind][buy][cp] = profit;
            }
        }
    }
    return dp[0][1][k];
}







#include <bits/stdc++.h> 
using namespace std;
////////////////////-------------------------->>>>>>>>>>>Space optimisation
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
   vector<vector<int>> ahead(2, vector<int>(k+1, 0));

    vector<vector<int>> cur(2, vector<int>(k+1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {

                if (buy == 0)
                { // We can buy the stock
                    cur[buy][cap] = max(0 + ahead[0][cap],
                                        -prices[ind] + ahead[1][cap]);
                }

                if (buy == 1)
                { // We can sell the stock
                    cur[buy][cap] = max(0 + ahead[1][cap],
                                        prices[ind] + ahead[0][cap - 1]);
                }
            }
        }
        ahead = cur;
    }

    return ahead[0][k];
}

