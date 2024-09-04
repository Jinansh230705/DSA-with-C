#include <stdio.h>
void insertionSort(int arr[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		j=i-1; //last element of sorted array
		temp=arr[i];
		while(j>=0 &&  arr[j]>temp){
			arr[j+1]=arr[j];
			arr[j]=temp;
			j=j-1; //j--;
		}
		arr[j+1]=temp;
	}
}

void quickSort(int arr[], int first, int last){
	if(first<last){
	int i,j,pivot,temp;
	i=first;
	j=last;
	pivot=first; 
	while(i<j){
		while(arr[pivot]>=arr[i]){
			i++;
		}
		while(arr[pivot]<arr[j]){
			j--;
		}
		if(i<j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[pivot];
	arr[pivot]=arr[j];
	arr[j]=arr[i];
	arr[i]=temp;
	quickSort(arr,first,i-1);
	quickSort(arr,j+1,last);
}
}

int main(){
	int i,n;
	printf("Enter elements");
	scanf("%d", &n);
	int arr[n];
	for(i=0;i<n;i++){
		printf("Enter elements to enter:");
		scanf("%d", &arr[i]);
	}
	printf("Elements :");
	for (i=0;i<n;i++){
		printf(" %d",arr[i]);
	}
	
}
