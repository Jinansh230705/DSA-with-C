#include <stdio.h>
#define MAX 100
int queue[MAX], front=-1,rear=-1,no=0;

    void createQueue()
     {
    	printf("Enter the number of element to store: ");
		scanf("%d", &no);
	    if (no>0)
     	{
		     printf("Queue is ready to store %d element\n", no);
    	}
		else
		{
		    printf("Maxmimum no is %d \n", MAX);
		}
     }
	void enqueue()
	{   
	    if(front==0 && rear==no-1)
	    {
	       printf("Queue is OVERFLOW\n");
	    }
		else
		{
	       rear++;
		   printf("Enter element in ENQUEUE ");
		   scanf("%d", &queue[rear]);
		      //OR scanf("%d", &queue[++rear]);
		}
	}
	void dequeue()
	{
	     if((front==-1 && rear==-1) || (front==rear))
	    {
	         printf("Queue is UNDERFLOW\n");
	    }
	    else
	    {
	        printf("%d element Dequeue\n",queue[front++]);
	    }
	}
	void peek()
	{
	    if((front==-1 && rear==-1) || (front==rear))
	    {
	         printf("Queue is EMPTY\n");
	    }
	    else
	    {
	          printf("Peek of Queue is %d\n",queue[front]);
	    }
	}
	void display()
	{    int i=front;
	     if(front==-1 && rear==-1 || rear==front)
	     {
	         printf("Queue is EMPTY\n");
	     }
		 else
		 {
		     	while(i<rear)
	           {
	            	printf("QUEUE IS %d\n",queue[i]);
	           
	               i++;
	           }
		 }
	}
	void main()
	{
	    int choice;
	    do
	    {
	        printf("\n\t1.CREAT\n\t2.ENQUEUE\n\t3.DEQUEUE\n\t4.PEEK\n\t5.DISPLAY\n\t6.EXIT");
	        printf("\nEnter the CHOICE ");
	        scanf("%d",&choice);
	        switch(choice)
	        {
	            case 1:
	            	createQueue();
	            	break;
	           	case 2:
	            	enqueue();
	            	break;
	           	case 3:
	            	dequeue();
	            	break;
	           	case 4:
	            	peek();
	            	break;
	           	case 5:
	                display();
	            	break;
	        	case 6:
	                printf(".....EXITED.....");
	            	break;
	           	default:
	           	printf("INVALID INPUT\n CHOOSE INPUT FROM GIVEN CHOICE ONLY(1,2,3,4,5,6)");
	        }
	    }while(choice!=6);

	}

