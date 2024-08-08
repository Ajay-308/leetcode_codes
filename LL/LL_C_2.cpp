#include <iostream>
#include <vector>

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
    vector<int> v = {10,20,30};
    Node head = Node(v[0] , NULL);
    Node* temp  = &head;
    for(int i=1;i<v.size();i++){
        Node* newNode = new Node(v[i],NULL);
        temp->next = newNode;
        temp = newNode;
    }
    
    cout<<head.data<<endl;
    return 0;
}
