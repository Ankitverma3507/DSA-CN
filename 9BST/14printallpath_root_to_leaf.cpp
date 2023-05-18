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


//------->print all the paths from root to leaf
void helper(BinaryTree<int> *root, vector<int> path, vector<vector<int>> &allpaths)
{
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);
    if (root->left == NULL and root->right == NULL)
    {
        allpaths.push_back(path);
    }

    helper(root->left, path, allpaths);
    helper(root->right, path, allpaths);
}

vector<vector<int>> Paths(BinaryTree<int> *root)
{
    // Code here

    vector<vector<int>> allpaths;
    vector<int> path;

    helper(root, path, allpaths);
    return allpaths;
}




int main()
{
    BinaryTree<int> *root= takeInputLevelWise();
    vector<vector<int>> ans= Paths(root);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}