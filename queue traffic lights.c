#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *link;
};
typedef struct node *NODE;

int count=0;

NODE enqueue(NODE tail,char colour)
{
    NODE newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=colour;
    newnode->link=newnode;
    if(tail==NULL)
        tail=newnode;
    else
    {
        newnode->link=tail->link;
        tail->link=newnode;
        tail=newnode;
    }
    return tail;
}

NODE dequeue(NODE tail)
{
    NODE cur;
    char ch;
    if(tail==NULL)
        printf("Queue underflow\n");
    else if(tail->link==tail)
    {
        ch=tail->data;
        if(ch=='R')
        {
            free(tail);
            tail=NULL;
            tail=enqueue(tail,'Y');
            count++;
        }
        else if(ch=='Y')
        {
            free(tail);
            tail=NULL;
            tail=enqueue(tail,'G');
            count++;
        }
        else if(ch=='G')
        {
            free(tail);
            tail=NULL;
            tail=enqueue(tail,'G');
        }
    }
    else
    {
        cur=tail->link;
        while(cur!=tail)
        {
            tail->link=cur->link;
        ch=cur->data;
        if(ch=='R')
        {
            free(cur);
            tail=enqueue(tail,'Y');
            count++;
        }
        else if(cur->data=='Y')
        {
            free(cur);
            tail=enqueue(tail,'G');
            count++;
        }
        else if(cur->data=='G')
        {
            free(cur);
            tail=enqueue(tail,'G');
        }
        cur=cur->link;
        }
    }
    return tail;
}

int main()
{
    NODE tail=NULL;
    int n;
    char colour;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%s",&colour);
        tail=enqueue(tail,colour);
    }

    for(int i=0;i<20;i++)
        tail=dequeue(tail);

    printf("%d",count);
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 100

struct queue
{
    char data[size];
    int front ,rear;
};
void enqueue(struct queue *qptr,int num)
{

    if(qptr->front && qptr->rear==-1)
    {
        qptr->front=qptr->rear=0;
        qptr->data[qptr->rear]=num;
    }
    else if((qptr->rear+1)%size==qptr->front)
    {
        printf("queue ovweflow\n");
    }
    else
    {
        qptr->rear=(qptr->rear+1)%size;
        qptr->data[qptr->rear]=num;
    }
}
char dequeue(struct queue *qptr)
{
    int num=-1;
    if(qptr->front==-1 && qptr->rear==-1)
    {
        return num;
    }
    else if(qptr->front==qptr->rear)
    {

        num=qptr->data[qptr->front];
         qptr->front=qptr->rear=-1;
    }
    else
    {
        num=qptr->data[qptr->front];
        qptr->front=(qptr->front+1)%size;

    }
    return num;
}
void signal(struct queue *qptr)
{
    int c=0;
    char ch;
    while(qptr->front!=qptr->rear)
    {
        ch=dequeue(qptr);
        if((ch)=='R')
        {
            enqueue(qptr,'Y');
            c++;
        }
        else if(ch=='Y')
        {
            enqueue(qptr,'G');
            c++;
        }
    }
    printf("%d",c);
    }

int main()
{
    struct queue q,*qptr;
    qptr=&q;
    qptr->front=-1;
    qptr->rear=-1;
    char c;
    int i,n;

    scanf("%d",&n);
    if(n>0 && n<100)
    {
        for(i=0;i<n;i++)
    {
        scanf(" %c ",&c);
        enqueue(qptr,c);
    }
    }

    signal(qptr);

    return 0;
}
*/


#include<stdio.h>
#include<stdlib.h>

struct queue
{
    char data;
    struct queue *link;
};
typedef struct stack *NODE;

NODE enqueue(NODE head,char ch)
{
    NODE cur,newnode;
    newnode=malloc(sizeof(struct queue));
    newnode->data=ch;
    newnode->link=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=newnode;
    }
    return head;
}

NODE dequeue_specific(NODE head)
{
    NODE cur;
    char ch;
    int count=0;
    if(head==NULL)
        printf("Queue underflow\n");
    else if(head->link==NULL)
    {
        ch=head->data;
        if(ch=='R')
        {
            free(head);
            head=NULL;
            head=enqueue(head,'Y');
            count++;
        }
        else if(ch=='Y')
        {
            free(head);
            head=NULL;
            head=enqueue(head,'G');
            count++;
        }
        else if(ch=='G')
        {
            free(head);
            head=NULL;
            head=enqueue(head,'G');
        }
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            ch=cur->data;
            if(ch=='R')
            {
                free(cur);

            }
        }
    }
}
