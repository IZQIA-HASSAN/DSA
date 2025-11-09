#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert at head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        newNode->next = newNode; // first node points to itself
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head) { // find last node
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert at tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
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

// Insert at position (1-based index)
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

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at position
void deleteAtPosition(Node*& head, int pos) {
    if (head == nullptr || pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* temp = head;

    if (pos == 1) { // delete head
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        if (head == head->next) { // only one node
            delete head;
            head = nullptr;
            return;
        }

        last->next = head->next;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Display list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    cout << "List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int count_nodes(Node*& head ){
    int count = 0;
    if(head == nullptr){
        cout<<"list is empty"<<endl;
        return 0;
    }
    else{
        Node*temp = head;
        do{
            count++;
            temp = temp->next;
            
        }while(temp !=head);
        
        cout<<"no of nodes are "<<count<<endl;
    }


}
// Main function
int main() {
    Node* head = nullptr;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    display(head); // List: 10 20 30 40

    insertAtHead(head, 5);
    display(head); // List: 5 10 20 30 40

    insertAtPosition(head, 3, 15);
    display(head); // List: 5 10 15 20 30 40

    deleteAtPosition(head, 1);
    display(head); // List: 10 15 20 30 40

    deleteAtPosition(head, 4);
    display(head); // List: 10 15 20 40

    return 0;
}