#include<iostream>
#include"1BinaryTree.h"
#include<queue>
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
    if(root == NULL)
    {return INT8_MAX;}

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTree<int> *root)
{
    if(root==NULL)
    {return INT8_MIN;}

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool checkBST(BinaryTree<int> * root)
{
    if(root==NULL){return true;}
    int rightmin= minimum(root->right);
    int leftmax= maximum(root->left);

    bool output= (root->data>leftmax) and (root->data<=rightmin) and checkBST(root->right) and checkBST(root->left);
    return output;
}
int main()
{
BinaryTree<int> *root= takeInputLevelWise();
cout<<checkBST(root);
return 0;
}