#include <bits/stdc++.h> 
using namespace std;
/////////////////------------------------>>>>>>>>>>normal recursion
bool f(int i, int j,string &pattern, string &text ){
   if(i<0 and j<0) return  true;
   if(i<0 and j>=0) return false;
   if(i>=0 and j<0){
      for(int ind=i; ind>=0; ind--){
         if(pattern[ind] != '*')
         return false;
      }
         return true;
   }

   if(pattern[i]== text[j] or pattern[i]=='?'){
      return f(i-1,j-1,pattern,text);
   }

   if(pattern[i]=='*'){
      return f(i-1,j,pattern,text) | f(i,j-1,pattern,text);
   }

   
   return false;

}


bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n= pattern.size();
   int m= text.size();
   return f(n-1,m-1,pattern,text);
}




#include <bits/stdc++.h> 
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>memoization
bool f(int i, int j,string &pattern, string &text,vector<vector<int>>&dp ){
   if(i<0 and j<0) return  true;
   if(i<0 and j>=0) return false;
   if(i>=0 and j<0){
      for(int ind=i; ind>=0; ind--){
         if(pattern[ind] != '*')
         return false;
      }
         return true;
   }
   if(dp[i][j]!=-1) return dp[i][j];

   if(pattern[i]== text[j] or pattern[i]=='?'){
      return dp[i][j]=f(i-1,j-1,pattern,text,dp);
   }

   if(pattern[i]=='*'){
      return dp[i][j]=f(i-1,j,pattern,text,dp) | f(i,j-1,pattern,text,dp);
   }

   
   return dp[i][j]=false;

}


bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n= pattern.size();
   int m= text.size();
   vector<vector<int>>dp(n,vector<int>(m,-1));
   return f(n-1,m-1,pattern,text,dp);
}





#include <bits/stdc++.h> 
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>memoization with right shifting
bool f(int i, int j,string &pattern, string &text,vector<vector<int>>&dp ){
   if(i==0 and j==0) return  true;
   if(i==0 and j>0) return false;
   if(i>0 and j==0){
      for(int ind=i; ind>=1; ind--){
         if(pattern[ind-1] != '*')
         return false;
      }
         return true;
   }
   if(dp[i][j]!=-1) return dp[i][j];

   if(pattern[i-1]== text[j-1] or pattern[i-1]=='?'){
      return dp[i][j]=f(i-1,j-1,pattern,text,dp);
   }

   if(pattern[i-1]=='*'){
      return dp[i][j]=f(i-1,j,pattern,text,dp) | f(i,j-1,pattern,text,dp);
   }

   
   return dp[i][j]=false;

}


bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n= pattern.size();
   int m= text.size();
   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   return f(n,m,pattern,text,dp);
}








#include <bits/stdc++.h> 
using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>tabulation with right shifting


bool isAllStars(string & S1, int i) {

  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}

bool wildcardMatching(string & S1, string & S2) {

  int n = S1.size();
  int m = S2.size();

  vector < vector < bool >> dp(n + 1, vector < bool > (m, false));

  dp[0][0] = true;

  for (int j = 1; j <= m; j++) {
    dp[0][j] = false;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = isAllStars(S1, i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];

      else {
        if (S1[i - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

        else dp[i][j] = false;
      }
    }
  }

  return dp[n][m];

}









#include <bits/stdc++.h>

using namespace std;
//////////////////-------------------------->>>>>>>>>>>>>>>space optimisation

bool isAllStars(string & S1, int i) {

  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}

bool wildcardMatching(string & S1, string & S2) {

  int n = S1.size();
  int m = S2.size();

  vector < bool > prev(m + 1, false);
  vector < bool > cur(m + 1, false);

  prev[0] = true;

  for (int i = 1; i <= n; i++) {
    cur[0] = isAllStars(S1, i);
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        cur[j] = prev[j - 1];

      else {
        if (S1[i - 1] == '*')
          cur[j] = prev[j] || cur[j - 1];

        else cur[j] = false;
      }
    }
    prev = cur;
  }

  return prev[m];

}


















