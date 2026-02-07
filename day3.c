#include <stdio.h>

int main()
{
    int n, i, k;
    int found = 0, count = 0, freq = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements of array: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        count++;                              if (arr[i] == k) {
            freq++;
            printf("Found at index %d\n", i);   // or i+1 for position
            found = 1;
        }
    }

    if (!found)
        printf("Not found\n");
    else
        printf("Total occurrences: %d\n", freq);

    printf("Total comparisons: %d\n", count);

    return 0;
}
