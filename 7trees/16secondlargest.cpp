#include<iostream>
#include"2Treenode.h"
using namespace std;

pair<int, int> secondLargest(TreeNode<int>*root){

    pair<int, int> ans;
    ans.first= root->data;
    ans.second= NULL;

    for(int i=0; i<root->children.size(); i++)
    {
        pair<int,int> temp= secondLargest(root->children[i]);
        temp.first=root->children[i]->data;
        

        if(ans.first<temp.first)
        {
            int x= ans.first;
            ans.first=temp.first;
            
            if(ans.second==NULL and temp.second==NULL)
            {
                ans.second=x;
            }

            else if(ans.second==NULL and temp.second!=NULL)
            {
                if(x<temp.second)
                {
                    ans.second=temp.second;
                }
                else
                {
                    ans.second=temp.first;
                }
            }

            else if(ans.second!=NULL and temp.second==NULL)
            {
                ans.second=x;
            }

            else
            {
                if(x>ans.second)
                {ans.second=x;}
            }
        }

        else
        {
            if(ans.second==NULL and temp.second==NULL)
            {
                ans.second=temp.first;
            }

            else if(ans.second!=NULL and temp.second==NULL)
            {
                if(ans.second<temp.first)
                {
                    ans.second=temp.first;
                }
            }

            else
            {
                if(ans.second<temp.first)
                {
                    ans.second=temp.first;
                }
            }
        }
    }

    return ans;
}


//By Yuvraj
pair<int, int> secondLargestNode(TreeNode<int> * root) {
	pair<int, int> ans(root->data, - 1);
	//(max,secondmax)

	for (int i = 0; i < root->children.size(); i++) {

		pair<int, int> smallans = secondLargestNode(root->children[i]);

		if (smallans.first > ans.first) {
			ans.second = ans.first;
			ans.first = smallans.first;

		}
		else {
			if (smallans.first > ans.second) {
				ans.second = smallans.first;
			}
		}

	}

	return ans;
}
int main()
{

return 0;
}