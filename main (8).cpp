#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insertions
void insertAtHead(Node*& head, int val);
void insertAtTail(Node*& head, int val);
void insertAtPosition(Node*& head, int val, int pos);

// Deletions
void deleteAtHead(Node*& head);
void deleteAtTail(Node*& head);
void deleteAtPosition(Node*& head, int pos);

// Traversals
void printListForward(Node* head);
void printListBackward(Node* head);

int main() {
    Node* head = NULL;

    // Insert at head
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);

    cout << "Forward: ";
    printListForward(head);   // 30 <-> 20 <-> 10 <-> NULL

    cout << "Backward: ";
    printListBackward(head);  // 10 <-> 20 <-> 30 <-> NULL

    // Insert at tail
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    cout << "After tail insertions (Forward): ";
    printListForward(head);   // 30 <-> 20 <-> 10 <-> 40 <-> 50 <-> NULL

    // Insert at position
    insertAtPosition(head, 25, 3);

    cout << "After inserting 25 at pos 3 (Forward): ";
    printListForward(head);   // 30 <-> 20 <-> 25 <-> 10 <-> 40 <-> 50 <-> NULL

    // Deletions
    deleteAtHead(head);
    cout << "After deleting head (Forward): ";
    printListForward(head);

    deleteAtTail(head);
    cout << "After deleting tail (Forward): ";
    printListForward(head);

    deleteAtPosition(head, 2);
    cout << "After deleting node at pos 2 (Forward): ";
    printListForward(head);

    return 0;
}

// ---------------- Definitions ----------------

void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node*& head, int val, int pos) {
    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {//not clear
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteAtHead(Node*& head) {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}

void deleteAtTail(Node*& head) {
    if (head == NULL) return;   // Empty list case

    // Case: Only one node
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    // Case: More than one node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;  // Disconnect last node
    delete temp;              // Free memory
}
\\today limit close lecture here


void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL) return;

    Node* temp = head;

    if (pos == 1) {
        deleteAtHead(head);
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void printListForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printListBackward(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}
