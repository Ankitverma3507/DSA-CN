#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;

    node(int data)
    {
        this ->data= data;
        next=NULL;
    }
};
void print(node *head)
{
    node *temp=head;
    while(head!=NULL)//change herer head into temp;
    {
        cout<<head->data<<endl;
        head=head->next;
    }
    //we have to make sure that the address of our head cant be lost so we should make one temporary pointer which stores the value of address of head
}

node *takeinput()
{
    int data;
    int total=0;
    cin>>data;
    node *head= NULL;
    node *tale= NULL;
    while(data != -1)
    {
        node *newnode= new node(data);//here constructor called88
        if(head == NULL)
        {
            head=newnode;
            tale= newnode;
        }
        else
        {   //this code has o(n)                                     //this code has 0(n^2)
        tale->next=newnode;                                         // node *temp=head;
        tale= tale->next;                                           // while(temp->next!=NULL)
                                                                    // {
                                                                        // temp= temp->next;
                                                                    // }
                                                                    // temp->next=newnode;
        }
        cin>>data;
        total++;
    }
    // cout<<"total no of node is"<<total<<endl;
    return head;
}

int main()
{
    node*head= takeinput();
    print(head);

return 0;
}