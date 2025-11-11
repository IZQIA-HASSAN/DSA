#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Traversal
void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;
}

// Insert at Head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert at Tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Insert After Key
void insertAfter(Node* head, int key, int val) {
    if (head == NULL) return;
//heap represenation or actual representation of pointers and other data member of the program
    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

// Delete Head
void deleteHead(Node*& head) {
    if (head == NULL) return;

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    last->next = head->next;
    head = head->next;
    delete temp;
}

// Delete by Value
void deleteByValue(Node*& head, int val) {
    if (head == NULL) return;

    if (head->data == val) {
        deleteHead(head);
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == val) {
            prev->next = curr->next;
            delete curr;
            return;
        }
    } while (curr != head);
}

int main() {
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);

    cout << "Initial List: ";
    printList(head);

    insertAtHead(head, 5);
    cout << "After Inserting 5 at Head: ";
    printList(head);

    insertAfter(head, 20, 25);
    cout << "After Inserting 25 after 20: ";
    printList(head);

    deleteHead(head);
    cout << "After Deleting Head: ";
    printList(head);

    deleteByValue(head, 25);
    cout << "After Deleting 25: ";
    printList(head);

    return 0;
}
