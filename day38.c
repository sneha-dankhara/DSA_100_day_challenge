#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void push_front(int val) {
    if (front == 0) {
        printf("Overflow at front!\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            front--;
        }
        deque[front] = val;
    }
}

void push_back(int val) {
    if (rear == MAX - 1) {
        printf("Overflow at rear!\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        deque[rear] = val;
    }
}

void pop_front() {
    if (front == -1) {
        printf("Deque is empty!\n");
    } else {
        printf("Removed from front: %d\n", deque[front]);
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void pop_back() {
    if (rear == -1) {
        printf("Deque is empty!\n");
    } else {
        printf("Removed from rear: %d\n", deque[rear]);
        if (front == rear)
            front = rear = -1;
        else
            rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, val;

    while (1) {
        printf("\n===== DEQUE MENU =====\n");
        printf("1. Push Front\n2. Push Back\n3. Pop Front\n4. Pop Back\n5. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push_front(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                push_back(val);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                display();
                break;

            case 0:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}