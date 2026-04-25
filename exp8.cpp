#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// PUSH
void push(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    cout << x << " inserted into stack\n";
}

// POP
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    cout << top->data << " deleted from stack\n";
    top = top->next;
    delete temp;
}

// PEEK
void peek() {
    if (top == NULL)
        cout << "Stack is empty\n";
    else
        cout << "Top element is " << top->data << endl;
}

// DISPLAY
void display() {
    Node* temp = top;
    if (temp == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();
    peek();

    pop();
    display();

    return 0;
}
