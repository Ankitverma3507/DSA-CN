#include <iostream>
#include "1BinaryTree.h"
#include "queue"
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

BinaryTree<int> *treeusingINPOhelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    BinaryTree<int> *root = new BinaryTree<int>(pre[preS]);
    // for left

    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == pre[preS])
        {
            rootIndex = i;
        }
    }

    int LinS = inS;
    int LinE = rootIndex - 1;
    int LpreS = preS + 1;
    int LpreE = LinE - LinS + LpreS;

    // for right//
    int RinS = rootIndex + 1;
    int RinE = inE;

    int RpreS = LpreE + 1;
    int RpreE = preE;

    // done now recursive calls and connect em
    BinaryTree<int> *leftchild = treeusingINPOhelper(in, pre, LinS, LinE, LpreS, LpreE);
    BinaryTree<int> *rightchild = treeusingINPOhelper(in, pre, RinS, RinE, RpreS, RpreE);

    root->left = leftchild;
    root->right = rightchild;

    return root;
}

BinaryTree<int> *builtTree(int *In, int *pre, int size)
{
    return treeusingINPOhelper(In, pre, 0, size - 1, 0, size - 1);
}

void inroderTraversal(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    inroderTraversal(root->left);
    cout << root->data << " " << endl;
    inroderTraversal(root->right);
}

int main()
{
    int In[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};

    BinaryTree<int> *root = builtTree(In, pre, 9);
    printTreeLevelWise(root);
    cout << endl;

    inroderTraversal(root);

    return 0;
}