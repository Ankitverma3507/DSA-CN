#include <iostream>
#include "1BinaryTree.h"
#include <vector>
#include <queue>

using namespace std;

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

BinaryTree<int> *makeBST(vector<int> &arr, int st, int end)
{

    if (st > end)
    {
        BinaryTree<int> *ans = NULL;
        return ans;
    }
    int mid = (st + end) / 2;

    BinaryTree<int> *root = new BinaryTree<int>(arr[mid]);

    root->left = makeBST(arr, st, mid - 1);
    root->right = makeBST(arr, mid + 1, end);

    return root;




    
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);


    BinaryTree<int> *root = makeBST(arr, 0, arr.size()-1);
    printTreeLevelWise(root);

    return 0;
}