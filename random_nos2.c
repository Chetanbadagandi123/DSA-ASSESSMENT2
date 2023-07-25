#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void random(int num[100],int lower,int upper,int count);
void sort(int num[],int count);
void timers(int num[],int count);
int main()
{
    int num[100];
    int lower , upper , count;
    printf("enter limits and counts");
    scanf("%d%d%d",&lower,&upper,&count);
    timers(num,count);
    return 0;
}
void random(int num[100],int lower,int upper,int count)
{   int i;
    printf("The random numbers are: ");
    for ( i = 0; i < count; i++) {
         num[i] = (rand() % (upper - lower + 1)) + lower;
        scanf("%d ", num[i]);
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
void timers(int num[100],int count)
{
    FILE*fp;
    int i;
    double a;
    time_t start, end;
    double tr;
    fp=fopen("log.txt","w");
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
