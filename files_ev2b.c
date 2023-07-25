#include<stdio.h>

void read(char asentence[][100],int n);
void display(char bsentence[][100],int n);
int check(char bsentence[],char key[]);

void main()
{
    int n;
    char sentence[100][100];
    printf("Enter the number of lines\n");
    scanf("%d",&n);
    read(sentence,n);
}

void read(char asentence[][100],int n)
{
    FILE *fp1,*fp2;
    fp1=fopen("searchin.txt","r");
    fp2=fopen("searchop.txt","w");
    int tp;
    char key[10];
    printf("Enter the key word that you want to search for\n");
    scanf("%s",key);
    while(!feof(fp1))
    {
         for(int i=0;i<n;i++)
    {
        fgets(asentence[i],100,fp1);
         tp=check(asentence[i],key);
        if(tp==1)
        {
             fputs(asentence[i],fp2);
             puts(asentence[i]);
        }
    }

    }
}

int check(char bsentence[],char key[])
{
    int a[10],i=0,j=1,tp=0;
    while(bsentence[i]!='\0')
    {
        tp=0;
        if(bsentence[i]==key[0])
        {
            while(key[j]!='\0')
            {
                if(bsentence[i+j]!=key[j])
                   {
                       break;
                   }
                   j++;
            }
            if(key[j]=='\0')
            {
                tp=1;
                break;
            }
            else
            {
                j=0;
            }
        }
        i++;
    }
    return tp;
}
