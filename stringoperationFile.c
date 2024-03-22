#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

int main()
{
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter string 1: ");
    fgets(str1, MAX_LENGTH, stdin);

    str1[strcspn(str1, "\n")] = '\0';
    printf("Enter string 2: ");

    fgets(str2, MAX_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    char str3[MAX_LENGTH];
    strcpy(str3, str1);

    printf("String 3 (copied from string 1): %s\n", str3);
    int cmp_result = strcmp(str1, str2);

if (cmp_result == 0)
{
    printf("String 1 and String 2 are equal.\n");
}
else if (cmp_result < 0)
{
    printf("String 1 is lexicographically smaller than String 2.\n");
}
else
{
    printf("String 1 is lexicographically greater than String 2.\n");
}
FILE *file = fopen("string_operations.txt", "w");

if (file == NULL)
{
    printf("Error opening file.\n");
return 1;
}
    fprintf(file, "String 1: %s\n", str1);
    fprintf(file, "String 2: %s\n", str2);
    fprintf(file, "String 3 (copied from string 1): %s\n", str3);
    fprintf(file, "Comparison result: %d\n", cmp_result);
    fclose(file);
}
