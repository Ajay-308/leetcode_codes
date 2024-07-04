
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedlisttraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("elemenet: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
// case 1 delete at beg
// struct Node * deleteAtBeg(struct Node * head){
//     struct Node* ptr =head;

//     head=head->next;
//     free(ptr);
   
//     return head;
// };

//delete in between


// struct Node* deleteInBtw(struct Node* head , int index){
//     struct Node * p=head;
//     struct Node* q= head->next;

//     for(int i=0;i<index-1;i++){
//         p=p->next;
//         q=q->next;
//     }
//     p->next=q->next;
//     free(q);
//     return head;
// }


// delete at the end;

struct Node* deleteInBtw(struct Node* head){
    

}

int main(){
    struct Node * head;
    struct Node * first;
    struct Node * sec;
    
    head=(struct Node*) malloc(sizeof(struct Node));
    first=(struct Node*) malloc(sizeof(struct Node));
    head=(struct Node*) malloc(sizeof(struct Node));

    head->data=7;
    head->next=first;

    first->data=11;
    first->next=sec;

    sec->data=66;
    sec->next=NULL;

    head=deleteInBtw(head,1);
    linkedlisttraversal(head);

    return 0;
}