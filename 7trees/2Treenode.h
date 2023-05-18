#include <vector>
#include<iostream>
#include<queue>
using namespace std;
template <typename T>
class TreeNode
{
    public:
    T data;
    vector <TreeNode <T>*> children;//we can write <T> or not ,its optional because same data type will be alloted to the parent node which is given to the root node

    TreeNode(T data)
    {
        this->data=data;
    }

    ~TreeNode()
    {
        for(int i=0; i<children.size();i++)
        {
            delete children[i];
        }
    }
    
};


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