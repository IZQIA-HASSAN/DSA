#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Insert at the head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

// Insert at the tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at a specific position (1-based index)
void insertAtPosition(Node*& head, int pos, int val) {
    if (pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Delete at a specific position
void deleteAtPosition(Node*& head, int pos) {
    if (head == nullptr || pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* temp = head;
    int count = 1;

    if (pos == 1) { // delete head
        head = temp->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
        return;
    }

    while (temp != nullptr && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    if (temp->prev != nullptr) temp->prev->next = temp->next;
    if (temp->next != nullptr) temp->next->prev = temp->prev;

    delete temp;
}

// Display forward
void displayForward(Node* head) {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display backward
void displayBackward(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    cout << "Backward: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = nullptr;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    displayForward(head);   // Forward: 10 20 30 40
    displayBackward(head);  // Backward: 40 30 20 10

    insertAtPosition(head, 2, 15); // Insert 15 at position 2
    displayForward(head);          // Forward: 10 15 20 30 40

    deleteAtPosition(head, 3);     // Delete element at position 3 (20)
    displayForward(head);          // Forward: 10 15 30 40

    deleteAtPosition(head, 1);     // Delete head (10)
    displayForward(head);          // Forward: 15 30 40

    return 0;
}