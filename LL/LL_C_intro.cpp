#include <iostream>

using namespace std;

struct  Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data,Node* next){
        this->data = data;
        this->next = NULL;
    }

};

int main(){
    Node* head = new Node(10,NULL);
    Node* second = new Node(20,NULL);
    Node* third = new Node(30,NULL);

    head-> next = second;
    second->next = third;

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    return 0;

}