#include<stdio.h>
int r,c;

void readstring(char str[r][c],int n);
void longest_line(char str[r][c],int n);

int main()
{
    char str[10][40];
    int n;
    printf("Enter the size of rows and coloumns respectively:\n");
    scanf("%d\n%d",&r,&n);
    printf("\nEnter the no of lines to be print\n");
    scanf("%d",&n);
    readstring(str,n);
    longest_line(str,n);
    return 0;
}

void readstring(char str[r][c],int n)
{
    int i;
    printf("\nEnter the string line by line\n");
    for(i=0;i<=n;i++)
    {
        gets(str[i]);
    }
}

void longest_line(char str[r][c],int n)
{
    int i,j,k,count=0,max=0;
    char longest[100];

	for(i=0; i<=n ;i++)
    {
		j=0;
		count=0;
		while(str[i][j]!='\0')
        {
            count++;
            j++;
        }

        if(max<count)
        {
            max=count;
            for(k=0;k<=max;k++)
            {
                longest[k]=str[i][k];
            }
        }
	}

	printf("\nLongest line has %d characters and line is :\n%s\n", max , longest );
}

