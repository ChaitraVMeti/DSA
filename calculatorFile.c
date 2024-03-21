#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n1,n2;
   FILE *fptr;
   fptr=fopen("text.txt","w");
   printf("enter the two numbers:");
   scanf("%d%d",&n1,&n2);

   fputs("\nthe addition of two numbers is ",fptr);
   fprintf(fptr,"%d",n1+n2);

   fputs("\nthe subtraction of two numbers is ",fptr);
   fprintf(fptr,"%d",n1-n2);

   fputs("\nthe multiplication of two numbers is ",fptr);
   fprintf(fptr,"%d",n1*n2);

   fputs("\nthe division of two numbers is ",fptr);
   fprintf(fptr,"%d",n1/n2);
   fclose(fptr);
}
