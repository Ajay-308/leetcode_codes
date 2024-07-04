
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node * insertAtFirst(struct Node * head , int data){
    struct Node* ptr =(struct Node *) malloc (sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
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
    head=insertAtFirst(head,56);
    linkedlisttraversal(head);

    return 0;
}