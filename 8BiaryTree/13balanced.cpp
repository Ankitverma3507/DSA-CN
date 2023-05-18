#include <iostream>
#include "1BinaryTree.h"
#include <queue>
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

// int heightOfBinaryTree(BinaryTree<int>* root)
// {
//     if(root == NULL){return 0;}

//     int leftheight= 1+ heightOfBinaryTree(root->left);
//     int rightheight= 1+ heightOfBinaryTree(root->right);

//     if(leftheight>rightheight){return leftheight;}
//     else return rightheight;
// }


// bool isBalanced(BinaryTree<int> *root)
// {
//     if(root==NULL){return true;}

//     int leftHeight= heightOfBinaryTree(root->left);
//     int rightHeight= heightOfBinaryTree(root->right);

//     if(leftHeight-rightHeight == 1 or leftHeight-rightHeight==0)

//     {return true;}
//     else
//     return false;

// }

//------------------->Havin time complexicity O(n);
pair<bool, int> isBalancedhelper(BinaryTree<int> *root){

    if(root==NULL)
    {
        pair<bool, int> p;
        p.first= true;
        p.second=0;
        return p;
    }

    pair<bool, int> leftNode= isBalancedhelper(root->left);
    pair<bool, int> rightNode= isBalancedhelper(root->right);

    pair <bool, int> ans;

    if(leftNode.first != rightNode.first)
    {
        ans.first= false;
        ans.second= 1+ max(leftNode.second, rightNode.second);
    }

    else
    {
        if((leftNode.second- rightNode.second) <=1)
        {
            ans.first= true;
            ans.second= 1+  max(leftNode.second, rightNode.second);
        }
        else
        {ans.first= false;
        ans.second= 1+  max(leftNode.second, rightNode.second);}
    }

    return ans;
}


bool isBalanced( BinaryTree<int> *root)
{
    return isBalancedhelper(root).first;
}
int main()
{
 BinaryTree<int> *root= takeInputLevelWise();

cout<<"Answer is "<<isBalanced(root);
}