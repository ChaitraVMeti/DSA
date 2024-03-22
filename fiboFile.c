#include<stdio.h>
#include<stdlib.h>

int reverse(int );
int main()
{
    FILE *fptr;

    int num,p;

    fptr=fopen("text.txt","w");
    fprintf(fptr,"%d",152);
    fclose(fptr);
    fptr=fopen("text.txt","r");
    fscanf(fptr,"%d",&num);
    fclose(fptr);
    p=reverse(num);
    fptr=fopen("text.txt","a");
    fputs("\nThe Reverse of the Number is: ",fptr);
    fprintf(fptr,"%d",p);
}
int reverse(int n)
{
    int temp=n;
    int r, sum=0;
    while(n)
{
    r=n%10;
    sum=sum*10+r;
    n=n/10;
}
return sum;
}
