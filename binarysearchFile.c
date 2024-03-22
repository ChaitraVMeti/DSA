#include <stdio.h>
#include <stdlib.h>

int binarysearch(int [], int, int);
void bubblesort1(int [], int);

int main()
{
    int arr[100];
    int n = 15, key, num;
    int p, k = 0;
    FILE *fptr;

    fptr = fopen("text.txt", "r");

    if (fptr == NULL)
    {
        printf("File not available.");
        exit(1);
    }
    while (fscanf(fptr, "%d", &num) != EOF && k < 100)
    {
        arr[k] = num;
        k++;
    }
    fclose(fptr);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    bubblesort1(arr, n);

    fptr = fopen("text.txt", "a");
    if (fptr == NULL)
    {
        printf("File not available.");
        exit(1);
    }

    fputs("\nStored Elements are : ", fptr);
    for(int i = 0; i < n; i++)
    {
        fprintf(fptr, "%d ", arr[i]);
    }

    p = binarysearch(arr, key, n);

    if (p == 1)
    {
        fputs("\nThe key is found\n", fptr);
    }
    else
    {
        fputs("\nThe key is not found", fptr);
    }
    fclose(fptr);
    return 0;
}

void bubblesort1(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int binarysearch(int a[], int key, int n)
{
    int l = 0, u = n - 1;
    int mid;
    while (l <= u)
    {
        mid = (l + u) / 2;
        if (key == a[mid])
            return 1;
        else if (key < a[mid])
            u = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
