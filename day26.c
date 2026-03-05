#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        // if first node
        if(head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Traversal in forward direction
    printf("Doubly Linked List (Forward Traversal):\n");

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}