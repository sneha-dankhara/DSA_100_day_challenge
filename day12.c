#include <stdio.h>

int main()
{
    int m, n;

    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter elements of the matrix:\n");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if matrix is square
    if(m != n)
    {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    int isSymmetric = 1;

    // Compare matrix[i][j] with matrix[j][i]
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] != matrix[j][i])
            {
                isSymmetric = 0;
                break;
            }
        }
        if(isSymmetric == 0)
            break;
    }

    if(isSymmetric == 1)
        printf("Symmetric Matrix\n");
    else
        printf("Not a Symmetric Matrix\n");

    return 0;
}
