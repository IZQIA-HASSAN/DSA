// circular doubly linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;  // Global head pointer

// Create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at end
void insertEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

// Insert at beginning
void insertBegin(int data) {
    insertEnd(data);
    head = head->prev;  // Move head to new node
}

// Delete a node by value
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* curr = head;
    while (true) {
        if (curr->data == key) {
            if (curr->next == curr) { // Only one node
                delete curr;
                head = NULL;
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                if (curr == head)  // Deleting head
                    head = curr->next;
                delete curr;
            }
            return;
        }
        curr = curr->next;
        if (curr == head) {
            cout << "Value not found.\n";
            break;
        }
    }
}

// Display forward
void displayForward() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* curr = head;
    while (true) {
        cout << curr->data << " ";
        curr = curr->next;
        if (curr == head) break;
    }
    cout << endl;
}

// Display backward
void displayBackward() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* curr = head->prev;
    while (true) {
        cout << curr->data << " ";
        curr = curr->prev;
        if (curr->next == head) break;
    }
    cout << endl;
}

// 🔹 Example usage
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertBegin(5);

    cout << "Forward Traversal: ";
    displayForward();   // 5 10 20 30

    cout << "Backward Traversal: ";
    displayBackward();  // 30 20 10 5

    deleteNode(20);
    cout << "After deleting 20: ";
    displayForward();   // 5 10 30

    return 0;
}