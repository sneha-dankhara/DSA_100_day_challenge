#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, m, value;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        if(top == MAX - 1) {
            printf("Stack Overflow\n");
        } else {
            stack[++top] = value;
        }
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        if(top == -1) {
            printf("Stack Underflow\n");
            break;
        } else {
            top--; // pop element
        }
    }

    // Print remaining stack from top to bottom
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        for(int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    return 0;
}