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
