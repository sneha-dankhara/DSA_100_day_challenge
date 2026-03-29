#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify (Max Heap)
void heapify(int arr[], int n, int i) {
    int largest = i;        // assume root is largest
    int left = 2*i + 1;
    int right = 2*i + 2;

    // check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);  // recursive call
    }
}

// Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);   // move max to end
        heapify(arr, i, 0);       // heapify reduced heap
    }
}

// Print array
void printArray(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ---------------- MAIN ----------------

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printArray(arr, n);

    return 0;
}