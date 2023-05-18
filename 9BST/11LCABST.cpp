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

BinaryTree<int> * LCAofBST(BinaryTree<int> *root, BinaryTree<int> * n1, BinaryTree<int> * n2)
{
   if (root == NULL) {
		return NULL;
	}

	if (root->data == n1->data) {
		return n1;
	}
	if (root->data == n2->data) {
		return n2;
	}
        

    BinaryTree<int> * a= LCAofBST(root->left, n1, n2);
    BinaryTree<int> * b= LCAofBST(root->right, n1, n2);

    if(b ==NULL and a==NULL)
    {
        return NULL;
    }
    if(a !=NULL and b==NULL)
    {
        return a;
    }
    
    if(b !=NULL and a==NULL)
    {
        return b;
    }

    if(b !=NULL and a!=NULL)
    {
        return root;
    }
    
    
}


BinaryTree<int> * LCA_BST(BinaryTree<int> * root, BinaryTree<int> * n1, BinaryTree<int>* n2) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == n1->data) {
		return root;
	}

	if (root->data == n2->data) {
		return root;
	}

	if (n1->data < root->data and n2->data < root->data) {
		return LCA_BST(root->left, n1, n2);
	}
	else if (n1->data > root->data and n2->data > root->data) {
		return LCA_BST(root->right, n1, n2);
	}
	else {
		//opposite tree
		return root;
	}


}

int main()
{
    BinaryTree<int> *root= takeInputLevelWise();
    int n1, n2;
	cin >> n1 >> n2;
	BinaryTree<int> * first = new BinaryTree<int>(n1);
	BinaryTree<int> * second = new BinaryTree<int>(n2);
	if (!LCAofBST(root, first , second)) {
		cout << "NULL";
	}
	else {
		cout << LCAofBST(root, first, second)->data;
	}
    return 0;
}
