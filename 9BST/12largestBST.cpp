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

int minimum(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return INT8_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return INT8_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool checkBST(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int rightmin = minimum(root->right);
    int leftmax = maximum(root->left);

    bool output = (root->data > leftmax) and (root->data <= rightmin) and checkBST(root->right) and checkBST(root->left);
    return output;
}

class largestBST
{
public:
    int min;
    int max;
    bool isbst;
    int heightoflarBST;
};

largestBST BSTlargest(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        largestBST ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isbst = true;
        ans.heightoflarBST = 0;
        return ans;
    }

    largestBST leftOutput = BSTlargest(root->left);
    largestBST rightOutput = BSTlargest(root->right);

    if(leftOutput.isbst and rightOutput.isbst and leftOutput.max<root->data and rightOutput.min>= root->data)
    {
        largestBST output;
        output.min= min(root->data, min(leftOutput.min, rightOutput.min));
        output.max= max(root->data,max(leftOutput.max, rightOutput.max));
        output.isbst= true;
        output.heightoflarBST =1+ max(leftOutput.heightoflarBST, rightOutput.heightoflarBST);
        return output;
    }

    else
    {
        largestBST output;
        output.min= min(root->data, min(leftOutput.min, rightOutput.min));
        output.max= max(root->data,max(leftOutput.max, rightOutput.max));
        output.isbst= false;
        output.heightoflarBST= max(leftOutput.heightoflarBST, rightOutput.heightoflarBST);
        return output;
    }


}


int main()
{
    BinaryTree<int> *root= takeInputLevelWise();
    cout<<"ans is "<<BSTlargest(root).heightoflarBST<<endl;
    return 0;
}


