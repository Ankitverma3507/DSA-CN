#include<iostream>
#include"2Treenode.h"
using namespace std;


int NoOfLeafNode(TreeNode<int>*root)
{
    if(root==NULL){return 0;}
    int count;
    if(root->children.size()==0)
    {
        count=1;
    }
    else {count=0;}

    for(int i=0; i<root->children.size();i++)
    {
        count+= NoOfLeafNode(root->children[i]);
    }

    return count;
}
int main()
{

return 0;
}