#include<iostream>
#include "2Treenode.h"
using namespace std;

int numNodes(TreeNode<int> *root)
{
    int ans=1;
    for(int i=0; i<root->children.size(); i++)
    {
        ans=ans+ numNodes(root->children[i]);
    }
    return ans;
}

int sumNodes(TreeNode<int> *root)

{
    //Write your code here
    
    int ans=root->data;
    for(int i=0; i<root->children.size();i++ )
    {
        // ans+= root->data;  
        ans+=sumNodes(root->children[i]);
    }
    return ans;
}
int main()
{


return 0;
}