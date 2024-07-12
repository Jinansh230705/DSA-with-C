#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
   char infix[50];
   char postfix[50];
   char stack[50];

   int i, j=0, k=0;
   printf("\nEnter the Infix Expresion: ");
   scanf("%s", &infix);
   printf("\nInfix expression in string : %s", infix);
   printf("\nInfix expression in character form: ");
   for(i=0;i<strlen(infix);i++){
      printf("%c", infix[i]);
   }
       
   for(i=0;i<strlen(infix);i++){
      if((infix[i]>='A' && infix[i]<='Z')|| (infix[i]>='a' && infix[i]<='z')){
         postfix[k]=infix[i];
         k++;
      }
      else{
         stack[j]=infix[i];
         j++;
      }
   }
         
   printf("\n Element (Operators): ");
   for(i=0;i<=j;i++){
      printf("%c", stack[i]);
   }

   printf("\nOpearands: ");
   for (i=0;i<k;i++){
      printf("%c", postfix[i]);
   }     
}
