 #include <iostream>
using namespace std;

// ------------------------------------
// Node structure
// ------------------------------------
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// ------------------------------------
// Insert at HEAD
// ------------------------------------
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) { // Empty list
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* last = head->prev; // Last node

    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;

    head = newNode; // New node becomes head
}

// ------------------------------------
// Insert at TAIL (end of list)
// ------------------------------------
void insertAtTail(Node*& head, int val) {
    if (head == NULL) { // If empty, just call insertAtHead
        insertAtHead(head, val);
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;

    Node* last = head->prev; // Find last node

    // Insert newNode between last and head
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

// ------------------------------------
// Insert at a specific POSITION (1-based index)
// ------------------------------------
void insertAtPosition(Node*& head, int val, int pos) {
    // Case 1: If inserting at head OR list is empty
    if (pos <= 1 || head == NULL) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse until position OR just before head again
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // Case 2: If reached tail, insert at end
    if (temp->next == head) {
        insertAtTail(head, val);
        return;
    }

    // Case 3: Insert in between
    Node* newNode = new Node();
    newNode->data = val;

    newNode->next = temp->next;     // link new node forward
    newNode->prev = temp;           // link back to temp
    temp->next->prev = newNode;     // link next node back to new node
    temp->next = newNode;           // link temp forward to new node
}

// ------------------------------------
// Delete HEAD node
// ------------------------------------
void deleteHead(Node*& head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == head) { // Only one node
        delete head;
        head = NULL;
        return;
    }

    /*Node* last = head->prev;chat gpt recomendation
    Node* newHead = head->next;

    last->next = newHead;
    newHead->prev = last;

    delete head;
    head = newHead;*/
    Node* last=head->prev;
    Node* temp=head;
    last->next=head->next;
    head=head->next;
    head->prev=last;
    delete temp;

}

// ------------------------------------
// Delete TAIL node
// ------------------------------------
void deleteTail(Node*& head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == head) { // Only one node
        delete head;
        head = NULL;
        return;
    }

    Node* last = head->prev;
    Node* secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    delete last;
}

// ------------------------------------
// Delete a node by VALUE
// ------------------------------------
void deleteByValue(Node*& head, int val) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    do {
        if (temp->data == val) {
            // Case 1: Only one node
            if (temp == head && temp->next == head) {
                delete temp;
                head = NULL;
                return;
            }

            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            if (temp == head) { // If deleting head
                head = nextNode;
            }

            delete temp;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value " << val << " not found!" << endl;
}

// ------------------------------------
// Print list FORWARD
// ------------------------------------
void printForward(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;
}

// ------------------------------------
// Print list BACKWARD
// ------------------------------------
void printBackward(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* last = head->prev;
    Node* temp = last;
    do {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    } while (temp != last);
    cout << "HEAD" << endl;
}

// ------------------------------------
// MAIN function (demo)
// ------------------------------------
int main() {
    Node* head = NULL;

    // Insert at head
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);

    cout << "After inserting at head: ";
    printForward(head);

    // Insert at tail
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    cout << "After inserting at tail: ";
    printForward(head);

    // Insert at position
    insertAtPosition(head, 25, 3);
    cout << "After inserting 25 at position 3: ";
    printForward(head);

    // Delete head
    deleteHead(head);
    cout << "After deleting head: ";
    printForward(head);

    // Delete tail
    deleteTail(head);
    cout << "After deleting tail: ";
    printForward(head);

    // Delete by value
    deleteByValue(head, 25);
    cout << "After deleting value 25: ";
    printForward(head);

    cout << "Final List (Backward Traversal): ";
    printBackward(head);

    return 0;
}
