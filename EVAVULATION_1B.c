#include<stdio.h>
#include<stdlib.h>

int string_length(char str[]);

int main()
{
    FILE *file1,*file2;
    int k=0,l=0,i=0,m,q;
    char str[10][100],temp[100];
    file1=fopen("lines.txt","r");
    file2=fopen("longline.txt","w");
    if(file1==NULL)
    {
        printf("File does not exist.\n");
        exit(0);
    }
    while(!feof(file1))
    {
       fgets(str[i],1000,file1);
       k=string_length(str[i]);
       if(l<k)
       {
           l=k;
           m=0;
           q=0;
           while(str[i][q]!='\0')
           {
               temp[m]=str[i][q];
               q++;
               m++;
           }
           temp[m]='\0';
       }
       fputs(str[i],file2);
       puts(str[i]);
    }
    printf("\nThe longest line read is\n");
    puts(temp);
    fputs("\nThe longest line read is\n",file2);
    fputs(temp,file2);
    fclose(file1);
    fclose(file2);
    return 0;
}

int string_length(char str[])
{
    int k=0;
    while(str[k]!='\0')
    {
        k++;
    }
    return k;
}
