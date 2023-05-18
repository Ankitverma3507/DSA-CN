// #include<bits/stdc++.h>
#include<iostream>
#include"2Treenode.h"
using namespace std;

pair<TreeNode<int>*, int>  NodeWithMaxSum(TreeNode<int>*root)
{
    pair<TreeNode<int>*, int> ans;
    ans.first=root;
    ans.second=root->data;

    for(int i=0; i<root->children.size();i++)
    {
        ans.second+=root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int>*,int> subans= NodeWithMaxSum(root->children[i]);
        if(subans.second>ans.second)
        {
            ans=subans;
        }
    }
    return ans;
    
}
int main()
{

return 0;
}