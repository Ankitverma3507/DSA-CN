#include <iostream>
#include "1BinaryTree.h"
#include <queue>
#include<vector>
#include"0NodeLL.h"

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

vector<Node *> levelwiseLL(BinaryTree<int> *root)
{
    vector<Node *> ans;
    if(root==NULL)
    {
        ans.push_back(NULL);
        return ans;
    }

    queue<BinaryTree<int> *> pendingNode;
    pendingNode.push(root);
    pendingNode.push(NULL);

    while(pendingNode.size()!=0)
    {
        BinaryTree<int> * front= pendingNode.front();
        pendingNode.pop();
        Node *head=NULL;
        Node *tail= NULL;

        if(front !=NULL)
        {
            Node *n= new Node(front->data);

            if(head==NULL)
            {
                head=n;
                tail=n;
                ans.push_back(head);
            }

            else
            {
                tail->next=n;
                tail= tail->next;
            }

            if(front->left !=NULL)
            {
                pendingNode.push(front->left);
            }

            if(front->right !=NULL)
            {
                pendingNode.push(front->right);
            }
        }

        else
        {
            tail->next=NULL;

            if(pendingNode.size()==0)
            {break;}
            pendingNode.push(NULL);
            head=NULL;
            tail=NULL;
        }

        return ans;
    }

    // void printLL(Node* head) 
    // {
	// Node<int> * temp = head;
	// while (temp != NULL) {
	// 	cout << temp->data << " ";
	// 	temp = temp->next;
	// }
	// cout << endl;
    // }

}



int main()
{
BinaryTree<int> * root = takeInputLevelWise();
	vector<Node * > ans = levelwiseLL(root);

	
}