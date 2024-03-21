#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fptr;

    fptr=fopen("text.txt","w");

    fputs("Hello World\n",fptr);

    fclose(fptr);
}
