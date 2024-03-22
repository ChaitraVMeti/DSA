#include<stdio.h>
#include<stdlib.h>

void bubblesort1(int *, int);
void bubblesort2(int *, int);

int main()
{
    FILE *fptr;
    int num;
    int arr[100];
    int k = 0;
    char a[100] = "Ascending Order: ";
    char d[100] = "Descending Order: ";
    int z = 20;

    fptr = fopen("text.txt", "r");

    if (fptr == NULL)
    {
        printf("Unable to open file for reading.\n");
        exit(0);
    }

    while (fscanf(fptr, "%d", &num) == 1 && k < 100)
    {
        arr[k] = num;
        k++;
    }
    fclose(fptr);

    bubblesort1(arr, z);
    fptr = fopen("text.txt", "a");
    fprintf(fptr, "\n%s", a);

    for(int i = 0; i < z; i++)
    {
        fprintf(fptr, "%d ", arr[i]);
    }
    fclose(fptr);

    bubblesort2(arr, z);
    fptr = fopen("text.txt", "a");
    fprintf(fptr, "\n%s", d);

    for(int i = 0; i < z; i++)
    {
        fprintf(fptr, "%d ", arr[i]);
    }
    fclose(fptr);

    printf("The Elements are perfectly Sorted and again Stored in File Successfully\n");
    return 0;
}

void bubblesort1(int a[], int n)
{
    int temp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void bubblesort2(int a[], int n)
{
    int temp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            if(a[j] < a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
