#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int string_search(char *text,char *pattern)
{
    int i,j,text_len,pattern_len;
    text_len=strlen(text);
    pattern_len=strlen(pattern);


    for(i=0;i<=text_len-pattern_len;i++)
    {
        j=0;
        while(j<pattern_len &&text[i+j]==pattern[j])
            j++;
        if(j==pattern_len)
        return i;
    }
    return -1;
}
int main()
{
    char text[100],pattern[100];
    int index;
    printf("enter text\n");
    gets(text);
    printf("enter pattern\n");
    gets(pattern);
    index=string_search(text,pattern);
    if(index!=-1)
    {
        printf("pattern found at %d index\n",index);
    }
    else
        printf("pattern not found\n");
    return 0;
}
