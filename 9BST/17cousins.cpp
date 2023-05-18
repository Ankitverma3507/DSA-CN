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

  int find_HeightParent(BinaryTree<int> *root,int &parent,int value,int height)
    {
        if(!root)
            return 0;
        if(root->data==value)
            return height;
        
        parent = root->data;
        int left = find_HeightParent(root->left,parent,value,height+1);
        if(left)
            return left;
        parent = root->data;
        int right = find_HeightParent(root->right,parent,value,height+1);
        return right;
    }

void paths(BinaryTree<int> *root, int k, vector<vector<int>>&allpath, vector<int> path)
{
    if(root==NULL){return;}

    path.push_back(root->data);

    if(root->data==k)
    {
        allpath.push_back(path) ;
    }

    paths(root->left,k,allpath, path);
    paths(root->right,k,allpath, path);

    return;
}

 bool isCousins(BinaryTree<int>* root, BinaryTree<int>* x, BinaryTree<int>* y) {
        if(root==NULL){return true;}
        
        if(root->data==x->data || root->data==y->data)
            return false;
            
        int parent=-1;
        int xHeight = find_HeightParent(root,parent,x->data,0);
        
        int yParent=-1;
        int yHeight = find_HeightParent(root,yParent,y->data,0);
        
        if(parent!=yParent && xHeight==yHeight)
            return true;        
        return false;
    }

int main()
{
    BinaryTree<int> *root= takeInputLevelWise();
    // int m,n;
    // cout<<"enter k ";
    // cin>>m>>n;

    // cout<<height(root,m)<<" " ;
    // cout<<height(root,n);


    BinaryTree<int> *p= new BinaryTree<int>(2);
    BinaryTree<int> *q= new BinaryTree<int>(4);

    cout<<isCousins(root,p,q);
    return 0;
}