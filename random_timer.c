#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void random(int num[100],int lower,int upper,int count)
{
    printf("The random numbers are: ");
    for (int i = 0; i < count; i++)
    {
        num[i] = (rand() % (upper - lower + 1)) + lower;
        printf("%d ",num[i]);
    }
}

void sort(int num[100],int count)
{ int i,j,temp;
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



}
void timers(int num[100],int lower,int upper,int count)
{
    FILE*fp;
    int i;
    double a;
    time_t start, end;
    double tr;
    fprintf(fp,"Total count x is %d\n",count);
    start = clock();
    sort(num,count);
    end = clock();
    tr=end -start;
    printf("Start time is %ld",start);
    fprintf(fp,"Start time is %ld\n",start);
    printf("End time is %ld\n",end);
    fprintf(fp,"End time is %ld\n",end);
    printf("Time required is%lf\n",tr);
    fprintf(fp,"Time required is%lf\n",tr);
    fclose(fp);
}

int main()
{
    int num[100];
    int lower , upper , count;
    printf("enter lower upper count\n");
    scanf("%d%d%d",&lower,&upper,&count);
    timers(num,lower,upper,count);
    return 0;
}
