#include <stdio.h>
#include <stdlib.h>


void insertionSort(int [], int);

int main()
{
    int arr[10], k = 0, num;
    FILE *fptr;


    fptr = fopen("text.txt", "r");

    if (fptr == NULL)
    {
        printf("File not available.");
        exit(0);
    }


    while (fscanf(fptr, "%d", &num) != EOF && k < 10)
    {
        arr[k] = num;
        k++;
    }

    fclose(fptr);


    insertionSort(arr, k);


    fptr = fopen("text.txt", "a");

    if (fptr == NULL)
    {
        printf("File not available.");
        exit(0);
    }


    fputs("\n\nThe Elements After Sorting using Insertion Algorithm: ", fptr);
    for (int i = 0; i < k; i++)
    {
        fprintf(fptr, "%d ", arr[i]);
    }

    fclose(fptr);

    return 0;
}


void insertionSort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

    while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = key;
    }
}
