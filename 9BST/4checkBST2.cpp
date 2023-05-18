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

class BSTornot
{
    public:
    bool isBsT;
    int minimum;
    int maximum;
};

BSTornot checkBST(BinaryTree<int> *root)
{
    if(root==NULL)
    {
        BSTornot ans;
        ans.isBsT= true;
        ans.minimum= INT8_MAX;
        ans.maximum= INT8_MIN;

        return ans;
    }


    BSTornot leftoutput= checkBST(root->left);
    BSTornot rightoutput= checkBST(root->right);

    int minimum= min(root->data, min(leftoutput.minimum, rightoutput.minimum));
    int maximum= max(root->data, max(leftoutput.maximum, rightoutput.maximum));
    bool isBSTfinal= (root->data>leftoutput.maximum) and (root->data<=rightoutput.minimum) and leftoutput.isBsT and rightoutput.isBsT;

    BSTornot ans;
    ans.minimum= minimum;
    ans.maximum= maximum;
    ans.isBsT= isBSTfinal;
    return ans;
}

int main()
{
BinaryTree<int> *root= takeInputLevelWise();
cout<<checkBST(root).isBsT;
}