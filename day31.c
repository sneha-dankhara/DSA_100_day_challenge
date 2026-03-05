#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int op, value;
        scanf("%d", &op);

        switch(op) {
            case 1: // push
                scanf("%d", &value);
                if(top == MAX - 1) {
                    printf("Stack Overflow\n");
                } else {
                    stack[++top] = value;
                }
                break;

            case 2: // pop
                if(top == -1) {
                    printf("Stack Underflow\n");
                } else {
                    printf("%d\n", stack[top--]);
                }
                break;

            case 3: // display
                if(top == -1) {
                    printf("Stack is empty\n");
                } else {
                    for(int j = top; j >= 0; j--) {
                        printf("%d ", stack[j]);
                    }
                    printf("\n");
                }
                break;

            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}