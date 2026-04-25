#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *front = NULL, *rear = NULL;

// ENQUEUE
void enqueue(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << x << " inserted into queue\n";
}

// DEQUEUE
void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;
    cout << front->data << " deleted from queue\n";
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

// PEEK
void peek() {
    if (front == NULL)
        cout << "Queue is empty\n";
    else
        cout << "Front element is " << front->data << endl;
}

// DISPLAY
void display() {
    Node* temp = front;
    if (temp == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    peek();

    dequeue();
    display();

    return 0;
}
