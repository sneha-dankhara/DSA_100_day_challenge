#include <stdio.h>

int main() {
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[100][100];

    printf("Enter matrix elements:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    int minDim = (m < n) ? m : n;

    for (int i = 0; i < minDim; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal = %d\n", sum);

    return 0;
}