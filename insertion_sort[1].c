#include<stdio.h>
void insertion_sort(int arr[],int n){
	int i,j,temp;
	for(i = 1;i<n; i++){
		j = i-1;
		temp = arr[i];
		while(j >= 0&&arr[j]>temp){
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1] =  temp;
	}
	printf("-- Sorted array --\n");
}
int main(){
	int n;
	printf("\nEnter the Number of elements:");
	scanf("%d",&n);
	int arr[n];
	int i;
	for( i = 0; i<n ;  i++){
		printf("\nEnter element for arr[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	
	insertion_sort(arr,n);
	
	for(i = 0;i<n;i++){
		printf("\nElment at arr[%d]: %d",i,arr[i]);
	}
	
	return 0;
}
