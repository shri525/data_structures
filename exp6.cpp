#include <iostream>
using namespace std;

int main() {
    int queue[5];
    int front = -1, rear = -1;
    int choice, value;

    while (true) {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:   
            if (rear == 4) {
                cout << "Queue Overflow!\n";
            }
            else {
                cout << "Enter value: ";
                cin >> value;

                if (front == -1)
                    front = 0;

                rear++;
                queue[rear] = value;
                cout << value << " inserted.\n";
            }
            break;

        case 2:   
            if (front == -1 || front > rear) {
                cout << "Queue Underflow!\n";
            }
            else {
                cout << queue[front] << " deleted.\n";
                front++;

                if (front > rear)
                    front = rear = -1;
            }
            break;

        case 3:   
            if (front == -1) {
                cout << "Queue is Empty.\n";
            }
            else {
                cout << "Queue Elements: ";
                for (int i = front; i <= rear; i++) {
                    cout << queue[i] << " ";
                }
                cout << endl;
            }
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }
    }
}
