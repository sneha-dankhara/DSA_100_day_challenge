#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    if(n == 0)
    {
        printf("Array is empty.\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d sorted elements:\n", n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int j = 0;   // index for unique elements

    for(int i = 1; i < n; i++)
    {
        if(arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    printf("Unique elements are:\n");

    for(int i = 0; i <= j; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
