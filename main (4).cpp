#include <iostream>
using namespace std;

#define Size 3

class Queue {
private:
    int head, tail;
    int Q[Size];

public:
    Queue() {
        head = -1;
        tail = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (head == 0 && tail == Size - 1) || (tail + 1 == head);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (head == -1);
    }

    // Enqueue operation
    void enq(int element) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot insert " << element << endl;
            return;
        }

        // If queue is empty, initialize head
        if (head == -1)
            head = 0;

        // Move tail in circular manner
        tail = (tail + 1) % Size;
        Q[tail] = element;
        cout << element << " added to the queue." << endl;
    }

    // Dequeue operation
    void deq() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot delete." << endl;
            return;
        }

        cout << Q[head] << " deleted from the queue." << endl;

        // If this was the last element
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % Size;
        }
    }

    // Display function
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << "Queue elements are: ";
        int i = head;
        while (true) {
            cout << Q[i] << " ";
            if (i == tail)
                break;
            i = (i + 1) % Size;
        }
        cout << endl;

        cout << "Head is at index " << head << ", Tail is at index " << tail << endl;
    }
};

// Main function
int main() {
    Queue q;

    q.enq(10);
    q.enq(20);
    q.enq(30);
    q.display();

    q.deq();
    q.display();

    q.enq(40); // utilizes free space
    q.display();

    q.deq();
    q.deq();
    q.deq();
    q.display();

    return 0;
}
