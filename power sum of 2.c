#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,sum=0;
    printf("enter the 2 the power:");
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        sum=sum+pow(2,i);
    }
    printf("%d",sum);
    return 0;
}
