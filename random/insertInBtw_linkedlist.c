
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node * insertAtBtw(struct Node * head , int data,int index){
    struct Node* ptr =(struct Node *) malloc (sizeof(struct Node));
    struct Node* p=head;

    int i=0;

    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

void linkedlisttraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("elemenet: %d\n",ptr->data);
        ptr=ptr->next;
    }
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

    head=insertAtBtw(head,56,2);
    linkedlisttraversal(head);

    return 0;
}