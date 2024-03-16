#include<stdio.h>
#define MAXSIZE 10

   int main()
{
    FILE*input,*output;
    int a[MAXSIZE];
    int i=0,j,res=0;

    input=fopen("input.txt","r");
    output=fopen("output.txt","w");

    if(input==NULL)
 {
     perror("\nError:\n");
     return 1;
 }
     while(!feof(input))
     {
         fscanf("%d",&a[i]);
          i++;
     }
      for(j=0;j<i;j++)
 {
      printf("\n%d",a[j]);
      printf("+");
      res=res+a[j];
 }
      return 0;
}
