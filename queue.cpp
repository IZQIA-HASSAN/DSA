#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Global pointers for front and rear
Node* front = nullptr;
Node* rear = nullptr;

// Function to check if queue is empty
bool isEmpty() {
    return (front == nullptr);
}

// Function to add element at the end (Enqueue)
void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " enqueued to the queue.\n";
}

// Function to remove element from front (Dequeue)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    cout << temp->data << " dequeued from the queue.\n";
    delete temp;

    if (front == nullptr) // If queue becomes empty
        rear = nullptr;
}

// Function to display all queue elements
void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "Queue elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to view the front element
int peek() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return -1;
    }
    return front->data;
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    cout << "Front element is: " << peek() << endl;

    dequeue();
    display();

    dequeue();
    dequeue();
    dequeue(); // extra dequeue to show error handling

    return 0;
}