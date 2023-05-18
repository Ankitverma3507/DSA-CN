#include <iostream>
#include "2Treenode.h"
using namespace std;
// to get the tree we will made function which will return us the address of rootnode

// TreeNode<int> *getTree()
// {
//     int rootData;
//     cout<<"enter the root data"<<endl;
//     cin>>rootData;
//     TreeNode<int> *root= new TreeNode<int>(rootData);

//     int n;
//     cout<<"enter the no. of children"<<endl;
//     cin>>n;
//     for(int i=0; i<n; i++)
//     {
//         TreeNode<int> *child= getTree();
//         root->children.push_back(child);
//     }
//     return root;

// }

TreeNode<int> *getTreelevelwise()
{
    int rootData;
    cout << "enter the root data" << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (!pendingNode.empty())
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << "Enter the number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter" << i << "th child of " << front->data << endl;
            cin >> childData;
            // TreeNode<int> child(childData);//we cant allocate it statically beacuse we want it to be survive after the loop also
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}

// to print the data of all the root and children node
void Printtree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    } // this is  not the base case this is only the edge condition and here we dont need to give base condition explicitely to use Recursion
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++) // This loop is added to add the more infromation into our output of the printree function
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        Printtree(root->children[i]);
    }
}



void preorderTraversal(TreeNode<int> *root)
{
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorderTraversal(root->children[i]);
    }
}

int countNodesGreaterThanX(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    if (root->data > x)
    {
        count++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodesGreaterThanX(root->children[i], x);
    }
    return count;
}

pair<TreeNode<int> *, int> NodeWithMaxSum(TreeNode<int> *root)
{
    pair<TreeNode<int> *, int> ans;
    ans.first = root;
    ans.second = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        ans.second += root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int> *, int> subans = NodeWithMaxSum(root->children[i]);
        if (subans.second > ans.second)
        {
            ans = subans;
        }
    }
    return ans;
}

bool identical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1->data != root2->data)
    {
        return false;
    }
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++)
    {
        bool smallAns = identical(root1->children[i], root2->children[i]);
        if (!smallAns)
        {
            return false;
        }
    }

    return true;
}

int NextLargest(TreeNode<int> *root, int n)
{
    int ans;
    if (root->data > n)
    {
        ans = root->data;
    }
    else
    {
        ans = 0;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        int temp = NextLargest(root->children[i], n);

        if (ans == 0)
        {
            ans = temp;
        }

        else
        {
            if (ans < temp)
            {
                return ans;
            }

            else
            {
                ans = temp;
            }
        }
    }

    if (ans < n)
    {
        return -1;
    }
    return ans;
}

pair<int, int> secondLargestNode(TreeNode<int> *root)
{
    pair<int, int> ans(root->data, -1);
    //(max,secondmax)

    for (int i = 0; i < root->children.size(); i++)
    {

        pair<int, int> smallans = secondLargestNode(root->children[i]);

        if (smallans.first > ans.first)
        {
            int x= ans.first;
            if(x<smallans.second){ans.second=smallans.second;}
            else{ans.second = ans.first;}
            ans.first = smallans.first;
        }
        else
        {
            if (smallans.first > ans.second)
            {
                ans.second = smallans.first;
            }
        }
    }

    return ans;
}

void replaceWtihnode(TreeNode<int>*root, int k)
{
    
    root->data=k;

    for(int i=0; i<root->children.size(); i++)
    {
        replaceWtihnode(root->children[i], k+1);
        
    }

    return;
}
int main()
{
    // now we will made simple three node of tree
    //  TreeNode <int>* root= new TreeNode <int>(1);
    //  TreeNode <int>* node1= new TreeNode <int>(2);
    //  TreeNode <int>* node2= new TreeNode <int>(3);

    // //uptil now we only make three nodes but we did not connect them acc. to tree DS so we will do this now
    // root->children.push_back(node1);
    // root->children.push_back(node2);//now we connected them also
    TreeNode<int> *root = getTreelevelwise();
    // TreeNode <int>*root2= getTreelevelwise();
    // int x;
    // cout << "enter x" << endl;
    // cin >> x;
    // cout<< countNodesGreaterThanX(root,x)<<endl;

    // cout<<"ans is "<<NodeWithMaxSum(root).first;
    // cout << (NodeWithMaxSum(root).first)->data << " " << NodeWithMaxSum(root).second << endl;
    // cout<<identical(root1, root2);

    // cout << secondLargestNode(root).second;

    replaceWtihnode(root,0);
    printTreelevelwise(root);


    return 0;
}