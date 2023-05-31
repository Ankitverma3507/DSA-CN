#include <bits/stdc++.h>
using namespace std;
////////////////////-------------------------->>>>>>>>>>>Normal recursion
int f(int ind, int previn, int arr[], int n)
{
    if (ind == n)
        return 0;

    int nottake = 0 + f(ind + 1, previn, arr, n);
    int take = 0;
    if (previn == -1 or arr[ind] > arr[previn])
    {
        take = 1 + f(ind + 1, ind, arr, n);
    }
    return max(nottake, take);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return f(0, -1, arr, n);
}

/////////////-----------------finaly submitted code run all  test case

#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    temp.push_back(arr[0]);
    int length = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            length++;
        }

        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
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
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int previn = ind - 1; previn >= -1; previn--)
        {
            int nottake = 0 + dp[ind + 1][previn + 1];
            int take = 0;
            if (previn == -1 or arr[ind] > arr[previn])
            {
                take = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][previn + 1] = max(nottake, take);
        }
    }
    return dp[0][-1 + 1];
}

#include <bits/stdc++.h>
using namespace std;
////////////////////-------------------------->>>>>>>>>>>another approach tabulation

int longestIncreasingSubsequence(int arr[], int n)
{

    vector<int> dp(n, 1);

    for (int i = 0; i <= n - 1; i++)
    {
        for (int prev_index = 0; prev_index <= i - 1; prev_index++)
        {

            if (arr[prev_index] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev_index]);
            }
        }
    }

    int ans = -1;

    for (int i = 0; i <= n - 1; i++)
    {
        ans = max(ans, dp[i]);
    }

    return ans;
}

// to print LIS
#include <bits/stdc++.h>
using namespace std;

vector<int> divisibleSet(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);

    for (int i = 0; i <= n - 1; i++)
    {

        hash[i] = i; // initializing with current index
        for (int prev_index = 0; prev_index <= i - 1; prev_index++)
        {

            if (arr[prev_index] < arr[i] && 1 + dp[prev_index] > dp[i])
            {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i <= n - 1; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    while (hash[lastIndex] != lastIndex)
    { // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    // reverse the array
    reverse(temp.begin(), temp.end());

    cout << "The subsequence elements are ";

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;

    
}