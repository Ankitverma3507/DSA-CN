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

//function to print linked list members statically
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
//function to print linked list members dynamically
void printd(node *head)
{
    while (head!=NULL)
    {
        
    }
    
}

int main()
{
    //first node is called head node and last one is called tale node of linked list. we have to store the address of first node
//statically allocation
node n1(1);
node *head=&n1; 

node n2(2);
node n3(5);
node n4(4);
node n5(6);

n1.next=&n2;
n2.next=&n3;
n3.next=&n4;
n4.next=&n5;

// n1.next=&n2;

// cout<<n1.data<<" "<<n2.data<<endl;
// cout<<head->data<<endl;// we can print our data of any node by the help of head 

//dynamic allocation
// node *n3= new node(3);
// node *head=n3;
// node *n4= new node(34);

// //now we want to connect to node which are dynamicaaly alloted
// n3->next=n4;
print(head);

return 0;
}