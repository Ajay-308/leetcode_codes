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

// Delete the k-th node
Node* remove_k(Node* head, int k) {
    if (head == nullptr) return head;
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 1;

    while (temp != nullptr && cnt < k) {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    if (temp != nullptr) {
        prev->next = temp->next;
        delete temp;
    }

    return head;
}
// Delete the k-th node
Node* remove_val(Node* head, int val) {
    if (head == nullptr) return head;
    if (head->data==val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if(temp->data==val){
            prev->next = prev->next->next;
            delete temp;
            break;

        }
        prev = temp;
        temp = temp->next;
    }


    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> v1 = {7, 5, 9, 4, 6};
    Node* head = new Node(v1[0]);
    Node* current = head;
    for (size_t i = 1; i < v1.size(); i++) {
        current->next = new Node(v1[i]);
        current = current->next;
    }

    cout << "Original list: ";
    printList(head);

    head = remove_val(head, 6);

    cout << "after removing element:- ";
    printList(head);

    return 0;
}
