#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct stack
{
    char data[50];
    int top;
};

void push(struct stack *sptr,char element);
char pop(struct stack *sptr);
char peek(struct stack *sptr);
void postfix_conv(char infix[50]);
int precedence(char ch);

int main() {
    char infix[50];
    //printf("Enter the infix expression\n");
    scanf("%s",infix);
    postfix_conv(infix);
    return 0;
}

void push(struct stack *sptr,char element)
{
    if(sptr->top==50-1)
        printf("Stack overflow\n");
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=element;
    }
}

char pop(struct stack *sptr)
{
    char element;
    if(sptr->top==-1)
    {
        return -1;
    }
    else
    {
        element=sptr->data[sptr->top];
        sptr->top--;
        return element;
    }
}

char peek(struct stack *sptr)
{
    char element;
    if(sptr->top==-1)
        return -1;
    else
    {element=sptr->data[sptr->top];
     return element;}
}

int precedence(char ch)
{
    switch(ch)
    {
        case '#': return 0;
            break;
        case '(': return 1;
            break;
        case '+':
        case '-': return 2;
            break;
        case '*':
        case '/':
        case '%': return 3;
            break;
        case '^': return 4;
            break;
    }
}

void postfix_conv(char infix[50])
{
    struct stack s,*sptr;
    sptr=&s;
    sptr->top=-1;
    char postfix[50],ch,element;
    int i=0,k=0;
    push(sptr,'#');
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(ch=='(')
            push(sptr,ch);
        else if(isalnum(ch))
            postfix[k++]=ch;
        else if(ch==')')
        {
            while(sptr->data[sptr->top]!='(')
                postfix[k++]=pop(sptr);
            element=pop(sptr);   //remove '('
        }
        else
        {
            while(precedence(peek(sptr))>=precedence(ch))
                postfix[k++]=pop(sptr);
            push(sptr,ch);
        }
        i++;
    }
    while(sptr->data[sptr->top]!='#')
        postfix[k++]=pop(sptr);
    postfix[k]='\0';
    printf("Given Infix Expression: %s\nPostfix Expression: %s\n",infix,postfix);
}
