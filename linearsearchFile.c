#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    int num, s, k = 0;
    int a[100];

    fptr = fopen("text.txt", "r");

    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }
    else
    {

        while (fscanf(fptr, "%d", &num) != EOF && k < 100)
        {
            a[k] = num;
            k++;
        }
        fclose(fptr);

                fptr = fopen("text.txt", "a");
        if (fptr == NULL)
        {
            printf("Unable to open file.\n");
            exit(1);
        }


        printf("Enter the element to search: ");
        scanf("%d", &s);


        int found = 0;
        for (int i = 0; i < k; i++)
        {
            if (s == a[i])
            {
                found = 1;
                break;
            }
        }

        if (found)
            fputs("\nThe Element is Found.", fptr);
        else
            fputs("\nElement not Found.", fptr);

        fclose(fptr);
    }
    return 0;
}
