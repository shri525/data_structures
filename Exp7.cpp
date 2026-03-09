#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Display list
void display(Node* head) {
    if (!head) { cout << "List is empty\n"; return; }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Insert at beginning
void insertBegin(Node*& head, int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
    cout << "List after insertion at beginning: ";
    display(head);
}

// Insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    cout << "List after insertion at end: ";
    display(head);
}

// Delete by value
void deleteNode(Node*& head, int val) {
    if (!head) { cout << "List is empty!\n"; return; }
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "List after deletion: ";
        display(head);
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val) temp = temp->next;
    if (!temp->next) cout << "Value not found!\n";
    else {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "List after deletion: ";
        display(head);
    }
}

int main() {
    Node* head = nullptr;
    int choice, val;

    while (true) {
        cout << "\n--- Linked List Operations ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Delete by value\n4. Display list\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                insertBegin(head, val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                insertEnd(head, val);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteNode(head, val);
                break;
            case 4:
                cout << "Current List: ";
                display(head);
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
