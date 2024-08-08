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

// Add number to the end of the linked list
void add(Node*& head, int number) {
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Node* newNode = new Node(number);
    temp->next = newNode;
}

// Add two integers present in linked list
void twoAdd(Node*& head1, Node*& head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;

    while (temp1 != nullptr && temp2 != nullptr) {
        int sum = temp1->data + temp2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        temp1->data = sum;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != nullptr) {
        int sum = temp1->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        temp1->data = sum;
        temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
        int sum = temp2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        add(head1, sum);  // Adding remaining nodes from head2 to head1
        temp2 = temp2->next;
    }

    if (carry != 0) {
        add(head1, carry);
    }
}

// Function to print the linked list
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
    vector<int> v2 = {8, 4, 3};

    Node* head1 = new Node(v1[0]);
    Node* head2 = new Node(v2[0]);
    Node* temp1 = head1;
    Node* temp2 = head2;

    for (int i = 1; i < v1.size(); i++) {
        Node* newNode = new Node(v1[i]);
        temp1->next = newNode;
        temp1 = newNode;
    }

    for (int i = 1; i < v2.size(); i++) {
        Node* newNode = new Node(v2[i]);
        temp2->next = newNode;
        temp2 = newNode;
    }

    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);

    twoAdd(head1, head2);

    cout << "Result: ";
    printList(head1);

    return 0;
}
