#include<stdio.h>
#include<stdlib.h>
#define MAX 5
  int top=-1;
  int stack[MAX];

  	void push()
	{
		if(top>=MAX-1)
		{
		printf("\nStack Overflow");
    	}
		else
		{
		printf("Enter the element to Push:");
		top++;
		scanf("%d",&stack[top]);	
		}
	}
	
	void pop()
	{
		if(top<0)
		{
		printf("\nStack Underflow");
    	}
		else
		{
		top--;
		}
	}
	
	void peak()
	{
		if(top<0)
		{
			printf("\nStack is Empty");
		}
		else
		{
			printf("%d",stack[top]);
		}
	}
	
	void display()
	{
		if(top<0)
		{
			printf("\nStack is Empty");
		}
		else
		{   
		    int i;
		    for(i=top;i>=0;i--)
		    {
			printf("\n%d",stack[i]);
		    }
		}
	}
	
  int main()
    {
      int choice;
	   do
	   {
	   	printf("\n------------------------");
	   	printf("\n1.PUSH\n2.POP\n3.PEAK\n4.DISPLAY\n5.EXIT");
	   	printf("\nEnter your Choice:");
	   	scanf("%d",&choice);
	   	
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
			  printf("Exit");
			  break;
			  default:
			  printf("Invilid Input");	
		}
	   }while(choice!=5);
	}  
	

