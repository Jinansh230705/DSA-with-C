#include <stdio.h>
int main()
{
    int arr[5];
    int i;
    printf("Enter 5 Elements:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<5;i++)
    {
        printf("%d\t",arr[i]);
    }
    int arr1[10];
    for(i=0;i<5;i++)
    {
      arr1[i]=arr[i];
    }
    printf("\nIncreased the Size of Array!\n");
    for(i=0;i<10;i++)
    {
        printf("%d\t",arr1[i]);
    }
    printf("\nEnter other 5 Elements:\n");
    for(i=5;i<10;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("\nNew Array is:\n");
     for(i=0;i<10;i++)
    {
        printf("%d\t",arr1[i]);
    }
    return 0;
}
