#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

Node* top = NULL; 

void push() 
{
    int item;
    printf("Enter element to push: ");
    scanf("%d", &item);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

void pop() 
{
    if (top == NULL) 
    {
        printf("Stack Underflow\n");
        return;
    }
    
    Node* temp = top;
    top = top->next;
    free(temp);
}

void peak() 
{
    if (top == NULL) 
    {
        printf("Stack is Empty\n");
        return;
    }
}

void display() 
{
    if (top == NULL) 
    {
        printf("Stack is Empty\n");
        return;
    }

    Node* temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() 
{
    int choice;
    do {
        printf("\n-------------------------\n");
        printf("1. PUSH\n2. POP\n3. PEAK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice) 
        {
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
                printf("Exited\n");
                break;
            default:
                printf("Invalid Selection\n");
                break;
        }
    } while (choice != 5);

    Node* temp;
    while (top != NULL) 
    {
        temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}
