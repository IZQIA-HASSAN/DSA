#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Queue class using Linked List
class Queue {
private:
    Node* front;  // Points to front (head) node
    Node* rear;   // Points to last (tail) node

public:
    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Enqueue: Insert element at rear
    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (rear == NULL) {
            // Queue is empty
            front = rear = newNode;
            cout << val << " enqueued (first element)" << endl;
            return;
        }

        // Link new node at the end and update rear
        rear->next = newNode;
        rear = newNode;
        cout << val << " enqueued" << endl;
    }

    // Dequeue: Remove element from front
    void dequeue() {
        if (front == NULL) {
            cout << "Queue underflow! (Empty Queue)" << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued element: " << front->data << endl;
        front = front->next;

        // If front becomes NULL, also set rear to NULL
        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    // Peek: Show front element
    void peek() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    // Display all elements
    void display() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
        cout << "Queue destroyed and memory freed." << endl;
    }
};

// Main function
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.peek();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Extra dequeue to show underflow

    q.display();

    return 0;
}
