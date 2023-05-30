#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////------------->>>>>>>>>question is same to previous koshan
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<bool> prev(k + 1, false);

    prev[0] = true;

    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> cur(k + 1, false);
        cur[0] = true;
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = prev[target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];

            cur[target] = notTaken || taken;
        }
        prev = cur;
    }

    return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.

    int totsum = 0;
    for (int i = 0; i < n; i++)
        totsum += arr[i];

    if (totsum % 2)
        return false;

    int target = totsum / 2;
    return subsetSumToK(n, target, arr);
}
