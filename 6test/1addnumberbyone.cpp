#include<iostream>
using namespace std;

 Node * reverse(Node * head)
    {
        Node *prev=NULL;
        Node *curr=head;
        Node*forward=NULL;
    
      while(curr!=NULL)
      {
        forward=curr->next;
        curr->next= prev;
        
        prev=curr;
        curr=forward;
      }
       return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head=reverse(head);
        Node *curr=head;
        
        while(curr!=NULL)
        {
            if(curr->next==NULL and curr->data==9)
            {
                curr->data=1;
                Node *temp= new Node (0);
                temp->next=head;
                head=temp;
                curr=curr->next;
            }
            
            else if(curr->data==9)
            {
                curr->data=0;
                curr=curr->next;
            }
            
            else
            {
                curr->data=curr->data+1;
                curr=curr->next;
                break;
            }
        }
        
        head=reverse(head);
        return head;
        
    }
int main()
{

return 0;
}