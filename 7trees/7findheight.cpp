#include<iostream>
#include"2Treenode.h"
using namespace std;


int getHeight(TreeNode<int> *root)
{
    int height=1;
    vector <int> childheight;
    for (int i = 0; i < root->children.size(); i++)
    {
        childheight.push_back(getHeight(root->children[i]));
    }
    int max=0;
    for (int i = 0; i < childheight.size(); i++)
    {
        if (childheight[i]>max)
        {
            max=childheight[i];
        }
        
    }
    height+=max;
    return height;
}
int main()
{

return 0;
}