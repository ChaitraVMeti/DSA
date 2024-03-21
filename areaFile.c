#include<stdio.h>
#include<stdlib.h>

int main()
{
    int l,b;

    FILE *fptr;
    fptr=fopen("text.txt","w");

    printf(" enter the length and width: ");
    scanf("%d%d",&l,&b);

    int area=l*b;

    fputs("the area of the given digit is:",fptr);
    fprintf(fptr,"%d",area);



}
