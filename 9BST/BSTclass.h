#include <iostream>
#include "1BinaryTree.h"
#include <queue>
using namespace std;

class BST
{
    BinaryTree<int> *root;

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

private:
    bool hasData(int data, BinaryTree<int> *root)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->data == data)
        {
            return true;
        }

        else if (data < root->data)
        {
            return hasData(data, root->left);
        }
        else
            return hasData(data, root->right);
    }

    BinaryTree<int> *insert(BinaryTree<int> *root, int data)
    {
        if (root == NULL)
        {
            BinaryTree<int> *temp = new BinaryTree<int>(data);
            return temp;
        }

        if (data > root->data)
        {
            root->right = insert(root->right, data);
        }

        else
        {
            root->left = insert(root->left, data);
        }

        return root;
    }

    BinaryTree<int> *deletedata(BinaryTree<int> *root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (data > root->data)
        {
            root->right = deletedata(root->right, data);
            return root;
        }

        if (data < root->data)
        {
            root->left = deletedata(root->left, data);
            return root;
        }

        if (data == root->data)
        {
            if (root->left == NULL and root->right == NULL)
            {
                delete root;
                return NULL;
            }

            else if (root->left == NULL)
            {
                BinaryTree<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }

            else if (root->right == NULL)
            {
                BinaryTree<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }

            else
            {
                BinaryTree<int> *minNode = root->right;
                while (root->left != NULL)
                {
                    minNode = minNode->left;
                }

                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = deletedata(root->right, rightMin);
                return root;
            }
        }
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

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }

    void insert(int data)
    {
        this->root = insert(this->root, data);
        return;
    }

    void deletedata(int data)
    {
        this->root = deletedata(this->root, data);
    }

    void printTree()
    {
        return printTreeLevelWise(root);
    }

    
};