#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 11

struct stack
{
    int data[size];
    int top;
};

int isfull(struct stack *sptr)
{
    if(sptr->top==(size-1))
        return 1;
    else
        return 0;
}

int isempty(struct stack *sptr)
{
    if(sptr->top==0)
        return 1;
    else
        return 0;
}

void push(struct stack *sptr,int element)
{
    sptr->top++;
    sptr->data[sptr->top]=element;
}

int pop(struct stack *sptr)
{
    int element=sptr->data[sptr->top];
    sptr->top--;
    return element;
}

void display(struct stack *sptr)
{
    if(sptr->top==0)
        printf("STACK EMPTY\n");
    else
    {
        for(int i=sptr->top; i!=0; i--)
        {
            printf("%d ",sptr->data[i]);
        }
    }
}

int main()
{
    struct stack s,*sptr=&s;
    sptr->top=0;
    int ch,element,num[size];

    FILE *inputFile;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Failed to open the input file.\n");
        return 1;
    }
    for (int i = 0; i < size; i++)
            fscanf(inputFile,"%d",&num[i]);

    fclose(inputFile);
    int j=0;
    fclose(inputFile);
    while(1)
    {
        printf("\nSTACK MENU\n");
        printf("1.PUSH 2.POP 3.DISPLAY 4:EXIT\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(isfull(sptr))
            {
                printf("Stack overflow\n");
            }
            else
            {
                printf("PUSHED ELEMENT IS : %d",num[j]);
                push(sptr,num[j]);
                j++;
            }
            break;

            case 2:
            if(isempty(sptr))
            {
                printf("Stack underflow\n");
            }
            else
            {
                element=pop(sptr);
                printf("POPPED ELEMENT IS = %d\n",element);
            }
            break;

            case 3:display(sptr);
            break;

            case 4:exit(0);
            break;

            default:printf("INVALID CHOICE \n");
            break;
        }
    }
    return 0;
}
