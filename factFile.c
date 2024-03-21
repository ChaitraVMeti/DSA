#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fptr;
    int n, fact=1;
    fptr=fopen("text.txt","w");

    printf("Enter the no.: ");
    scanf("%d",&n);

    for(int i=n;i>0;i--)
        fact =fact*i;

    fputs("The factorial of the number ",fptr);
    fprintf(fptr,"%d %d",n,fact);

    fclose(fptr);

}
