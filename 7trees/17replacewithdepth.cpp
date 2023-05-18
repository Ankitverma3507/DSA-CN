#include<iostream>
#include "2Treenode.h"

void replaceWtihnode(TreeNode<int>*root, int k)
{
    
    root->data=k;

    for(int i=0; i<root->children.size(); i++)
    {
        replaceWtihnode(root->children[i], k+1);
        
    }

    return;
}
using namespace std;
int main()
{

return 0;
}