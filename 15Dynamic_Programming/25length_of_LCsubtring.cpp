#include <bits/stdc++.h>
using namespace std;
#include<vector>
/////////////////////////////////////////----------->>>>>>.tabulation
int lcs(string &s, string &t)
{
    // Write your code here
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    int ans = 0;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                ans = max(ans, dp[ind1][ind2]);
            }

            else
                dp[ind1][ind2] = 0;
        }
    }
    return ans;
}




#include <bits/stdc++.h> 
using namespace std;
#include<vector>
/////////////////////////////////////////----------->>>>>>.space optimisation
int lcs(string &s, string &t)
{
	//Write your code here
	int n= s.size();
	int m= t.size();
	vector<int>prev(m+1,0), curr(m+1,0);
	for(int j=0; j<=m; j++) prev[j]=0;
	for(int i=0; i<=n; i++) prev[0]=0;

	int ans=0;
	for(int ind1=1; ind1<=n; ind1++){
		for(int ind2=1; ind2<=m; ind2++){
			if(s[ind1-1]==t[ind2-1]){
		 	 	curr[ind2]= 1+ prev[ind2-1];
			 	ans= max(ans,curr[ind2]);
		}

		 else curr[ind2]=0;
		}
		prev=curr;
	}
return ans;
	
}
