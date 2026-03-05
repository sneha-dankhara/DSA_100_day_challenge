#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {
    int n, coeff, exp;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent for each term:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Print polynomial
    printf("Polynomial: ");

    temp = head;
    while(temp != NULL) {
        if(temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if(temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        temp = temp->next;
        if(temp != NULL) {
            printf(" + ");
        }
    }

    printf("\n");
    return 0;
}