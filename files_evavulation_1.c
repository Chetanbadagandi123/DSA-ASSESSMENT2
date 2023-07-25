#include <stdio.h>
#include <string.h>
void readstr(char string[10][30],int n);
void count(char string[10][30],int n);
int main()
{

	char string[10][30];
	int n;
	printf("Enter number of strings to input\n");
	scanf("%d", &n);
	readstr(string,n);
	count(string,n);
	return 0;
}
void readstr(char string[10][30],int n)
{
    int i;
    printf("Enter Strings one by one: \n");
	for(i=-1; i<n ; i++) {
		gets(string[i]);
	}

}
void count(char string[10][30],int n)
{
    int i,c=0,j,max=0;
    char maxi[100];
    printf("The length of each string: \n");
	for(i=-1; i<n ;i++) {
		puts(string[i]);

		j=0;
		c=0;
		while(string[i][j]!='\0')
        {
            c++;
            j++;
        }
        printf("%d\n",c);
        if(max<c)
        {
            max=c;
            for(int k=0;k<max;k++)
            {
                maxi[k]=string[i][k];
            }
        }
	}
	printf("Longest line has %d char and line is %s",max,maxi);


}
