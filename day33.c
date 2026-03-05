#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Push operator onto stack
void push(char c) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

// Pop operator from stack
char pop() {
    if(top == -1) {
        return '\0'; // empty
    }
    return stack[top--];
}

// Peek top of stack
char peek() {
    if(top == -1)
        return '\0';
    return stack[top];
}

// Operator precedence
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if(isalnum(c)) {
            // Operand → add to postfix
            postfix[k++] = c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            // Pop until '('
            while(top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else {
            // Operator
            while(top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}