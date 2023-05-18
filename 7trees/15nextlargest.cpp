#include <iostream>
#include "2Treenode.h"
using namespace std;

int NextLargest(TreeNode<int> *root, int n)
{
    int ans;
    if (root->data > n)
    {
        ans = root->data;
    }
    else
    {
        ans = 0;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        int temp = NextLargest(root->children[i], n);

        if (ans == 0)
        {
            ans = temp;
        }

        else
        {
            if (ans < temp)
            {
                return ans;
            }

            else
            {
                ans = temp;
            }
        }
    }

    if (ans < n)
    {
        return -1;
    }
    return ans;
}
int main()
{

    return 0;
}