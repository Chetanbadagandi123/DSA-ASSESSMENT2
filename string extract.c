#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void extract(char str[100],int s,int e)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(i>=(s-1)&&i<(s+e))
        {
            printf("%c",str[i]);
        }
        i++;
    }
}

void extract_all(char str[100],int s,int e)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(i>=(s-1))
        {
            printf("%c",str[i]);
        }
        i++;
    }
}

int main()
{
    char str[100];
    int s,e;
    scanf ("%[^\n]%*c",str);
    //gets(str);
    scanf("%d%d",&s,&e);
    if(e==0)
    {
        extract_all(str,s,e);
    }
    else
    {
        if(e<s)
        {
            printf("Cannot extract string.");
        }
        else
        {
            extract(str,s,e);
        }
    }
}
