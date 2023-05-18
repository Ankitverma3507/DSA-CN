#include<iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include<vector>
#include <string.h>
using namespace std;

void uniqueCharacter(string s, int size)
{
    unordered_map <char,int> ans;

    for(int i=0; i<size; i++)
    {
        if(ans.count(s[i])>0)
        {continue;}

        else
        {
            ans[s[i]]=true;
            cout<<s[i];
        }
    }

    return ;
}
using namespace std;
int main()
{


string s;
// int size= s.size();
cout<<"enter string ";
cin>>s;
uniqueCharacter(s,5);

return 0;
}