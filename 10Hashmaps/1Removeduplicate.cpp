#include<iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicate(int *a, int size)
{
    vector<int> output;
    unordered_map<int,bool> seen;

    for(int i=0; i<size; i++)
    {
        if(seen.count(a[i])>0)
        {
            continue;
        }

        seen[a[i]]= true;
        output.push_back(a[i]);

    }
        return output;

}




int main()
{
    int a[]={1,4,4,3,2,2,5,5,5,6};
    int size=10;
    vector <int> ans= removeDuplicate(a,size);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

return 0;
}