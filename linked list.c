#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data; //4 byte
	struct Node *link;//8 byte
};
struct Node* head=NULL;

 struct Node* createNode(){
	struct Node *newNode=NULL;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=101;
	newNode->link=NULL;
	return newNode;
}

void insertionatbeginning(){
	struct Node* node=NULL;
//stuct Node* ptr= head;
	node= createNode(90);
//	while (ptr->!=NULL){
//		ptr=ptr->link
//	}
//	ptr->node;
	node->link=head;
	head=node;
}

void deletion_at_end(int x_data){
	struct Node* ptr=head;
	struct Node* temp=NULL;
	while(ptr->link!=NULL){
	temp=ptr;
	ptr=ptr->link;
}
temp->link=NULL;
free(ptr);
ptr=NULL;
}

void deletion_At_Beginging(){
	struct Node* ptr=head;
	ptr=ptr->link ;
	free(head);
	head=NULL;
	head=ptr;
}

void deletion_At_Node(int x_data){
	struct Node* ptr=NULL;
	struct Node* temp=NULL;
	while(ptr->data!=x_data){
	
		temp=ptr;
		ptr=ptr->link;
	}
	temp->link=ptr->link;
	free(ptr);
	ptr=NULL;
}

void deletion_At_Particular_Position(int pos){
	struct Node* ptr=head;
	struct Node* temp=NULL;
	int count=1;
	while(count!=pos){
		temp=ptr;
		ptr->link;
		count++;//3
	}
	temp->link=ptr->link;
	free(ptr);
	ptr=NULL;
}

void deletion_Before_Particular_Node(int x_data){
	struct Node* ptr=head;
	struct Node* temp=NULL;
	struct Node* prev=NULL;
	while(ptr->data!=x_data){
		temp=prev;
		prev=ptr;
		ptr=ptr->link;
	}
	temp->link=ptr->link;
	free(ptr);
	prev=NULL;
}

void deletion_After_Particular_Node(int x_data){
	struct Node* ptr=head;
	struct Node* temp=NULL;
	while(ptr->data!=x_data){
		ptr=ptr->link;
	}
	temp=ptr->link;
	ptr->link=temp->link;
	free(temp);
	temp=NULL;
}

void display(){
	struct Node* ptr=head;
	printf("\n head->");
	while(ptr!=NULL){
		printf("%d",ptr->data);
		ptr=ptr->link;
		printf("->NULL");
	}
}

void search(int x_data){
	struct Node* ptr=head;
	while(ptr->data!=x_data){
		ptr=ptr->link;
	}
	printf("(%d) data found at [%u]adress.",ptr->data,ptr);
	//return ptr;
}

int main(){
//	struct Node* ptr= search(104);
//	printf("(%d) data found at [%u]adress.",ptr->data,ptr);

	
	
}
