#include<iostream>
#include "2Treenode.h"
using namespace std;
//preorder
void preorderTraversal(TreeNode<int>* root)
{
    cout<<root->data<<" ";
    for(int i=0; i<root->children.size();i++)
    {
        preorderTraversal(root->children[i]);
    }
}

// postorder
void postorder(TreeNode<int>* root)
{
    if(root==NULL){return ;}
    if(root->children.size()==0){cout<<root->data<<" ";}

    for(int i=0; i<root->children.size();i++)
    {
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";//at the end data of the root node will be printed
}
int main()
{

return 0;
}