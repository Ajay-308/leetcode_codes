#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node *left,*right;
};

//creating node function

struct node *createNode(int data){
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

//preorder traversal
void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//postorder traversal
void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}

//inorder traversal

void inOrder(struct node* root){
    if(root !=NULL){
        inOrder(root->left);
        printf("%d\t",root->data);
        inOrder(root->right);
    }
}

int main(){
    struct node *p=createNode(2);
    struct node *p1=createNode(1);
    struct node *p2=createNode(4);
    struct node *p3=createNode(11);
    struct node *p4=createNode(12);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    preOrder(p);
    postOrder(p);
    inOrder(p);
    return 0;

}