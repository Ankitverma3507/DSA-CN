#include <bits/stdc++.h> 
using namespace std;

long long int maximumsum(vector<int> &arr)
{
    int n= arr.size();
    long long int prev= arr[0];
    long long int prev2= 0;

    for(int i =0; i<n; i++)
    {
        long long int take= arr[i];
        if(i>1)
        take+= prev2;

        long long int nottake= 0+ prev;

        long long int curri= max(take,nottake);
        prev2=prev;
        prev=curri;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n= valueInHouse.size();
    vector<int> temp1, temp2;
    if(n==1) return valueInHouse[0];
    for(int i=0; i<n; i++)
    {
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i !=n-1) temp2.push_back(valueInHouse[i]);
    }

    return max(maximumsum(temp1), maximumsum(temp2));
}