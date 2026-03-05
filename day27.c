#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
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
            temp = head;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Function to calculate length
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
void findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    // Move pointer of longer list
    if(len1 > len2) {
        diff = len1 - len2;
        for(int i = 0; i < diff; i++)
            temp1 = temp1->next;
    }
    else {
        diff = len2 - len1;
        for(int i = 0; i < diff; i++)
            temp2 = temp2->next;
    }

    // Traverse both lists
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data == temp2->data) {
            printf("%d\n", temp1->data);
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");
    struct Node* head1 = createList(n);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");
    struct Node* head2 = createList(m);

    printf("Intersection Node: ");
    findIntersection(head1, head2);

    return 0;
}