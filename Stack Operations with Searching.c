#include<stdio.h>
#include<stdlib.h>
  int top=-1;
  int *stack;
  int n;
  
  	void push()
	{
		if(top>=n-1)
		{
		printf("\nSTAKE OVERFLOW");
    	}
		else
		{
		printf("ENTER ELEMENT TO PUSH:");
		top++;
		scanf("%d",&stack[top]);	
		}
	}
	
	void pop()
	{
		if(top<0)
		{
		printf("\nSTAKE UNDERFLOW");
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
			printf("\nSTAKE IS EMPTY");
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
			printf("\nSTAKE IS EMPTY");
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
	void resize()
	{
		printf("Relloc the size of Elements");
		scanf("%d",&n);
	    stack=(int*)realloc(stack,n*sizeof(int));
	}
	void search(){
	    int n;
	    printf("Eneter the element for search=");
	    scanf("%d",&n);
	    for(int i=top;i>=0;i--)
	    {
	        if(stack[i]==n)
	        {
	            printf("Your element Position is a : %d",i+1);
	            return;
	        }
	    }
	}
  int main()
    {
     
    printf("ENTER NO. OF ELEMENT\n");
    scanf("%d",&n);
    stack=(int*)calloc(n,sizeof(int));
      int choice;
	   do
	   {
	   	printf("\n_____________________________");
	   	printf("\n1.PUSH\n2.POP\n3.PEAK\n4.DISPLAY\n5.RESIZE\n6.SEARCH\n7.EXIT");
	   	printf("\nEnter Your Choice   ");
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
		          resize();
		          break;
		          case 6:
		          search();
		          break;
			  case 7:
			  printf("Exit");
			  break;
			  default:
			  printf("Invilid Input");	
		}
	   }while(choice!=7);
	   	
	}
