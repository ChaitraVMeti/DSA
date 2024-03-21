#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fptr;
    int num,sum=0,n;

    fptr=fopen("text.txt","w");

    printf("Enter the number: ");
    scanf("%d",&num);

    while(num)
    {
        n=num%10;
        sum=sum+n;
        num=num/10;
    }

    fputs("The sum of the given digit is: ",fptr);
    fprintf(fptr," %d",sum);
    fclose(fptr);
}
