#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>normal recursion

int f(int ind1, int ind2, string s, string t)
{
	if (ind1 < 0 or ind2 < 0)
		return 0;

	if (s[ind1] == t[ind2])
	{
		return 1 + f(ind1 - 1, ind2 - 1, s, t);
	}

	return 0 + max(f(ind1 - 1, ind2, s, t), f(ind1, ind2 - 1, s, t));
}

int lcs(string s, string t)
{
	// Write your code here
	int n = s.size();
	int m = t.size();
	return f(n - 1, m - 1, s, t);
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>Memoization

int f(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp)
{
	if (ind1 < 0 or ind2 < 0)
		return 0;
	if (dp[ind1][ind2] != -1)
		return dp[ind1][ind2];
	if (s[ind1] == t[ind2])
	{
		return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, s, t, dp);
	}

	return dp[ind1][ind2] = 0 + max(f(ind1 - 1, ind2, s, t, dp), f(ind1, ind2 - 1, s, t, dp));
}

int lcs(string s, string t)
{
	// Write your code here
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n, vector<int>(m, -1));
	return f(n - 1, m - 1, s, t, dp);
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>tabulatin
int lcs(string s, string t)
{
	// Write your code here
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	for (int j = 0; j <= m; j++)
		dp[0][j] = 0;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;

	for (int ind1 = 1; ind1 <= n; ind1++)
	{
		for (int ind2 = 1; ind2 <= m; ind2++)
		{
			if (s[ind1 - 1] == t[ind2 - 1])
			{
				dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
			}

			else
				dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
		}
	}

	return dp[n][m];
}

#include <bits/stdc++.h>
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>space opt
int lcs(string s, string t)
{
	// Write your code here
	int n = s.size();
	int m = t.size();
	vector<int> prev(m + 1, 0), curr(m + 1, 0);
	for (int j = 0; j <= m; j++)
		prev[j] = 0;
	// for(int i=0; i<=n; i++) prev[0]=0;//coz their will be no columns

	for (int ind1 = 1; ind1 <= n; ind1++)
	{
		for (int ind2 = 1; ind2 <= m; ind2++)
		{
			if (s[ind1 - 1] == t[ind2 - 1])
			{
				curr[ind2] = 1 + prev[ind2 - 1];
			}

			else
				curr[ind2] = 0 + max(prev[ind2], curr[ind2 - 1]);
		}
		prev = curr;
	}

	return prev[m];
}