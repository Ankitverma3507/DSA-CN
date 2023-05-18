#include <iostream>
#include <queue>
#include "1.1linkedlis.h"
#include "BSTclass.h"
#include <bits/stdc++.h>

using namespace std;

BinaryTree<int> *takeInputLevelWise()
{
    int rootdata;
    cout << "Enter the root data" << endl;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }

    BinaryTree<int> *root = new BinaryTree<int>(rootdata);
    queue<BinaryTree<int> *> pendingnodes;
    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {
        BinaryTree<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "Enter the left child of " << front->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            BinaryTree<int> *child = new BinaryTree<int>(leftData);
            front->left = child;
            pendingnodes.push(child);
        }

        cout << "Enter the right child of " << front->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            BinaryTree<int> *child = new BinaryTree<int>(rightData);
            front->right = child;
            pendingnodes.push(child);
        }
    }
    return root;
}
void printTreeLevelWise(BinaryTree<int> *root)
{
    queue<BinaryTree<int> *> pendingNode;
    pendingNode.push(root);

    while (pendingNode.size() != 0)
    {
        BinaryTree<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << front->data << ":";

        BinaryTree<int> *leftchild = front->left;
        if (front->left != NULL)
        {
            cout << "L" << leftchild->data << " ";
            pendingNode.push(leftchild);
        }

        BinaryTree<int> *rightchild = front->right;
        if (front->right != NULL)
        {
            cout << "R" << rightchild->data << " ";
            pendingNode.push(rightchild);
        }
        cout << endl;
    }

    // printTree(root->left);
    // printTree(root->right);
    return;
}


void printAtdistanceK(BinaryTree<int> * root, int k) {
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		cout << root->data << " ";
	}

	printAtdistanceK(root->left, k - 1);
	printAtdistanceK(root->right, k - 1);

}

// int nodesatK(BinaryTree<int> *root, int targetnode, int k)
// {
//     if(root==NULL)
//     {return -1;}

//     if(root->data==targetnode)
//     {
//         printAtdistanceK(root,k);
//         return 0;
//     }

//     int ld= nodesatK(root->left, targetnode, k);
//     if(ld!=-1)
//     {
//         if(ld+1==k)
//         {
//             cout<<root->data<<endl;        }
//         else
//         {
//             printAtdistanceK(root->right, (k=ld-2));
//         }
//     return ld + 1;

//     }

//     else {
//     int rd= nodesatK(root->right, targetnode,k);
//     if(rd!=-1)
//     {
//         if(rd+1==k)
//         {
//             cout<<root->data<<endl;        }
//         else
//         {
//             printAtdistanceK(root, k-rd-2);
//         }
//     }
//      return rd+1;
//     }

// return -1;
// }



int printNodeatK(BinaryTree<int> * root, int target, int k) {
	if (root == NULL) {
		return -1;
	}


	if (root->data == target) {
		printAtdistanceK(root, k );
		return 0;
	}

	int ld = printNodeatK(root->left, target, k);

	if (ld != -1) {

		if (ld + 1 == k) {
			cout << root->data << endl;
		}
		else {
			printAtdistanceK(root->right, (k - ld - 2));
			//return k - ld - 2;
		}
		return ld + 1;
	}

	else {

		int rd = printNodeatK(root->right, target, k);

		if (rd != -1) {
			if (rd + 1 == k) {
				cout << root->data << endl;
			}
			else {
				printAtdistanceK(root->left, (k - rd - 2));
				//return (k - rd - 2);
			}
			return rd + 1;
		}
	}

	return -1;

}


int main()
{
    BinaryTree<int>*root= takeInputLevelWise();
    int ans=printNodeatK(root,3,3);

    return 0;
}