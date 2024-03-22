#include<stdio.h>
#include<stdlib.h>

int ispalindrome(int);

int main()

{

    FILE *fptr;
    int num,p;
    fptr=fopen("text.txt","w");
    fprintf(fptr,"%d",151);
    fclose(fptr);
    fptr=fopen("text.txt","r");
    fscanf(fptr,"%d",&num);
    p=ispalindrome(num);
    fclose(fptr);
    fptr=fopen("text.txt","a");

if(p)
        fputs("\nThe Given No. is Palindrome:",fptr);
else
        fputs("\nThe Given No. is Not Palindrome:",fptr);

        fclose(fptr);
}

int ispalindrome(int n)
{

    int temp=n;
    int r, sum=0;
    while(n)
{
    r=n%10;
    sum=sum*10+r;
    n=n/10;
}
    if(temp==sum)
    return 1;
    return 0;
}
