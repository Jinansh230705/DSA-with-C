#include <stdio.h>
#define MAX 100
int queue[MAX], front=-1,rear=-1,no;

void enqueue(){
	if (front==0 && rear==no-1){
		printf("Queue is Overflow");
      	}
		else {
			printf("Enter the element to enqueue");
			scanf("%d",&queue[++rear]);
	    	}
        }
void dequeue(){
	if ((front==-1&&rear==-1)||(front==rear)){
		printf("QUEUE is Underflow");
	}
	else{
		printf("%d element will dequeue ,queue[front]");
		front++;
	}
}

void peek(){
		if ((front==-1&&rear==-1)||(front==rear)){
		    printf("QUEUE is empty");
		}
		else{
	    	printf("%d is the peek element ,queue[front]");
		}
}

display(){
	int i=front;
	if ((front==-1&&rear==-1)||(front==rear)){
		printf("Queue is empty");
	}
	else{
		while(i<=rear){
			printf(" %d",queue[i]);
			i++;
		}
	}
}
	   
	
	void main(){
		int choice;
	do{
		printf("\n\t 1.ENQUEUE\n\t 2.DEQUEUE\n\t 3.PEEK\n\t 4.DISPLAY\n\t 5.EXIT\n");
		printf("Enter the choice");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Exited");
				break;
			default: 
			printf("Invalid Selection\nTry Again...\nProvide input from the given Range(1/2/3/4/5)");
			break;
		}
	}
	while(choice!=5);
	}
