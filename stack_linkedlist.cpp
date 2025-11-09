#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Pointer to top of stack
Node* top = nullptr;

// Function to push an element onto the stack
void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed onto stack.\n";
}

// Function to pop an element from the stack
void pop() {
    if (top == nullptr) {
        cout << "Stack Underflow!\n";
        return;
    }
    Node* temp = top;
    cout << top->data << " popped from stack.\n";
    top = top->next;
    delete temp;
}

// Function to get the top element
int peek() {
    if (top == nullptr) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return top->data;
}

// Function to check if stack is empty
bool isEmpty() {
    return top == nullptr;
}

// Function to count number of elements
int count() {
    int cnt = 0;
    Node* temp = top;
    while (temp != nullptr) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top element is: " << peek() << endl;
    cout << "Number of elements: " << count() << endl;

    pop();
    pop();

    cout << "Number of elements: " << count() << endl;

    if (isEmpty()) {
        cout << "Stack is empty now.\n";
    } else {
        cout << "Stack is not empty.\n";
    }

    return 0;
}
