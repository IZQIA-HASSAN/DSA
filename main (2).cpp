#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    // Constructor to initialize front and rear
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Function to add a value to the queue
    void enqueue(int value) {
        // Check if queue is full
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is full\n";
            return;
        }

        // First element
        if (front == -1)
            front = 0;

        // Move rear to next position
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << value << " added to the circular queue\n";
    }

    // Function to remove a value from the queue
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << arr[front] << " removed from the circular queue\n";

        // Only one element in queue
        if (front == rear) {
            front = rear = -1;
        } else {
            // Move front to next position
            front = (front + 1) % SIZE;
        }
    }

    // Function to display queue elements
    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// Main function to test the queue
int main() {
    CircularQueue q;

    // Adding 5 elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);  // Should show full (as circular queue holds SIZE-1 elements)

    q.display();

    // Removing two elements
    q.dequeue();
    q.dequeue();

    // Adding more elements
    q.enqueue(6);
    q.enqueue(7);

    q.display();

    return 0;
}
