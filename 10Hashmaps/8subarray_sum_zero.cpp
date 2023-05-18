#include<iostream>
#include<iostream>
#include<iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include<vector>
using namespace std;


int longest_subarr_sum_to_zero(int *a, int size)
{
    unordered_map<int, int> mpp;
    int sum=0; int length=0;
    for(int i=0; i<size; i++)
    {
        sum = sum+ a[i];
        if(a[i]==0 and length==0)
        length=1;

        else if(sum==0)
        length= i+1;

        else if(mpp.count(sum)>0)
        length= max(length,i- mpp[sum]);

        else
        mpp[sum]=i;
    }
    return length;
}

int main()
{
int a[]= { 95, -97, -387, -435, -5, -70, 897, 127, 23, 284};
int size=10;

cout<<"ans is "<<longest_subarr_sum_to_zero(a,size);

return 0;
}