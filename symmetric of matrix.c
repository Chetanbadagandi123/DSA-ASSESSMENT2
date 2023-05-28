#include <stdio.h>
#define MAX_SIZE 10

int is_symmetric(int matrix[][MAX_SIZE], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (matrix[i][j] != matrix[j][i])
                return 0;
        }
    }
    return 1;
}

int main()
{
    FILE *inputFile, *outputFile;
    int matrix[MAX_SIZE][MAX_SIZE];
    int size, i, j;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Failed to open the input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &size);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            fscanf(inputFile, "%d", &matrix[i][j]);
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    fclose(inputFile);

    int symmetric = is_symmetric(matrix, size);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Failed to open the output file.\n");
        return 1;
    }

    if (symmetric)
    {
        fprintf(outputFile, "The matrix is symmetric.\n");
        printf("The matrix is symmetric.\n");
    }
    else
    {
        fprintf(outputFile, "The matrix is not symmetric.\n");
        printf("The matrix is not symmetric.\n");
    }

    fclose(outputFile);

    return 0;
}
