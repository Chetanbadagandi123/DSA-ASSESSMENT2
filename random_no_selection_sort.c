#include<stdio.h>
#include<stdlib.h>

void selection(int n,int a[n])
{
    int ex,temp;
    for(int i=0;i<n-1;i++)
    {
        ex=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[ex])
            {
               ex=j;
            }
        }
        temp=a[ex];
        a[ex]=a[i];
        a[i]=temp;
    }
}
int main()
{
        int i,n;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
       {
           a[i]=(int) (rand()%20);
       }
       for(i=0;i<n;i++)
       {
          printf("%d ",a[i]);
       }
       printf("\n");
       selection(n,a);
        for(i=0;i<n;i++)
       {
          printf("%d ",a[i]);
       }
        return 0;
}
