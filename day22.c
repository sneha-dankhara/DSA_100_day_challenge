#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter %d integers:\n", n);

    // Create linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Count nodes by traversal
    int count = 0;
    temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Number of nodes in the linked list = %d\n", count);

    return 0;
}