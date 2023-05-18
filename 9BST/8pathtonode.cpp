#include<iostream>
// #include"1BinaryTree.h"
#include<queue>
#include "1.1linkedlis.h"
#include "BSTclass.h"
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

vector<int> * pathToNode(BinaryTree<int>*root, int data)

{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==data)
    {
        vector<int> *output= new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftoutput= pathToNode(root->left, data);
    if(leftoutput!=NULL)
    {
        leftoutput->push_back(root->data);
        return leftoutput;
    }
    vector<int> *rightoutput= pathToNode(root->right, data);
    if(rightoutput!=NULL)
    {
        rightoutput->push_back(root->data);
        return rightoutput;
    }
    else
    return NULL;

    

}
int main()
{
//  BinaryTree<int> *root= takeInputLevelWise();
//  vector<int> *ans= pathToNode(root, 2);

//  for(int i=0; i<ans->size();i++)
//  {
//     cout<<ans->at(i);
//  }
//  delete ans;

BST b;
b.insert(3);
b.insert(34);
b.insert(6);
b.insert(6);
b.insert(45);
b.insert(35);
b.printTree();
}