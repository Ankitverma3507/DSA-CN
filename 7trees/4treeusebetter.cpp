#include<iostream>
#include<queue>
#include "2Treenode.h"
using namespace std;

TreeNode <int> *getTree()
{
    int rootData;
    cout<<"enter the root data"<<endl;
    cin>>rootData;

    TreeNode <int> *root= new TreeNode <int>(rootData);

    queue <TreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while (!pendingNode.empty())
    {
        TreeNode<int>* front= pendingNode.front();
        pendingNode.pop();
        cout<<"Enter the number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0; i<numChild; i++)
        {
            int childData;
            cout<<"Enter"<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            // TreeNode<int> child(childData);//we cant allocate it statically beacuse we want it to be survive after the loop also
            TreeNode<int>* child= new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}

void printTreelevelwise(TreeNode<int>*root)
{
    // TreeNode<int>*rootnode= new TreeNode<int>(root->data);
    queue<TreeNode<int>*> allnode;
    allnode.push(root);
    while (!allnode.empty())
    {
        TreeNode<int> *front= allnode.front();
        allnode.pop();
        cout<<front->data<<":";
        for(int i=0; i<front->children.size();i++)
        {
        cout<<front->children[i]->data<<",";
        allnode.push(front->children[i]);

        }
        cout<<endl;
    }
     

}

void Printtree(TreeNode<int>*root)
{
    if(root==NULL){return;}//this is  not the base case this is only the edge condition and here we dont need to give base condition explicitely to use Recursion
    cout<<root->data<<":";
    for(int i=0; i<root->children.size(); i++)  //This loop is added to add the more infromation into our output of the printree function
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++)
    {
        Printtree(root->children[i]); 
    }
}
int main()
{
TreeNode <int>*root= getTree();
printTreelevelwise(root);
return 0;
}