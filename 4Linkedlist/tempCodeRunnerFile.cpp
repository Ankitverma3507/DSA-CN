if(head==NULL){
//         return head;
//     }
//     if(pos==0){
//         Node *temp=head;
//         delete head;
//         temp=temp->next;
//         return temp;
//     }
//     Node *curr=head;
//     for(int i=0;i<pos;i++){
//         if(curr==NULL){
// 			return head;
//         }
//         curr=curr->next;
//     }
//     /*if(curr==NULL){
//         return head;
//     }*/
//     Node *prev=head;
//     for(int i=0;i<pos-1;i++){
//         if(prev==NULL){
//             return head;
//         }
//         prev=prev->next;
//     }
//     if(prev->next==NULL){
//         return head;
//     }
//      else if(curr->next==NULL){
//         delete curr;
//         prev->next=NULL;
//     }else{
//         Node *a=curr->next;
//         prev->next=a;
//         delete curr;
//     }
//     return head;