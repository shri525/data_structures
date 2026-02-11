#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;
void push() {
    int value;
    if (top == MAX - 1) {
        cout << "Stack Overflow" << endl;
    } else {
        cout << "Enter value: ";
        cin >> value;
        stack[++top] = value;
        cout << "Value pushed" << endl;
    }
}
void pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
    } else {
        cout << "Popped value: " << stack[top--] << endl;
    }
}
void peek() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element: " << stack[top] << endl;
    }
}
void display() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements are:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}
void status() {
    if (top == -1)
        cout << "Stack is Empty" << endl;
    else if (top == MAX - 1)
        cout << "Stack is Full" << endl;
    else
        cout << "Stack is not Full or Empty" << endl;
}

int main() {
    int choice;
    do {
        cout << "\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Status\n6.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: status(); break;
            case 6: cout << "Exit" << endl; break;
            default: cout << "Invalid choice" << endl;
        }
    } while (choice != 6);

    return 0;
}
