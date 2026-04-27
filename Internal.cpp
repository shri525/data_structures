#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;
void insertRear(int val) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Overflow: Deque is full\n");
        return;
    }
    if (front == -1) { // Empty queue
        front = 0;
        rear = 0;
    } else if (rear == SIZE - 1) { // Wrap around
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = val;
    printf("Inserted %d at end\n", val);
}
void deleteFront() {
    if (front == -1) {
        printf("Underflow: Deque is empty\n");
        return;
    }
    printf("Deleted %d from beginning\n", deque[front]);
    if (front == rear) { // Only one element
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1) { // Wrap around
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    display();
    deleteFront();
    display();
    return 0;
}
