#include<iostream>
#include"2Treenode.h"
using namespace std;

int countNodesGreaterThanX(TreeNode<int>* root, int x)
{
    if(root==NULL){return 0;}
    int count=0;
    if(root->data>x)
    {
        count++;
    }
    for(int i=0; i<root->children.size();i++)
    {
        count+=countNodesGreaterThanX(root->children[i],x);

    }
    return count;
}
int main()
{

return 0;
}