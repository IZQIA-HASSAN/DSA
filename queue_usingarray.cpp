#include <iostream>
using namespace std;

// Define maximum size of queue
#define SIZE 5

// Global variables
int queue[SIZE];
int front = -1;
int rear = -1;

// Function to check if queue is full
bool isFull() {
    return rear == SIZE - 1;
}

// Function to check if queue is empty
bool isEmpty() {
    return front == -1 || front > rear;
}

// Enqueue (Insert element in queue)
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue " << value << endl;
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
    cout << value << " inserted into queue." << endl;
}
void enqueue(int value){
    if(isFull()){
        cout<<"queue is full"<<endl;
        return ;
    }
    if(front == -1){
        front = 0;
        
    
    }
    rear++;
    queue[rear] = value;

}

// Dequeue (Remove element from queue)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    cout << queue[front] << " removed from queue." << endl;
    front++;

    // Reset front and rear if queue becomes empty
    if (front > rear) {
        front = rear = -1;
    }
}

// Peek (View front element)
void peek() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Front element is: " << queue[front] << endl;
}

// Display all elements in queue
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue(); // trying to dequeue empty queue
    return 0;
}
