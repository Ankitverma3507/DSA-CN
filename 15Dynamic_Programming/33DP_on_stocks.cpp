#include <bits/stdc++.h> 
using namespace std;
// we have to tell which is the best time to buy and sell stocks and we have to return max profit
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n= prices.size();
    int mini= prices[0]; int profit=0;
    for(int i=1; i<n; i++){
        int cost= prices[i]- mini;
        profit= max(profit,cost);
        mini= min(mini,prices[i]);
    }
    return profit;
}