#include <stdio.h>

#define MAX 200000
#define OFFSET 100000

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix = 0;

    // store first occurrence of prefix sum
    int firstIndex[MAX] = {0};

    for (int i = 0; i < MAX; i++)
        firstIndex[i] = -2;

    firstIndex[OFFSET] = -1; // prefix sum = 0 at index -1

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        int idx = prefix + OFFSET;

        if (firstIndex[idx] == -2) {
            firstIndex[idx] = i;
        } else {
            int len = i - firstIndex[idx];
            if (len > maxLen)
                maxLen = len;
        }
    }

    printf("\nLength of longest zero sum subarray: %d\n", maxLen);

    return 0;
}