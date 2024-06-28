#include <stdio.h>
#include <stdlib.h>
int n;
int top = -1;
int* stack;

void push() {
    if (top >= n - 1) {
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

void resize(){
printf("Enter the New Size:");
scanf("%d",&n);
}

int main() {
    int choice;
    printf("Enter the no. of elements:");
    scanf("%d",&n);
    stack = (int*)calloc(n, sizeof(int));

    do {
        printf("\n---------------------------------------");
        printf("\nPerform Operations");
        printf("\n1. PUSH\n2. POP\n3. PEAK\n4. DISPLAY\n5. RESIZE \n6. EXIT\n");
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
            case 5: resize();
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
