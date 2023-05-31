#include <bits/stdc++.h>
#include<string>
using namespace std;
int longestBitonicSequence(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] and dp1[j] + 1 > dp1[i])
            {
                dp1[i] = 1 + dp1[j];
            }
        }
    }

    vector<int> dp2(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i] and dp2[j] + 1 > dp2[i])
            {
                dp2[i] = 1 + dp2[j];
            }
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}
