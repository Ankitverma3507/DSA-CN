#include <bits/stdc++.h> 
using namespace std;
////////////////////-------------------------->>>>>>>>>>>Normal recursion
int f(int ind, int previn,int arr[], int n){
    if(ind==n) return 0;

    int nottake= 0+ f(ind+1, previn,arr,n);
    int take=0; 
    if(previn==-1 or arr[ind]> arr[previn]){
        take= 1+ f(ind+1, ind,arr,n);
    }
    return max(nottake,take) ;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
    return f(0,-1,arr,n);
}












/////////////-----------------finaly submitted code run all  test case


#include <bits/stdc++.h> 



int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    temp.push_back(arr[0]);
    int length=1;
    for(int i=1; i<n; i++){
      if (arr[i] > temp.back()) {
        temp.push_back(arr[i]);
        length++;
      }

      else {
        int ind = lower_bound(temp.begin(), temp.end(), arr[i])- temp.begin();
        temp[ind] = arr[i];
      }
    }

    return length;



}










#include <bits/stdc++.h> 
using namespace std;
////////////////////-------------------------->>>>>>>>>>>tabulation


int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
       vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       for(int ind=n-1; ind>= 0 ; ind--){
           for(int previn= ind-1; previn>=-1; previn--){
                int nottake= 0+ dp[ind+1][previn+1];
                int take=0; 
                if(previn==-1 or arr[ind]> arr[previn]){
                    take= 1+ dp[ind+1][ind+1];
                }
                 dp[ind][previn+1]=max(nottake,take) ;

           }
       }
    return dp[0][-1+1];
}
