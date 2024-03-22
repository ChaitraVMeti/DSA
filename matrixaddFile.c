#include<stdio.h>
#include<stdlib.h>


#define ROW 10
#define COL 10


void readmatrix(int [][COL], int, int);


void displaymatrix(int [][COL], int, int);


void addmat(int [][COL], int [][COL], int [][COL], int, int);

int main()
{
    int a[ROW][COL];
    int b[ROW][COL];
    int y[ROW][COL];
    int r, c;


    printf("Enter the order (rows and columns): ");
    scanf("%d %d", &r, &c);


    if (r <= 0 || r > ROW || c <= 0 || c > COL) {
        printf("Invalid dimensions.\n");
        return 1;
    }


    printf("Enter the matrix A elements: \n");
    readmatrix(a, r, c);

        printf("Enter the matrix B elements: \n");
    readmatrix(b, r, c);

        printf("The matrix A elements are: \n");
    displaymatrix(a, r, c);
    printf("The matrix B elements are: \n");
    displaymatrix(b, r, c);

       addmat(a, b, y, r, c);

       printf("The Sum of matrix A & B is: \n");
    displaymatrix(y, r, c);

    return 0;
}


void addmat(int a[][COL], int b[][COL], int y[][COL], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            y[i][j] = a[i][j] + b[i][j];
        }
    }
}


void displaymatrix(int a[][COL], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}


void readmatrix(int a[][COL], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
