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


BinaryTree<int> *helper(int *in, int *po, int inS, int inE, int poS, int poE)
{
    if(inS > inE)
    {return NULL;}
    BinaryTree<int>*root= new BinaryTree<int>(po[poE]);
    
    
    int rootindex=-1;
    for(int i=inS; i<=inE; i++)
    {
        if(in[i]==po[poE])
        {
            rootindex=i;
        }
    }

    int LinS= inS;
    int LinE= rootindex-1;
    
    int LpoS= poS;
    int LpoE= LinE- LinS + LpoS;

//right
    int RinS= rootindex+1;
    int RinE= inE;
    int RpoS= LpoS +1;
    int RpoE = poE -1;

    root->left= helper(in, po, LinS, LinE, LpoS, LpoE );
    root->right= helper(in, po, RinS, RinE, RpoS, RpoE);


    return root;

}

//yuvraj
BinaryTree<int> * constructPostandIn(int * in, int * post, int inS, int inE, int postS, int postE) {
	if (inS > inE) {
		return NULL;
	}

	BinaryTree<int> *root = new BinaryTree<int> (post[postE]);

	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == post[postE]) {
			rootIndex = i;

		}
	}

	int LinS = inS;
	int LinE = rootIndex - 1;

	int LpostS = postS;
	int LpostE = LinE - LinS + LpostS;


	//for right
	int RinS = rootIndex + 1;
	int RinE = inE;

	int RpostS = LpostE + 1;
	int RpostE = postE - 1;


	root->left = constructPostandIn(in, post, LinS, LinE, LpostS, LpostE);
	root->right = constructPostandIn(in, post, RinS, RinE, RpostS, RpostE);

	return root;

}

BinaryTree<int> * constructTreeusingINandPo(int *in, int* po, int size)
{
    // return helper(in, po, 0, size-1, 0, size-1); 
    return constructPostandIn(in, po, 0, size-1, 0 , size-1);                                 
}
int main()
{
    int in[]= {4 ,2, 5, 1, 6, 3, 7};
    int po[]={4 ,5, 2, 6, 7, 3, 1 }; 
    int size=7;

BinaryTree<int> * root= constructTreeusingINandPo(in, po, size);
printTreeLevelWise(root);
cout<<endl;

return 0;
}


