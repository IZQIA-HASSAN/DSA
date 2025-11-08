
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

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top element is: " << peek() << endl;

    pop();
    pop();