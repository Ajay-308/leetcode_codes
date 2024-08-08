#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* insert_last(Node* head ,int val){
    Node* temp = head;
    while(temp->next!=nullptr){
        temp =  temp->next;
    }
    temp->next = new Node(val);
    return head;
}

Node* insert_At_any(Node* head,int val,int pos){
    Node*temp = head;
    Node* new_node = new Node(val);
    if(pos==1){
        new_node->next = head;
        head = new_node;
        return head;
    }
    for(int i=1;i<pos-1;i++){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}
int main() {
    vector<int> v1 = {7, 5, 9, 4, 6};
    Node* head = new Node(v1[0]);
    Node* current = head;
    for (size_t i = 1; i < v1.size(); i++) {
        current->next = new Node(v1[i]);
        current = current->next;
    }

    cout<<"original"<<endl;
    printList(head);
    cout<<"insert"<<endl;
    // head = insert_last(head,10);
    head = insert_At_any(head,10,3);
    printList(head);


    return 0;
}
