#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getPriority(char ch) {
    if (ch == '^') return 2;
    else if (ch == '/' || ch == '*') return 1;
    else if (ch == '+' || ch == '-') return 0;
    else return -1;
}

char associativity(char ch) {
    if (ch == '^') return 'R';
    return 'L';
}

void infixToPostfix(char input[]) {
    char postfix[100], stack[100];
    int i = 0, j = 0, top = -1, len;
    len = strlen(input);

    for (i = 0; i < len; i++) {
        char ch = input[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;  // Pop the '(' from the stack
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (top != -1 && 
                   (getPriority(ch) < getPriority(stack[top]) || 
                    (getPriority(ch) == getPriority(stack[top]) && associativity(ch) == 'L'))) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        } else {
            printf("\n\nInvalid character '%c' found \n", ch);
            return;
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
    printf("\nPostfix Expression: %s\n", postfix);
}

int main() {
    char infix_Exp[100];

    printf("Instruction:");
    printf("\n\t1. Use operators (*, /, +, -) only in an expression");
    printf("\n\t2. Operand should be a single character only. e.g. A+B/C-D");
    printf("\nEnter expression: ");

    scanf("%s", infix_Exp);
    printf("\nGiven expression: %s", infix_Exp);

    infixToPostfix(infix_Exp);

    return 0;
}
