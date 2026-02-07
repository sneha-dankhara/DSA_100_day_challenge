//Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left
#include <stdio.h>
int main()
{
    int n,pos,i;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);

    int arr[n+1];

    printf("Enter %d elements in array:- ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    pos=pos-1;

    printf("updated array:- ");
    for(i=pos ; i<n-1 ; i++){
        arr[i]=arr[i+1];
    }

    for(i=0 ; i<n-1 ; i++){
        printf("%d ",arr[i]);
    }
}

