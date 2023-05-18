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

int height(BinaryTree<int> *root)

{
    if(root==NULL){return 0;}

    return 1+ max(height(root->left), height(root->right));
}


int diameter(BinaryTree<int> *root)
{
    if(root==NULL){return 0;}

    int option1= height(root->left) + height(root->right);
    int option2= diameter(root->left);
    int option3= diameter(root->right);

    return max(option1, max(option2, option3));
}


//------------->Better approach for diameter

pair<int, int> diameterheight(BinaryTree<int> *root)
{
    if(root==NULL)
    {
        pair<int, int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair <int , int > leftAns= diameterheight(root->left);
    pair <int , int > rightAns= diameterheight(root->right);
    int ld= leftAns.second;
    int lh= leftAns.first;
    int rd= rightAns.second;
    int rh= rightAns.first;

    int height= 1+ max(lh, rh);
    int diameter= max(lh+rh, max(rd, ld));

    pair<int, int> p;
    p.first= height;
    p.second= diameter;

    return p;

}
int main()
{
BinaryTree<int> *root= takeInputLevelWise();
pair<int, int> p= diameterheight(root);

cout<<"height is "<<p.first<<endl;
cout<<"diameter is "<<p.second<<endl;
return 0;
}