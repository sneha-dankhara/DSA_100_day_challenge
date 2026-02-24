#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

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
    return head;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node dummy;  // temporary node
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if(head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    return dummy.next;
}

// Function to print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);
    printf("Enter %d sorted integers:\n", n);
    struct Node* head1 = createList(n);

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);
    printf("Enter %d sorted integers:\n", m);
    struct Node* head2 = createList(m);

    struct Node* mergedHead = mergeLists(head1, head2);

    printf("Merged Linked List:\n");
    printList(mergedHead);

    return 0;
}