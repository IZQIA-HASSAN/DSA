#include <iostream>
using namespace std;

#define MAX 100  // maximum size of stack

int stack[MAX];
int top = -1; // indicates empty stack
int count = 0;

// Function to push an element onto the stack
void push(int value) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow!\n";
        return;
    }
    top++;
    count++;
    stack[top] = value;
    cout << value << " pushed onto stack.\n";
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        cout << "Stack Underflow!\n";
        return;
    }
    cout << stack[top] << " popped from stack.\n";
    top--;
}

// Function to get the top element of the stack
int peek() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return stack[top];
}

// Function to check if stack is empty
bool isEmpty() {
    return top == -1;
}

void display(){
    cout<<"the total number of elements in the stack is = "<<count<<endl;
}
int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top element is: " << peek() << endl;

    pop();
    pop();

    if (isEmpty()) {
        cout << "Stack is empty now.\n";
    } else {
        cout << "Stack is not empty.\n";
    }

    display();
    return 0;
}
