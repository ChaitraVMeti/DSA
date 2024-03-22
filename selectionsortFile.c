#include <stdio.h>
#include <stdlib.h>

void readarray(int [], int);
void displayarray(int [], int);
void selectionsort(int [], int);

int main()
{
    int n = 10;
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

    selectionsort(arr, n);

    fptr = fopen("text.txt", "a");
    if (fptr == NULL)
    {
        printf("File not available.");
        exit(0);
    }

    fputs("\nSorted Array is : ", fptr);
    for (int i = 0; i < k; i++)
    {
        fprintf(fptr, "%d ", arr[i]);
    }
    fclose(fptr);

    return 0;
}

void selectionsort(int a[], int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
