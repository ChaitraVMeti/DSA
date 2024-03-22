#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[100];
    FILE *fptr;
    int sum = 0, h = 0, k = 0, num, s = 99999;


    fptr = fopen("text.txt", "r");
if (fptr == NULL)
    {
        printf("File not available.");
        exit(0);
    }


while(fscanf(fptr, "%d", &num) != EOF && k < 100)
    {
        arr[k] = num;
        k++;
    }
    fclose(fptr);


    for(int i = 0; i < k; i++)
    {
        sum += arr[i];
        if(arr[i] > h)
            h = arr[i];
        if(arr[i] < s)
            s = arr[i];
    }


    fptr = fopen("text.txt","a");

if (fptr == NULL)
    {
        printf("File not available.");
        exit(0);
    }

    fprintf(fptr, "\nHighest Element is %d", h);
    fprintf(fptr, "\nSmallest Element is %d", s);
    fprintf(fptr, "\nSum of the Element is %d", sum);
    fprintf(fptr, "\nAverage of the Element is %f", (float)sum / k);

    fclose(fptr);
    return 0;
}
