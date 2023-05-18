#include<iostream>
#include"2Treenode.h"
using namespace std;

void printNodeLevelK(TreeNode<int>*root, int k)
{
    if(root==NULL){return;}
    if(k==0)//base case
    {
        cout<<root->data<<endl;
    }

    for(int i=0; i<root->children.size();i++)
    {
        printNodeLevelK(root->children[i], k-1);
    }
}
int main()
{

return 0;
}