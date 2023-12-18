// Write a program using 2D array to multiply two matrices.
#include <stdio.h>

// Function to multiply two matrices A and B and store the result in C
void multiplyMatrices(int m, int n, int p, int A[][n], int B[][p], int C[][p])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int rows, int cols, int matrix[][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m, n, p;

    // Dimensions of matrix A (m x n) and matrix B (n x p)
    printf("Enter the dimensions of matrix A (m x n): ");
    scanf("%d %d", &m, &n);
    printf("Enter the dimensions of matrix B (n x p): ");
    scanf("%d %d", &n, &p);

    // Declare 2D arrays for matrices A, B, and C
    int A[m][n];
    int B[n][p];
    int C[m][p];

    // Input elements for matrices A and B
    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Multiply matrices A and B and store the result in matrix C
    multiplyMatrices(m, n, p, A, B, C);

    // Display the resulting matrix C
    printf("Resulting matrix C:\n");
    displayMatrix(m, p, C);

    return 0;
}
