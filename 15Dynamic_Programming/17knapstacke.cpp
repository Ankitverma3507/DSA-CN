#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////------------------->>>>>normal recursion
int f(int ind,int wt,vector<int>&value,vector<int> weight)
{
	if(ind==0)
	{
		if(weight[0]<= wt)
		return value[0];
		 return 0;
	}
	int take= -1e9;
	int nontake= 0+ f(ind-1,wt,value,weight);
	if(weight[ind]<=wt)
	take= value[ind] + f(ind-1,wt-weight[ind],value,weight);

	return max(take,nontake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return f(n-1,maxWeight,value,weight);
}









#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////------------------->>>>>memoization

int f(int ind,int wt,vector<int>&value,vector<int>& weight,vector<vector<int>> &dp)
{
	if(ind==0)
	{
		if(weight[0]<= wt)
		return value[0];
		 return 0;
	}
	if(dp[ind][wt] !=-1) return dp[ind][wt];
	int take= -1e9;
	int nontake= 0+ f(ind-1,wt,value,weight,dp);
	if(weight[ind]<=wt)
	take= value[ind] + f(ind-1,wt-weight[ind],value,weight,dp);

	return dp[ind][wt]=max(take,nontake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,maxWeight,value,weight,dp);
}





#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////------------------->>>>>tabultaion


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	for(int i=weight[0]; i<=maxWeight; i++) dp[0][i]=value[0];

	for(int ind=1; ind<n; ind++){
		for(int wt=0; wt<=maxWeight; wt++){
			int take= -1e9;
			int nontake= 0+ dp[ind-1][wt];
			if(weight[ind]<=wt)
			take= value[ind] + dp[ind-1][wt-weight[ind]];

			 dp[ind][wt]=max(take,nontake);
		}
	}
	return dp[n-1][maxWeight];
}







#include <bits/stdc++.h> 

using namespace std;
///////////////////////////////------------------->>>>>space
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	
	vector<int> prev(maxWeight+1,0), curr(maxWeight+1);
	for(int i=weight[0]; i<=maxWeight; i++) prev[i]=value[0];

	for(int ind=1; ind<n; ind++){
		for(int wt=0; wt<=maxWeight; wt++){
			int take= -1e9;
			int nontake= 0+ prev[wt];
			if(weight[ind]<=wt)
			take= value[ind] + prev[wt-weight[ind]];

			 curr[wt]=max(take,nontake);
		}
		prev= curr;
	}
	return prev[maxWeight];
}







#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////------------------->>>>>super super space otpimisation

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	
	vector<int> prev(maxWeight+1,0);
	for(int i=weight[0]; i<=maxWeight; i++) prev[i]=value[0];

	for(int ind=1; ind<n; ind++){
		for(int wt=maxWeight; wt>=0; wt--){
			int take= -1e9;
			int nontake= 0+ prev[wt];
			if(weight[ind]<=wt)
			take= value[ind] + prev[wt-weight[ind]];

			 prev[wt]=max(take,nontake);
		}
		
	}
	return prev[maxWeight];
}