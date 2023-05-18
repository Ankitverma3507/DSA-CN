#include<iostream>
#include"1BinaryTree.h"
#include<queue>
#include "1.1linkedlis.h"
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


pair<Node *, Node *> BSTtoLL(BinaryTree<int> *root)
{
    if(root==NULL){
        pair <Node*, Node*>ans;
        ans.first=NULL;
        ans.second=NULL;
        return ans;
    }

    Node * middle= new Node (root->data);

    pair <Node*, Node*> left= BSTtoLL(root->left);
    pair <Node*, Node*> right= BSTtoLL(root->right);

    Node *lhead= left.first;
    Node *ltail= left.second;
    Node *rhead= right.first;
    Node *rtail= right.second;

    pair <Node* , Node*> ans;
    if(lhead!=NULL and rhead!=NULL)
    {
        ltail->next= middle;
        middle->next= rhead;

        ans.first= lhead;
        ans.second= rtail;
    }

    else if (lhead!=NULL and rhead==NULL)
    {
        ltail->next= middle;
        
        ans.first=lhead;
        ans.second= middle;
    }

    else if (lhead==NULL and rhead!=NULL)
    {
        middle->next= rhead;

        ans.first=middle;
        ans.second= rtail;
    }

    else {
		//lhead == NULL and rhead == NULL
		ans.first = middle;
		ans.second = middle;
	}



    return ans;

}
int main()
{
BinaryTree<int> *root= takeInputLevelWise();
Node *head= BSTtoLL(root).first;
print(head);
}
