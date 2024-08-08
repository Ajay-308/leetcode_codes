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

// Function to delete the head of the linked list
void deleteHead(Node*& head) {
    if (head == nullptr) return; // Check if the head is nullptr to avoid dereferencing nullptr

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete the tail of the linked list
void deleteTail(Node*& head) {
    if (head == nullptr) return; // Check if the head is nullptr
    if (head->next == nullptr) { // Check if there's only one element
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}


int main() {
    vector<int> v = {10, 20, 30,40,50,60,80};
    Node* head = new Node(v[0]);
    Node* temp = head;
    for (int i = 1; i < v.size(); ++i) {
        Node* newNode = new Node(v[i]);
        temp->next = newNode;
        temp = newNode;
    }

    // Uncomment this block to test deleteTail function
    // cout << "Deleting tail:" << endl;
    // while (temp != nullptr) {
    //     cout << temp->data << endl;
    //     temp = temp->next;
    //     deleteTail(temp);
    //     cout<<temp->data<<endl;
    // }

    cout << "Deleting head:" << endl;
    while (head != nullptr) {      
        deleteHead(head);
        cout << head->data << endl;

    }

    return 0;
}
