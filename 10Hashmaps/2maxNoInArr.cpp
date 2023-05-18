#include<iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include<vector>
using namespace std;


int maxNuinArr(vector<int> &arr, int n)
{
    unordered_map <int,int> ans;
    int maxFreq=0;
    int maxAns=0;
    for(int i=0 ; i<arr.size(); i++)
    {
            ans[arr[i]]++;
            maxFreq= max(maxFreq,ans[arr[i]]);
    }

    for(int i=0; i<arr.size(); i++)
    {
        if(maxFreq== ans[arr[i]])
        {
            maxAns= arr[i];
            break;
        }
    }
    return maxAns;

}

int main()
{
    vector<int> a={2,12,2,11,12,2,1,2,2,11,12,2,6};
    int size=13;
    cout<< "ans is "<<maxNuinArr(a,size);
    return 0;
}