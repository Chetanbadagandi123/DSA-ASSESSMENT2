#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(int num[100],int upper,int lower,int count);

int main()
{
    int num[100];
    int lower , upper , count;
    printf("enter limits and counts");
    scanf("%d%d%d",&lower,&upper,&count);
    random(num,upper,lower,count);
    return 0;
}

void random(int num[100],int upper,int lower,int count)
{
    int i,j,temp;;
    FILE *fp1,*fp2;
    fp1=fopen("input.txt","w");
    fp2=fopen("output.txt","w");

    fprintf(fp1,"The random numbers are: ");
    printf("The random numbers are: ");
    for ( i = 0; i < count; i++) {
         num[i] = (rand() % (upper - lower + 1)) + lower;
        fprintf(fp1,"%d ",num[i]);
        printf("%d ", num[i]);

    }
     for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    fprintf(fp2,"sort is\n");
    printf("sort is");

    for(i=0;i<count;i++)
    {
        fprintf(fp2,"%d ",num[i]);
        printf("%d ",num[i]);
    }

    fclose(fp1);
    fclose(fp2);
}
