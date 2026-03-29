#include <stdio.h>
#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int val) {
    queue[++rear] = val;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Push to stack
void push(int val) {
    stack[++top] = val;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// ---------------- MAIN ----------------

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    for (int i = 0; i < n; i++) {
        push(dequeue());
    }

    // Step 2: Stack → Queue
    for (int i = 0; i < n; i++) {
        enqueue(pop());
    }

    // Print reversed queue
    printf("Reversed queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}