#include <stdio.h>

struct Node{
  struct Node* prev;
  int data;
  struct Node* next;
};
struct Node* start=NULL;

struct Node* createNode(){
  struct Node* newNode=NULL;
  newNode=(struct Node*)malloc(sizeof(struct Node));
  printf("\n Enter the Data: ");
  scanf("%d", &newNode->data);
  newNode->prev=NULL;
  newNode->next=NULL;
  return newNode;
}

void insertionAtBegining(){
  struct Node* node= createNode();
  node->next=start;
//  start->prev=node;
  start=node;
}

void display(){
  struct Node* ptr=start;
  printf("\n head-> ");
  while(ptr!=NULL){
    printf(" %d",ptr->data);
    ptr=ptr->next;
    if(ptr==NULL){
      break;
    }
  }
  printf(" ->NULL");
}

main(){
  insertionAtBegining();
  insertionAtBegining();
  insertionAtBegining();
  insertionAtBegining();
  display();

}
