#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    temp->next = head;

    printf("Circular Linked List: ");

    struct Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while(current != head);

    return 0;
}