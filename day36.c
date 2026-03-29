#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Check full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Check empty
int isEmpty() {
    return (front == -1);
}

// Enqueue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if (isEmpty()) return;

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

// Driver
int main() {
    int n, m, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Enter number of dequeues: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    printf("Queue after operations: ");
    display();

    return 0;
}