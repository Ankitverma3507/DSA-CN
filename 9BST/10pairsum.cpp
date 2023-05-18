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

vector<int> * treeArray(BinaryTree<int> * root) {
	if (root == NULL) {
		vector<int> *  ans  = new vector<int>();
		return ans;
	}
	vector<int> *  ans  = new vector<int>();
	vector<int> *  leftoutput  = new vector<int>();
	vector<int> *  rightoutput  = new vector<int>();

	leftoutput = treeArray(root->left);
	rightoutput = treeArray(root->right);

	ans->push_back(root->data);
	for (int i = 0; i < leftoutput->size(); i++) {
		ans->push_back(leftoutput->at(i));
	}
	for (int i = 0; i < rightoutput->size(); i++) {
		ans->push_back(rightoutput->at(i));
	}

	return ans;

}

void pairsum(BinaryTree<int> *root, int sum)
{
    if(root==NULL)
    {
        return;
    }

    vector<int> * arr= treeArray(root);
    sort(arr->begin(), arr->end());

    int i= 0;
    int j= arr->size()-1;

    while(i<j)
    {
        if(arr->at(i) + arr->at(j)==sum)
        {
            cout<<arr->at(i)<<" "<<arr->at(j);
            cout<<endl;
            i++;
            j--;
        }

        else if(arr->at(i)+ arr->at(j)>sum)
        {
            j--;
        }

        else
        {i++;}

    }

}

int main()
{
    BinaryTree<int> *root= takeInputLevelWise();

    pairsum(root, 12);
}

