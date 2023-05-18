/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

void swapadjacent(Node*head){
    if (head==NULL)
    {
        return;
    }
    int temp=head->data;
    head->data=head->next->data;
    head->next->data=temp;    
}
int lengthLL(Node*head){
    if (head==NULL)
    {
        return 0;
    }
    int len=lengthLL(head->next);
    return len+1;
}
Node *bubbleSort(Node *head)
{
if (head==NULL ||head->next==NULL)
{
    return head;
}
Node*newhead=NULL;
int len=lengthLL(head);
for (int i = 1; i < len; i++)
{
    Node*curr=head;
    for (int a = 1; a <= len-i;curr=curr->next, a++)
    {
        if (curr->data > curr->next->data)
        {
            swapadjacent(curr);
        }
        if (newhead==NULL)
        {
            newhead=curr;
        }
        
        }
    }
    return newhead;
}
