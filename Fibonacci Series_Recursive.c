#include<stdio.h>
int fibonacci(int num){
    if (num==0||num==1){
        return num;
    }
    else{
        return(fibonacci(num-1)+fibonacci(num-2));
    }
}

    void main(){
        int t,i;
        printf("\nEnter the number of terms:");
        scanf("%d",&t);
        printf("\n Fibonacci sequence: ");
        for(i=0;i<t;i++){
            printf("%d", fibonacci(i));
        }
    }
