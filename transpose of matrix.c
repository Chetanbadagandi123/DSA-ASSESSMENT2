#include <stdio.h>
#define MAX_SIZE 10

void transpose(int matrix[][MAX_SIZE],int transposed[][MAX_SIZE],int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main()
{
    FILE *inputFile, *outputFile;
    int matrix[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int size, i, j;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Failed to open the input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &size);

    printf("Input matrix is\n");
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

    transpose(matrix, transposed, size);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Failed to open the output file.\n");
        return 1;
    }

    fprintf(outputFile, "%d\n", size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            fprintf(outputFile, "%d ", transposed[i][j]);
            printf("%d",transposed[i][j]);
        }
        fprintf(outputFile, "\n");
        printf("\n");
    }

    fclose(outputFile);

    return 0;
}
