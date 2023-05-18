#include<iostream>
using namespace std;
void deleteAlternateNodes(Node *head) {
    //Write your code here
     if(head==NULL){return ;}
     Node *forward=head->next;
    if(forward==NULL){return ;}
    
    head->next=forward->next;
//     delete (Node);
        deleteAlternateNodes(head->next);
        
  
}
int main()
{

return 0;
}