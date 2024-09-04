#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
  int roll;
  char name[20];
  char div[6];
  float cgpa;
  struct Student *link1;
  struct Student *link2;
  struct Student *link3;
  struct Student *link4;
  struct Student *next;
};

struct Student *source = NULL;

  struct Student* readData(){
  struct Student *std = (struct Student *)malloc(sizeof(struct Student));
  printf("Enter Student data\n");
  printf("Enter Roll No.: ");
  scanf("%d", &std->roll);
  printf("Enter Name: ");
  scanf("%s", &std->name);
  printf("Enter Division: ");
  scanf("%s", &std->div);
  printf("Enter CGPA: ");
  scanf("%f", &std->cgpa);
  std->link1 = NULL;
  std->link2 = NULL;
  std->link3 = NULL;
  std->link4 = NULL;
  std->next = NULL;
  return std;
}

void createRecord(){
	struct Student *newData = readData();
	struct Student *std;
	
	if(source==NULL){
		source = newData;
	} 
	else if(source->link1==NULL){
		source->link1=newData;
	}
	else if(source->link2==NULL){
		source->link2=newData;
	}
	else if(source->link3==NULL){
		source->link3=newData;
	}
	else{
		source->link4=newData;
	}
}

void display(struct Student* std){
    printf("\t\t\tStudent Record\n");
    printf("_______________________________________________________________________\n");
    printf("\nRoll No.\tName\t\tDivision\tCGPA\n");
    printf("%d\t\t%s\t\t%s\t\t%0.2f\n",std->roll,std->name,std->div,std->cgpa);
    printf("_______________________________________________________________________\n");
    printf("\t\t\tFriend List\n");
    printf("_______________________________________________________________________\n");
    printf("\n1. %s\n2. %s\n3. %s\n4. %s\n",std->link1->name,std->link2->name,std->link3->name,std->link4->name);
}


void main(){
	createRecord();
	createRecord();
	createRecord();
	createRecord();
	createRecord();	
	display(source);
}
