#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, k, n;
    float A[20][20], c, x[10], sum = 0.0;
    printf("\nEnter the order of matrix: ");
    scanf("%d", &n);
    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= (n + 1); j++)
        {
            printf("A[%d][%d] : ", i, j);
            scanf("%f", &A[i][j]);
        }
    }
    //loop for the generation of upper triangular matrix
    for (j = 1; j <= n; j++)
    {
        for (i = j + 1; i <= n; i++)
        {
            c = A[i][j] / A[j][j];
            for (k = 1; k <= n + 1; k++)
            {
                A[i][k] = A[i][k] - c * A[j][k];
            }
        }
    }
    //back-substitution
    for (i = n; i >= 1; i--)
    {
        sum = 0;
        for (j = i + 1; j <= n; j++)
        {
            sum = sum + A[i][j] * x[j];
        }
        x[i] = (A[i][n + 1] - sum) / A[i][i];
    }

    printf("\nThe solution is: \n");
    for (i = 1; i <= n; i++)
    {
        printf("\nx%d=%f\t", i, x[i]);
    }
    return (0);
}