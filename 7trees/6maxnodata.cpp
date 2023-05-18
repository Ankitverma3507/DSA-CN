#include <iostream>
#include "2Treenode.h"
using namespace std;

TreeNode<int> *maxNode(TreeNode<int> *root)
{
    TreeNode<int> *max = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *max2 = maxNode(root->children[i]);
        if (max2->data > max->data)
        {
            max = max2;
        }
    }
    return max;
}
int main()
{

    return 0;
}