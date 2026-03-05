#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k, value;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    // Creating linked list
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

    printf("Enter k: ");
    scanf("%d", &k);

    if(k > n)
        k = k % n;

    // Find last node
    struct Node* last = head;
    int count = 1;

    while(last->next != NULL) {
        last = last->next;
        count++;
    }

    // Make list circular
    last->next = head;

    // Move to (n-k)th node
    struct Node* current = head;
    for(int i = 1; i < n - k; i++) {
        current = current->next;
    }

    // Update head and break circle
    head = current->next;
    current->next = NULL;

    printf("Rotated Linked List: ");

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}