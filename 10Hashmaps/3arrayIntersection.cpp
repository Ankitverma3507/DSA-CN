#include<iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include<vector>
using namespace std;


vector<int> arrIntersection(int *a, int aSize, int *b, int bSize)
{
    unordered_map <int,int> amap;
    vector<int> output;

    for (int i=0; i<aSize; i++)
    {
        if(amap.count(a[i])==0)
        amap[a[i]]=1;

        else
        amap[a[i]]++;

    }

    for(int j=0;  j<bSize; j++)
    {
        if(amap.count(b[j])>0)
        {
            if(amap[b[j]] !=0)
            {
                output.push_back(b[j]);
                amap[b[j]]--;
            }
        }
    }

    return output;
}

int main()
{
    int a[]={2,6,8,5,4,3};
    int asize=6;

    int b[]={2,3,4,7};
    int bsize=4;

    vector<int> ans=arrIntersection(a,asize, b,bsize);

    for(int i=0; i<ans.size(); i++)
    {
        cout<< ans[i]<<" ";
    }
    return 0;
}