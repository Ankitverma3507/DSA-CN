#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>.normal recursion
int f(int i, int j,vector<int> &arr, int N ){
    if(i==j) return 0;
    int mini= 1e9;
    for(int k=i; k<=j-1; k++){
        int operations= arr[i-1]*arr[j]*arr[k] + f(i,k,arr,N) + f(k+1,j,arr,N);
        mini= min(mini, operations);
    }

    return mini;
}


int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    return f(1,N-1,arr,N);

}






#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>.memoization
int f(int i, int j,vector<int> &arr, int N,vector<vector<int>> &dp ){
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini= 1e9;
    for(int k=i; k<=j-1; k++){
        int operations= arr[i-1]*arr[j]*arr[k] +
         f(i,k,arr,N,dp) + f(k+1,j,arr,N,dp);
        mini= min(mini, operations);
    }

    return dp[i][j]=mini;
}


int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N,-1));
    return f(1,N-1,arr,N,dp);

}





#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>.Tabulation

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    int dp[N][N];
    for(int i=1; i<N; i++) dp[i][i]=0;

    for(int i= N-1; i>=1; i-- ){
        for(int j= i+1; j<N; j++){
                    int mini= 1e9;
            for(int k=i; k<=j-1; k++){
                int operations= arr[i-1]*arr[j]*arr[k] +
                dp[i][k] + dp[k+1][j];
                mini= min(mini, operations);
            }

             dp[i][j]=mini;
        }
    }
    return dp[1][N-1];

}