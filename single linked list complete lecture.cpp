 #include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

// Insert at the beginning
void insert_at_start(node*& head, int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

// Insert at the end
void insert_at_end(node*& head, int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Insert at a specific position (1-based index)
void insert_at_position(node*& head, int pos, int value) {
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    node* newnode = new node;
    newnode->data = value;

    if (pos == 1) { // Insert at head
        newnode->next = head;
        head = newnode;
        return;
    }

    node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Positio n out of range!" << endl;
        delete newnode;
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete from start
void delete_from_start(node*& head) {
    if (head == NULL) {
        cout << "List empty!" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void delete_from_end(node*& head) {
    if (head == NULL) {
        cout << "List empty!" << endl;
        return;
    }
    if (head->next == NULL) { // Only one element
        delete head;
        head = NULL;
        return;
    }

    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

// Delete by value
void delete_by_value(node*& head, int value) {
    if (head == NULL) {
        cout << "List empty!" << endl;
        return;
    }

    if (head->data == value) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value not found!" << endl;
        return;
    }

    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Search an element
bool search(node* head, int key) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

// Count nodes
int count_nodes(node* head) {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Display the list
void display(node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Reverse the list
void reverse_list(node*& head) {
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Main function
int main() {
    node* head = NULL;

    insert_at_start(head, 10);
    insert_at_start(head, 20);
    insert_at_end(head, 30);
    insert_at_position(head, 2, 15);

    cout << "Initial List: ";
    display(head);

    delete_from_start(head);
    cout << "After deleting from start: ";
    display(head);

    delete_from_end(head);
    cout << "After deleting from end: ";
    display(head);

    insert_at_end(head, 40);
    insert_at_end(head, 50);
    cout << "After inserting 40 and 50 at end: ";
    display(head);

    delete_by_value(head, 15);
    cout << "After deleting value 15: ";
    display(head);

    cout << "Searching for 50: " << (search(head, 50) ? "Found" : "Not Found") << endl;
    cout << "Total nodes: " << count_nodes(head) << endl;

    reverse_list(head);
    cout << "After reversing: ";
    display(head);

    return 0;
}
