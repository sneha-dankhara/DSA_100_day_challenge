#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Frequency counting
    for(int i = 0; i < n; i++) {
        int count = 1;

        if(arr[i] == -9999)  // already counted
            continue;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -9999;   // mark as counted
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}