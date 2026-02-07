#include <stdio.h>

int main() {
    int n, pos, val;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n + 1];   // size increased by 1

    printf("Enter %d elements in array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    printf("Enter element value: ");
    scanf("%d", &val);

    pos = pos - 1;  // convert to 0-based index

    // shift elements to right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;

    printf("Updated array is: { ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("}");

    return 0;
}
