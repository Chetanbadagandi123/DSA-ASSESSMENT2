#include<stdio.h>

int main()
{
    FILE *fp,*fp2;
    int num;
    fp=fopen("input_file.txt","r");
    if (fp == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }
    fp2=fopen("input_file_2.txt","w");
    if (fp2 == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }
    fscanf(fp,"%d",&num);
    num=2*num;
    printf("%d",num);
    fprintf(fp2,"%d",num);
    fclose(fp);
    fclose(fp2);
    return 0;
}

/*#include <stdio.h>

int main()
{
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    int num;
    fscanf(input_file, "%d", &num);
    fclose(input_file);

    int doubled_num = num * 2;

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL)
    {
        printf("Error opening output file.\n");
        return 1;
    }
    printf("%d",doubled_num);
    fprintf(output_file, "%d", doubled_num);
    fclose(output_file);

    return 0;
}
*/
