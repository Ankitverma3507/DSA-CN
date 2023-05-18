#include<iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include<vector>
using namespace std;

int pairSumToZero(int *arr, int n)
{
//         // Write your code here
    int count  = 0;
    unordered_map<int,int> mpp;
    
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    
    for(auto it = mpp.begin(); it != mpp.end(); it++)
    {
        int key = it->first;
        
        if(key != 0 and mpp.find(-key) != mpp.end()){
            count += (mpp[key] * mpp[-key]);
        }
    }
	
    if(mpp.find(0) != mpp.end()){
		int f = mpp[0];
        count += (f * (f - 1));
    }
    return count/2;
}

int main()
{
    int a[]= {2,3,-2,2,-3};
    int size =5;
    cout<<"ans is "<<pairSumToZero(a,size);


    return 0;
}