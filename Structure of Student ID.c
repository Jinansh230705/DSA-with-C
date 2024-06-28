struct student 
{
    int id;
    char gender;
    float per;
};

int main()
{
    struct student std[3];
    struct student *ptr=std;
    
 int i;
 for(i=0;i<3;i++)
 {
  printf("ENTER ID\n");
  scanf("%d",&(ptr+i)->id);
  printf("ENTER GENDER\n");
  scanf(" %c",&(ptr+i)->gender);
  printf("ENTER PER\n");
  scanf("%f",&(ptr+i)->per);
 }
printf("ID\tGENDER\tPER\n");
for(i=0;i<3;i++)
 {
     printf("%d\t%c\t    %.2f",(ptr+i)->id,(ptr+i)->gender,(ptr+i)->per);
     printf("\n");
 }
  
    return 0;
}



