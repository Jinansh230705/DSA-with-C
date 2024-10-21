#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack{
  char data;
  struct Stack* link;
};

struct Stack *stack = NULL;
struct Stack *top = NULL;

struct Stack* createNode(){
  struct Stack *node = (struct Stack*)malloc(sizeof(struct Stack));
  printf("Enter the element:");
  scanf(" %c",&node->data);
  node->link=NULL;
  return node;
}

void push(char x){
    struct Stack *newNode=(struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = x;
    newNode->link = stack;
    stack = newNode;
}

char pop(){
    char x;
    if(stack==NULL){
       printf("Stack Underflow\n");
       return;
    } 
    else{
       struct Stack *temp=stack;
       x = temp->data;
       stack = stack->link;
       free(temp);
    }
    return x;
}
  
void display(){
  struct Stack *ptr = stack;
  if(stack==NULL){
    printf("Stack Underflow\n");
  }
  else{
    while(ptr!=NULL){
      printf("%c ", ptr->data);
      ptr = ptr->link;
    }
  }
}

int precedence(char x){
    if(x == '+' || x == '-')
    return 1;
    if(x == '*' || x == '/')
    return 2;
    return 0;
}
  
void infixToPostfix(char* infix){
    char postfix[100];
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(stack != NULL && stack->data != '('){
                postfix[j++] = pop();
            }
            if(stack != NULL && stack->data == '('){
                pop();
            }
        }
        else{
            while(stack != NULL && precedence(infix[i]) <= precedence(stack->data)){
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while(stack != NULL){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("%s\n", postfix);
}

int main()
{
    char infix[100];
    printf("Enter the infix Expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}