#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void print(node *head)
{
    node *temp = head;
    while (head != NULL) // change herer head into temp;
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    // we have to make sure that the address of our head cant be lost so we should make one temporary pointer which stores the value of address of head
}

node *ithnode(node *head, int i, int data)
{
    node *newnode = new node(data);
    int count = 0;

    node *temp = head;
    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL)
    {
        node *a = temp->next;
        temp->next = newnode;
        newnode->next = a;
    }
    return head;
}

node *takeinput()
{
    int data;
    int total = 0;
    cin >> data;
    node *head = NULL;
    node *tale = NULL;
    while (data != -1)
    {
        node *newnode = new node(data); // here constructor called88
        if (head == NULL)
        {
            head = newnode;
            tale = newnode;
        }
        else
        { // this code has o(n)
            tale->next = newnode;
            tale = tale->next;
        }
        cin >> data;
        total++;
    }

    return head;
}
int main()
{
    node *head = takeinput();
    print(head);

    int i, data;
    cin >> i >> data;
    head = ithnode(head, i, data);
    print(head);

    return 0;
}
//reverse a linked list 
//when we want to print more than two return statement of a function then we use class in which we can use class to return more than two ouptputs like 
//in below written code we have to use while loop to traverse across the liked list given by the recursion so it become O(nsqr)so to make it O(n) we start to note the tale also which means our recursion function will give you head and tale of the reversed linked list
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head==NULL){return NULL;}
    if(head->next==NULL){return head;}
    Node *smallHead=reverseLinkedListRec(head->next);
    Node *temp=smallHead;
    while(temp->next!=NULL){temp=temp->next;}
    temp->next=head;
    head->next=NULL;
    return smallHead;
        
}

//we will do like 
class pair
{
    public:
    Node *tale;
    Node *head;
};
rest code will be similar
pair reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head==NULL|| head->next==NULL)
    {
        pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    pair smallHead=reverseLinkedListRec(head->next);
    smallHead.tail->next=head;
    head->next=NULL;
    
    pair ans;
    ans.head=smallHead.head;
    ans.tail=head;
    return ans;
        
}


we can also use different approach . as we want to find the tail so we can say that the tail is our head ka next of the initial given linked list








Node *skipMdeleteN(Node *head, int m, int n)
{
    if(m == 0){
        return NULL;
    }
    if(n == 0){
        return head;
    }
    Node*head1=head;
	while(head != NULL && head -> next != NULL){
        int i = 0;
        while(i < (m - 1) && head != NULL){
            head = head -> next;
            i++;
        }
    	Node *temp = head;
    	int j = 0;
    	while(j <= n && head != NULL){
        	head = head -> next;
            j++;
    	}
        temp -> next = head;
    }
    return head1;
}


Node* swapNodes(Node *head,int i,int j) {
    Node *temp = head, *prev = NULL; 
    Node *node1 = NULL, *node2 = NULL, *node1_prev = NULL, *node2_prev = NULL;
    int pos = 0;
    
    // if i and j are equal
    if(i == j) return head; //No changes
    
    while(temp != NULL) {
        if(pos == i) {
            node1_prev = prev; 
            node1 = temp;
        }
        else if(pos == j) {
            node2_prev = prev; node2 = temp;
        }
        prev = temp;
        temp = temp -> next; pos++; 
    }
    if(node1_prev != NULL) {
        node1_prev -> next = node2;
    }
    else { 
        head = node2;
    }
    if(node2_prev != NULL) { 
        node2_prev -> next = node1; 
    }
    else {
        head = node1;
    }
    Node *temp1 = node2 -> next;
    node2 -> next = node1 -> next; 
    node1 -> next = temp1;
    return head;
}


Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(head==NULL||k==0||k==1){return head;}
    Node *temp=head;
    Node *temp2=head;
    while(temp!=NULL){
        int arr[k];
        for(int i=0;i<k;i++){
            arr[i] = -99;
            if(temp!=NULL){
            arr[i]=temp->data;
            temp=temp->next;
            }
        }
        //int j=1;
        for(int i=0;i<k && temp2!=NULL;i++){
            if(arr[k-i-1]==-99){continue;}
            temp2->data=arr[k-i-1];
            temp2=temp2->next;
        }
    }
    return head;
}
