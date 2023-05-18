#include<iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include<vector>
#include <string.h>
using namespace std;




vector<int> longestConsecutive(int *arr, int n) 
{
    unordered_map <int,bool>mpp;
    vector<int> ans;

    for(int i=0; i<n; i++)
    {
        mpp[arr[i]]= true;
    }

    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        if(mpp.count(arr[i]-1)==0)
        {
            temp.push_back(arr[i]);

            // int t=1;
            while (mpp.count(arr[i]+1))
            {
                temp.push_back(arr[i]+1);
                arr[i]++;
            }

            if(temp.size()> ans.size())
            {
                ans=temp;
            }
            
        }
    }

    int n1= ans[0];
    int n2= ans[ans.size()-1];
    ans.clear();
    ans.push_back(n1);
    ans.push_back(n2);
    return ans;

}

int main()
{
    int a[]={2,12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    int size=13;

    vector<int> ans=longestConsecutive(a,13);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}