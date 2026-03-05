#include <stdio.h>
#include <stdlib.h>

// Structure for Linked List Node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, count = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++) {

        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } 
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter key to count: ");
    scanf("%d", &key);

    temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    printf("Number of occurrences of %d = %d\n", key, count);

    return 0;
}
