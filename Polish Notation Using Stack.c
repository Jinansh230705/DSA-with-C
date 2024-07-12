#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 5
// Function to return precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

// Function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix expression to postfix expression
char* infixToPostfix(char* infix) {
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len + 2));
    char stack[MAX];
    int top = -1;

    for (i = 0, j = 0; i < len; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top > -1 && stack[top] != '(') {
                return "Invalid Expression";
            } else {
                top--;
            }
        } else if (isOperator(infix[i])) {
            while (top > -1 && precedence(infix[i]) <= precedence(stack[top])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top > -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

int top = -1;
int* stack;

void push() {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter the number to Push: ");
        top++;
        scanf("%d", &stack[top]);
    }
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
    } else {
        top--;
    }
}

void peak() {
    if (top >= 0) {
        printf("Top element: %d\n", stack[top]);
    } else {
        printf("Stack is empty\n");
    }
}

void display() {
    if (top >= 0) {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    int choice;
    stack = (int*)calloc(MAX, sizeof(int));

    do {
        printf("\n---------------------------------------");
        printf("\nPerform Operations");
        printf("\n1. PUSH\n2. POP\n3. PEAK\n4. DISPLAY\n5. Infix to Postfix\n6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peak();
                break;
            case 4:
                display();
                break;
            case 5:
                ;
                char infix[100];
                printf("Enter Infix Expression: ");
                scanf("%s", infix);

                char* postfix = infixToPostfix(infix);
                printf("Postfix Expression: %s\n", postfix);

                free(postfix);
                break;
            case 6:
                printf("Exited\n");
                break;
            default:
                printf("Invalid Selection\n");
        }
    } while (choice != 6);
    return 0;
}
