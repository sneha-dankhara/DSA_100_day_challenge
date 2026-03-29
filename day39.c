#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up (for insert)
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify Down (for extractMin)
void heapifyDown(int index) {
    int left, right, smallest;

    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Insert operation
void insert(int val) {
    if (size == MAX) {
        printf("Heap Overflow!\n");
        return;
    }

    heap[size] = val;
    heapifyUp(size);
    size++;
}

// Peek (minimum element)
void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

// Extract Min
void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// ---------------- MAIN ----------------

int main() {
    int n, value;
    char operation[20];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter operation (insert x / peek / extractMin): ");
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        }
        else if (strcmp(operation, "peek") == 0) {
            peek();
        }
        else if (strcmp(operation, "extractMin") == 0) {
            extractMin();
        }
        else {
            printf("Invalid operation!\n");
        }
    }

    return 0;
}